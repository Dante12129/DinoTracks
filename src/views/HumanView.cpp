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

      // Load the default map
      map.loadMapFromFile(1);

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

		  map.updateFrom(logic);
    }

    void HumanView::draw()
    {
      window.clear();
      
      map.draw(window);
      ui.draw(window);

      window.draw(player);

      window.display();
    }

    void HumanView::setWindowClosedCallback(std::function<void()> callback)
    {
      windowClosedCallback = callback;
    }
}
