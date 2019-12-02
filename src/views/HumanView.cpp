//
// Created by dan9c on 10/16/2019.
//

#include "views/HumanView.hpp"

//#include <iostream>

#include <SFML/Window/Event.hpp>
#include <Thor/Input/InputNames.hpp>

#include <EndMenu.hpp>
#include <Logic.hpp>
#include <StartMenu.hpp>
#include <Tags.hpp>

// TODO: Create globals for transitioning to End
// TODO: Create mechanism for starting and replaying
// TODO: Extract stuff from HumanView Constructor
// TODO: Update entities rather than just loading at start

namespace dt
{
    HumanView::HumanView(const Logic& initial) : window({1366, 768}, "DinoTracks", sf::Style::Titlebar | sf::Style::Close),
    ui(window.getSize())
    {
      window.setKeyRepeatEnabled(false);
      loadActionsFromFile();

      // Create player's visual representation
      const sf::Texture& playerTex = ResourceManager::currentManager->getTexture(initial.getPlayerVisual());
      player.setTexture(playerTex);
      player.setColor(sf::Color::Blue);
      player.setPosition({static_cast<float>(dinoWidth * 20), static_cast<float>(dinoHeight * 11)});
    }

    void HumanView::processEvents()
    {
      sf::Event event;
      input.updateAll(window);
    }

    void HumanView::sendCommands(Logic& logic) const
    {
      if(input.isActive(RUN_UP))
      {
//        std::cout << "MOVE_UP" << std::endl;
        logic.movePlayer(Direction::Up, Speed::Fast);
      }
      if(input.isActive(RUN_DOWN))
      {
//        std::cout << "MOVE_DOWN" << std::endl;
        logic.movePlayer(Direction::Down, Speed::Fast);
      }
      if(input.isActive(RUN_LEFT))
      {
//        std::cout << "MOVE_LEFT" << std::endl;
        logic.movePlayer(Direction::Left, Speed::Fast);
      }
      if(input.isActive(RUN_RIGHT))
      {
//        std::cout << "MOVE_RIGHT" << std::endl;
        logic.movePlayer(Direction::Right, Speed::Fast);
      }
      if(input.isActive(WALK_UP))
      {
//        std::cout << "WALK_UP" << std::endl;
        logic.movePlayer(Direction::Up, Speed::Slow);
      }
      if(input.isActive(WALK_DOWN))
      {
//        std::cout << "WALK_DOWN" << std::endl;
        logic.movePlayer(Direction::Down, Speed::Slow);
      }
      if(input.isActive(WALK_LEFT))
      {
//        std::cout << "WALK_LEFT" << std::endl;
        logic.movePlayer(Direction::Left, Speed::Slow);
      }
      if(input.isActive(WALK_RIGHT))
      {
//        std::cout << "WALK_RIGHT" << std::endl;
        logic.movePlayer(Direction::Right, Speed::Slow);
      }
    }

    void HumanView::updateFrom(const Logic& logic)
    {
      // Update player's position on screen
      //player.setPosition({player.getSize().x * logic.getPlayerPosition().x, player.getSize().y * logic.getPlayerPosition().y});
        
      map = &logic.getMap();
      centerX = (logic.getPlayerPosition().x + 1) * 32 + 11;
      centerY = (logic.getPlayerPosition().y + 1) * 32;

      // Update turn number
      ui.setTurn(logic);

      // Update score
      ui.setScore(logic);

      // Update Health and Energy Bar
      ui.setHealth(logic);
      ui.setEnergy(logic);

      // Update visual representation of enemies, food, and eggs
      auto entPositions = logic.getEntityPositions();
      auto enemyVis = logic.getEntityVisuals();

      entities.resize(33);
      int i = 0;
      for(sf::Sprite& sprite: entities)
      {
        const sf::Texture& dinoTexture = ResourceManager::currentManager->getTexture(enemyVis.at(i));
        sprite.setTexture(dinoTexture);
        sprite.setPosition({static_cast<float>(dinoWidth * entPositions.at(i).x), static_cast<float>(dinoHeight * entPositions.at(i).y)});
        ++i;
      }
    }

    void HumanView::draw()
    {
      window.clear();

      if (currentState == State::Playing)
      {
        if (map && map->getSize() != 0)
          drawMap();

        window.draw(player);
        window.setView(mapView);

        for (const sf::Sprite& sprite: entities)
        {
          window.draw(sprite);
        }

        window.setView(window.getDefaultView());

        ui.draw(window);
      }
      else if(currentState == State::Playing)
      {
        window.draw(StartMenu());
      }
      else if(currentState == State::End)
      {
        window.draw(EndMenu());
      }

      window.display();
    }

    void HumanView::setWindowClosedCallback(std::function<void()> callback)
    {
      input.setWindowCloseCallback(callback);
    }
    
    void HumanView::drawMap()
    {
      sf::Sprite grass;
      grass.setTexture(ResourceManager::currentManager->getTexture(TERRAIN));
      grass.setTextureRect(sf::IntRect(0, 0, 32, 32));

      sf::Sprite water;
      water.setTexture(ResourceManager::currentManager->getTexture(TERRAIN));
      water.setTextureRect(sf::IntRect(32, 0, 32, 32));

      sf::Sprite grassEdgeBottomLeft;
      grassEdgeBottomLeft.setTexture(ResourceManager::currentManager->getTexture(TERRAIN));
      grassEdgeBottomLeft.setTextureRect(sf::IntRect(64, 32, 32, 32));

      sf::Sprite grassEdgeBottomRight;
      grassEdgeBottomRight.setTexture(ResourceManager::currentManager->getTexture(TERRAIN));
      grassEdgeBottomRight.setTextureRect(sf::IntRect(64, 0, 32, 32));

      sf::Sprite grassEdgeTopLeft;
      grassEdgeTopLeft.setTexture(ResourceManager::currentManager->getTexture(TERRAIN));
      grassEdgeTopLeft.setTextureRect(sf::IntRect(0, 32, 32, 32));

      sf::Sprite grassEdgeTopRight;
      grassEdgeTopRight.setTexture(ResourceManager::currentManager->getTexture(TERRAIN));
      grassEdgeTopRight.setTextureRect(sf::IntRect(32, 32, 32, 32));

      sf::Sprite mountain;
      mountain.setTexture(ResourceManager::currentManager->getTexture(TERRAIN));
      mountain.setTextureRect(sf::IntRect(0, 64, 32, 32));

      mapView.setCenter(sf::Vector2f(centerX, centerY));
      mapView.setSize(sf::Vector2f(1366, 768));

      window.setView(mapView);

      int posX = 0;
      int posY = 0;

      for (int r = 0; r < 66; ++r)
      {
        for (int c = 0; c < 96; ++c)
        {
          switch (map->getTile(c, r))
          {
            case WATER:
              water.setPosition(sf::Vector2f(posX, posY));
              window.draw(water);
              break;
            case GRASS:
              grass.setPosition(sf::Vector2f(posX, posY));
              window.draw(grass);
              break;
            case GRASS_BOTTOM_LEFT:
              grassEdgeBottomLeft.setPosition(sf::Vector2f(posX, posY));
              window.draw(grassEdgeBottomLeft);
              break;
            case GRASS_BOTTOM_RIGHT:
              grassEdgeBottomRight.setPosition(sf::Vector2f(posX, posY));
              window.draw(grassEdgeBottomRight);
              break;
            case GRASS_TOP_RIGHT:
              grassEdgeTopRight.setPosition(sf::Vector2f(posX, posY));
              window.draw(grassEdgeTopRight);
              break;
            case GRASS_TOP_LEFT:
              grassEdgeTopLeft.setPosition(sf::Vector2f(posX, posY));
              window.draw(grassEdgeTopLeft);
              break;
            case MOUNTAIN:
              mountain.setPosition(sf::Vector2f(posX, posY));
              window.draw(mountain);
          }

          posX += 32;
        }

        posX = 0;
        posY += 32;
      }

      window.setView(window.getDefaultView());
	  }

    void HumanView::loadActionsFromFile()
    {
      // Get keys from file
      std::ifstream keyFile;
      std::string filePath = "../resources/keys/KeyConfig.txt";
      keyFile.open(filePath);

      std::string keyUp;
      std::string keyDown;
      std::string keyLeft;
      std::string keyRight;
      std::string keySlow;

      keyFile >> keyUp >> keyUp >> keyDown >> keyDown >> keyLeft >> keyLeft >> keyRight >> keyRight >> keySlow >> keySlow;

      keyFile.close();

      // Create default key associations
      thor::Action up (thor::toKeyboardKey(keyUp), thor::Action::ReleaseOnce);
      thor::Action down (thor::toKeyboardKey(keyDown), thor::Action::ReleaseOnce);
      thor::Action left (thor::toKeyboardKey(keyLeft), thor::Action::ReleaseOnce);
      thor::Action right (thor::toKeyboardKey(keyRight), thor::Action::ReleaseOnce);
      thor::Action slow (thor::toKeyboardKey(keySlow), thor::Action::Hold);

      input.associate(up, RUN_UP);
      input.associate(down, RUN_DOWN);
      input.associate(left, RUN_LEFT);
      input.associate(right, RUN_RIGHT);
      input.associate(slow && up, WALK_UP);
      input.associate(slow && down, WALK_DOWN);
      input.associate(slow && left, WALK_LEFT);
      input.associate(slow && right, WALK_RIGHT);
    }
}
