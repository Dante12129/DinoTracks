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
      // Let the HumanView Quit The App
      playerView.setWindowClosedCallback([&] {
          running = false;
      });

      // Set the global ResourceManager
      ResourceManager::currentManager = &resources;

      // Load global resources here
      // E.g. resources.load(ResourceManager::Type::Texture, "TREX_TEX", "trex.png")
      // Resource must be in the texures, fonts, or sounds subdirectories of the resources directory
      resources.load(ResourceManager::Type::Texture, "TERRAIN", "terrain.png");
      resources.load(ResourceManager::Type::Font, "METEORCOUNT_FONT", "Azonix.otf");
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
