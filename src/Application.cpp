//
// Created by Dan on 10/13/2019.
//

#include "Application.hpp"

namespace dt
{
  int Application::loop()
  {
    while(running)
    {
      playerView.processEvents();

      running = false; // TODO: implement EventManager so application can be closed.
    }

    return 0;
  }
}
