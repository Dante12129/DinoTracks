//
// Created by Dan on 10/13/2019.
//

#ifndef DINOTRACKS_APPLICATION_HPP
#define DINOTRACKS_APPLICATION_HPP

#include <memory>

#include <ResourceManager.hpp>
#include <EndMenu.hpp>
#include <logic/Logic.hpp>
#include <views/HumanView.hpp>
#include <views/AIView.hpp>

namespace dt
{
  class Application
  {
  public:
      // Global Application (will be initialized in constructor)
      static Application* currentApplication;

      // Constructors
      Application();

      // Main Game Loop
      int loop();

      // States
      void showStart();
      void startGame(const std::string& playerDino, int level);
      void endGame(EndMenu::Reason reason);

  private:
      // Status
      bool running = true;

      // Main Objects
      std::unique_ptr<Logic> gameLogic;
      std::unique_ptr<HumanView> playerView;
      std::unique_ptr<AIView> aiView;

      // Managers
      ResourceManager resources;
  };
}


#endif //DINOTRACKS_APPLICATION_HPP
