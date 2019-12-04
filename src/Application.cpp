//
// Created by Dan on 10/13/2019.
//

#include "Application.hpp"
#include "Tags.hpp"

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

namespace dt
{
    Application* Application::currentApplication = nullptr;

    Application::Application()
    {
      // Set the global ResourceManager
      ResourceManager::currentManager = &resources;

      // Load global resources here
      // E.g. resources.load(ResourceManager::Type::Texture, "TREX_TEX", "trex.png")
      // Resource must be in the textures, fonts, or sounds subdirectories of the resources directory
      resources.load(ResourceManager::Type::Texture, TERRAIN, "terrain.png");
      resources.load(ResourceManager::Type::Texture, TYRANNOSAURUS, "Tyrannosaurus.png");
      resources.load(ResourceManager::Type::Texture, STEGOSAURUS, "stegosaurus.png");
      resources.load(ResourceManager::Type::Texture, EGG, "egg.png");
      resources.load(ResourceManager::Type::Texture, MEAT, "meat.png");
      resources.load(ResourceManager::Type::Texture, TREE, "tree.png");
      resources.load(ResourceManager::Type::Texture, ESCAPE_TEX, "escape_pod.png");
      resources.load(ResourceManager::Type::DinosaurType, STEGOSAURUS, "Stegosaurus.txt");
      resources.load(ResourceManager::Type::DinosaurType, TYRANNOSAURUS, "Tyrannosaurus.txt");
      resources.load(ResourceManager::Type::Font, METEOR_FONT, "Azonix.otf");

      // Create the Views
      playerView.reset(new HumanView());
      playerView->setState(HumanView::State::Start, nullptr);

      // Create the Logic
//      startGame(TYRANNOSAURUS);

      // Let the HumanView Quit The App
      playerView->setWindowClosedCallback([&] {
          running = false;
      });

      // Set the global application
      currentApplication = this;
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
        playerView->processEvents();
        if(gameLogic) playerView->sendCommands(*gameLogic);

        // Update the logical and visual state
        if(gameLogic) gameLogic->update(frameDelta);
        if(gameLogic) playerView->updateFrom(*gameLogic);

        // Actual rendering of visual state
        playerView->draw();
      }

      return 0;
    }

    void Application::showStart()
    {
      // Delete logic
      if(gameLogic) gameLogic.release();

      // Change HumanView state
      playerView->setState(HumanView::State::Start, nullptr);
    }

    void Application::startGame(const std::string& playerDino)
    {
      // Create Logic
      gameLogic.reset(new Logic(playerDino));

      // Change HumanView state
      playerView->setState(HumanView::State::Playing, gameLogic.get());
    }

    void Application::endGame()
    {
      // Change HumanView state
      playerView->setState(HumanView::State::End, gameLogic.get());
    }
}
