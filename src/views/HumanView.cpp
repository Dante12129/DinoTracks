//
// Created by dan9c on 10/16/2019.
//

#include "views/HumanView.hpp"

#include <iostream>

#include <SFML/Window/Event.hpp>

namespace dt
{
    HumanView::HumanView() : window({1366, 768}, "DinoTracks", sf::Style::Titlebar | sf::Style::Close)
    {
      window.setKeyRepeatEnabled(false);

      // Create default key associations
      input.associate(sf::Keyboard::W, "MOVE_UP");
      input.associate(sf::Keyboard::S, "MOVE_DOWN");
      input.associate(sf::Keyboard::A, "MOVE_LEFT");
      input.associate(sf::Keyboard::D, "MOVE_RIGHT");
      input.associate(sf::Keyboard::Enter, "NOTHING");
      
      UserInterface ui(window.getSize());
      this->ui = ui;
      
      loader.loadMapFromFile(1);
    }

    void HumanView::processEvents()
    {
      sf::Event event;
      while(window.pollEvent(event))
      {
        switch(event.type)
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

    void HumanView::sendCommands(Logic& logic) const
    {
      if(input.isActiveOnce("MOVE_UP"))
      {
        std::cout << "MOVE_UP" << std::endl;
      }
      if(input.isActiveOnce("MOVE_DOWN"))
      {
        std::cout << "MOVE_DOWN" << std::endl;
      }
      if(input.isActiveOnce("MOVE_LEFT"))
      {
        std::cout << "MOVE_LEFT" << std::endl;
      }
      if(input.isActiveOnce("MOVE_RIGHT"))
      {
        std::cout << "MOVE_RIGHT" << std::endl;
      }
    }

    void HumanView::updateFrom(const Logic& logic)
    {
    }

    void HumanView::draw()
    {
      window.clear();

      ui.draw(window);

      window.display();
    }

    void HumanView::setWindowClosedCallback(std::function<void()> callback)
    {
      windowClosedCallback = callback;
    }
}
