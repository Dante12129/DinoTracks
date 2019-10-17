//
// Created by Dan on 10/13/2019.
//

#include "Application.hpp"

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

namespace dt
{
    Application::Application()
    {
      playerView.setWindowClosedCallback([&] {
          running = false;
      });
    }

    int Application::loop()
    {
      // To keep track of frame time
      sf::Clock frameClock;
      sf::Time frameDelta;

      while(running)
      {
        // Get frame time and start keeping next frame time
        frameDelta = frameClock.restart();

        // Process inputs and send them to logic
        playerView.processEvents();
        playerView.sendCommands(gameLogic);

        // Update the logical and visual state
        gameLogic.update(frameDelta);
        playerView.updateFrom(gameLogic);

        // Actual rendering of visual state
        playerView.draw();
      }

      return 0;
    }
}
