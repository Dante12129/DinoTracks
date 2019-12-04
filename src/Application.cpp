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

      // Set the global SoundManager
      SoundManager::curSoundManager = &sounds;

      // Set the global Application
      currentApplication = this;

      // Load global resources here
      // E.g. resources.load(ResourceManager::Type::Texture, "TREX_TEX", "trex.png")
      // Resource must be in the textures, fonts, or sounds subdirectories of the resources directory
      resources.load(ResourceManager::Type::Texture, TERRAIN, "terrain.png");
      resources.load(ResourceManager::Type::Texture, TYRANNOSAURUS, "tyrannosaurus.png");
      resources.load(ResourceManager::Type::Texture, STEGOSAURUS, "stegosaurus.png");
      resources.load(ResourceManager::Type::Texture, VELOCIRAPTOR, "velociraptor.png");
      resources.load(ResourceManager::Type::Texture, SPINOSAURUS, "spinosaurus.png");
      resources.load(ResourceManager::Type::Texture, ALLOSAURUS, "allosaurus.png");
      resources.load(ResourceManager::Type::Texture, PACHYCEPHALOSAURUS, "pachycephalosaurus.png");
      resources.load(ResourceManager::Type::Texture, PROTOCERATOPS, "protoceratops.png");
      resources.load(ResourceManager::Type::Texture, PARASAUROLOPHUS, "parasaurolophus.png");
      resources.load(ResourceManager::Type::Texture, EGG, "egg.png");
      resources.load(ResourceManager::Type::Texture, MEAT, "meat.png");
      resources.load(ResourceManager::Type::Texture, FRUIT, "fruit.png");
      resources.load(ResourceManager::Type::Texture, ESCAPE_TEX, "escape_pod.png");
      resources.load(ResourceManager::Type::DinosaurType, STEGOSAURUS, "stegosaurus.txt");
      resources.load(ResourceManager::Type::DinosaurType, TYRANNOSAURUS, "tyrannosaurus.txt");
      resources.load(ResourceManager::Type::DinosaurType, VELOCIRAPTOR, "velociraptor.txt");
      resources.load(ResourceManager::Type::DinosaurType, SPINOSAURUS, "spinosaurus.txt");
      resources.load(ResourceManager::Type::DinosaurType, ALLOSAURUS, "allosaurus.txt");
      resources.load(ResourceManager::Type::DinosaurType, PACHYCEPHALOSAURUS, "pachycephalosaurus.txt");
      resources.load(ResourceManager::Type::DinosaurType, PROTOCERATOPS, "protoceratops.txt");
      resources.load(ResourceManager::Type::DinosaurType, PARASAUROLOPHUS, "parasaurolophus.txt");
      resources.load(ResourceManager::Type::Font, MAIN_FONT, "Azonix.otf");
      resources.load(ResourceManager::Type::SoundBuffer, SOUND_WIN, "win_sound.wav");
      resources.load(ResourceManager::Type::SoundBuffer, SOUND_LOSE, "lose_sound.wav");
      resources.load(ResourceManager::Type::SoundBuffer, SOUND_EAT_HERB, "herb_eat.wav");
      resources.load(ResourceManager::Type::SoundBuffer, SOUND_EAT_CARN, "carn_eat.wav");
      resources.load(ResourceManager::Type::SoundBuffer, SOUND_COMBAT, "combat_sound.wav");
      resources.load(ResourceManager::Type::SoundBuffer, SOUND_TER_COLLISION, "terrain_collision.wav");
      resources.load(ResourceManager::Type::Texture, BACKGROUND_START, "startmenu.jpg");
      resources.load(ResourceManager::Type::Texture, BACKGROUND_END, "endmenu.png");

      // Create the Views
      playerView.reset(new HumanView());
      aiView.reset(new AIView);

      // Let the HumanView Quit The App
      playerView->setWindowClosedCallback([&] {
          running = false;
      });

      // Start the game
      showStart();
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

        // Check enemy positions and send commands to logic
        if(gameLogic) aiView->sendCommands(*gameLogic);

        // Update the logical and visual state
        if(gameLogic) gameLogic->update(frameDelta);
        if(gameLogic) playerView->updateFrom(*gameLogic);
        if(gameLogic) aiView->updateFrom(*gameLogic);

        // Actual rendering of visual state
        playerView->draw();
      }

      return 0;
    }

    void Application::showStart()
    {
      // Delete logic
      if(gameLogic) gameLogic.release();

      // Play music
      sounds.playMusic(MUSIC_MENU);

      // Change HumanView state
      playerView->setState(HumanView::State::Start, nullptr);
    }

    void Application::startGame(const std::string& playerDino, int level)
    {
      // Create Logic
      gameLogic.reset(new Logic(playerDino, level));

      // Play music
      sounds.playMusic(MUSIC_GAMEPLAY);

      // Change HumanView state
      playerView->setState(HumanView::State::Playing, gameLogic.get());
    }

    void Application::endGame(EndMenu::Reason reason)
    {
      // Play music
      if (reason == EndMenu::Reason::Energy || reason == EndMenu::Reason::Health || reason == EndMenu::Reason::Meteor)
        sounds.playMusic(MUSIC_LOSE);
      else if (reason == EndMenu::Reason::Pod)
        sounds.playMusic(MUSIC_WIN);
      else
        sounds.getMusic().stop();

      // Change HumanView state
      playerView->setState(HumanView::State::End, gameLogic.get(), reason);
    }
}
