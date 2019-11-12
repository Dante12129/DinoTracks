//
// Created by dan9c on 10/16/2019.
//

#include "views/HumanView.hpp"

#include <iostream>

#include <SFML/Window/Event.hpp>

#include <Logic.hpp>

namespace dt
{
    HumanView::HumanView() : window({1366, 768}, "DinoTracks", sf::Style::Titlebar | sf::Style::Close),
    ui(window.getSize())
    {
      window.setKeyRepeatEnabled(false);

      // Create default key associations
      input.associate(sf::Keyboard::W, "MOVE_UP");
      input.associate(sf::Keyboard::S, "MOVE_DOWN");
      input.associate(sf::Keyboard::A, "MOVE_LEFT");
      input.associate(sf::Keyboard::D, "MOVE_RIGHT");
      input.associate(sf::Keyboard::Enter, "NOTHING");

      // Create player's visual representation
      player.setSize({32, 32});
      player.setFillColor(sf::Color::Red);
      player.setPosition({player.getSize().x * 20, player.getSize().y * 11});
    }

    void HumanView::processEvents()
    {
      try
      {
        sf::Event event;
        while (window.pollEvent(event))
        {
          switch (event.type)
          {
            case sf::Event::Closed:
              windowClosedCallback();
              break;
            case sf::Event::KeyPressed:
              input.activate(event.key.code);
              break;
            case sf::Event::KeyReleased:
              input.deactivate(event.key.code);
              break;
          }
        }
      }
      catch(std::exception& e)
      {
        std::cout << e.what() << std::endl;
      }
    }

    void HumanView::sendCommands(Logic& logic) const
    {
      if(input.isActiveOnce("MOVE_UP"))
      {
        std::cout << "MOVE_UP" << std::endl;
        logic.movePlayer(Direction::Up);
      }
      if(input.isActiveOnce("MOVE_DOWN"))
      {
        std::cout << "MOVE_DOWN" << std::endl;
        logic.movePlayer(Direction::Down);
      }
      if(input.isActiveOnce("MOVE_LEFT"))
      {
        std::cout << "MOVE_LEFT" << std::endl;
        logic.movePlayer(Direction::Left);
      }
      if(input.isActiveOnce("MOVE_RIGHT"))
      {
        std::cout << "MOVE_RIGHT" << std::endl;
        logic.movePlayer(Direction::Right);
      }
    }

    void HumanView::updateFrom(const Logic& logic)
    {
      // Update player's position on screen
      //player.setPosition({player.getSize().x * logic.getPlayerPosition().x, player.getSize().y * logic.getPlayerPosition().y});
        
      map = &logic.getMap();
      centerX = logic.getPlayerPosition().x * 32 + 11;
      centerY = logic.getPlayerPosition().y * 32;
	    ui.setTurn(logic);
    }

    void HumanView::draw()
    {
      window.clear();

      if(map && map->getSize() != 0)
        drawMap();
      ui.draw(window);

      window.draw(player);

      window.display();
    }

    void HumanView::setWindowClosedCallback(std::function<void()> callback)
    {
      windowClosedCallback = callback;
    }
    
    void HumanView::drawMap()
    {
      sf::Sprite grass;
      grass.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
      grass.setTextureRect(sf::IntRect(0, 0, 32, 32));

      sf::Sprite water;
      water.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
      water.setTextureRect(sf::IntRect(32, 0, 32, 32));

      sf::Sprite grassEdgeBottomLeft;
      grassEdgeBottomLeft.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
      grassEdgeBottomLeft.setTextureRect(sf::IntRect(64, 32, 32, 32));

      sf::Sprite grassEdgeBottomRight;
      grassEdgeBottomRight.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
      grassEdgeBottomRight.setTextureRect(sf::IntRect(64, 0, 32, 32));

      sf::Sprite grassEdgeTopLeft;
      grassEdgeTopLeft.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
      grassEdgeTopLeft.setTextureRect(sf::IntRect(0, 32, 32, 32));

      sf::Sprite grassEdgeTopRight;
      grassEdgeTopRight.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
      grassEdgeTopRight.setTextureRect(sf::IntRect(32, 32, 32, 32));

      sf::Sprite mountain;
      mountain.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
      mountain.setTextureRect(sf::IntRect(0, 64, 32, 32));

      mapView.setCenter(sf::Vector2f(centerX, centerY));
      mapView.setSize(sf::Vector2f(1366, 768));

      window.setView(mapView);

      int posX = 0;
      int posY = 0;
      map->getTile(0, 0);

      for (int r = 0; r < 66; ++r)
      {
        for (int c = 0; c < 96; ++c)
        {
          switch (map->getTile(c, r))
          {
            case 0:
              water.setPosition(sf::Vector2f(posX, posY));
              window.draw(water);
              break;
            case 1:
              grass.setPosition(sf::Vector2f(posX, posY));
              window.draw(grass);
              break;
            case 2:
              grassEdgeBottomLeft.setPosition(sf::Vector2f(posX, posY));
              window.draw(grassEdgeBottomLeft);
              break;
            case 3:
              grassEdgeBottomRight.setPosition(sf::Vector2f(posX, posY));
              window.draw(grassEdgeBottomRight);
              break;
            case 4:
              grassEdgeTopRight.setPosition(sf::Vector2f(posX, posY));
              window.draw(grassEdgeTopRight);
              break;
            case 5:
              grassEdgeTopLeft.setPosition(sf::Vector2f(posX, posY));
              window.draw(grassEdgeTopLeft);
              break;
            case 6:
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
}
