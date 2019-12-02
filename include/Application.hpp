//
// Created by Dan on 10/13/2019.
//

#ifndef DINOTRACKS_APPLICATION_HPP
#define DINOTRACKS_APPLICATION_HPP

#include <memory>

#include <ResourceManager.hpp>
#include <logic/Logic.hpp>
#include <views/HumanView.hpp>
#include <views/AIView.hpp>

namespace dt
{
  class Application
  {
  public:
      // Constructors
      Application();

      // Main Game Loop
      int loop();

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
