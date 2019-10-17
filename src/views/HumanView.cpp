//
// Created by dan9c on 10/16/2019.
//

#include "views/HumanView.hpp"

#include <SFML/Window/Event.hpp>

namespace dt
{
    HumanView::HumanView() : window({1366, 768}, "DinoTracks", sf::Style::Titlebar | sf::Style::Close)
    {}

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
        }
      }
    }

    void HumanView::sendCommands(Logic& logic) const
    {

    }

    void HumanView::updateFrom(const Logic& logic)
    {

    }

    void HumanView::draw()
    {
      window.clear();

      // Draw stuff here

      window.display();
    }

    void HumanView::setWindowClosedCallback(std::function<void()> callback)
    {
      windowClosedCallback = callback;
    }
}