//
// Created by Dan on 10/13/2019.
//

#ifndef DINOTRACKS_APPLICATION_HPP
#define DINOTRACKS_APPLICATION_HPP

#include <logic/Logic.hpp>

class Application
{
public:
    // Setup
    Application();

    // Main Game Loop
    int loop();

private:
    // Status
    bool running = true;

    // Main Objects
    Logic gameLogic;
};


#endif //DINOTRACKS_APPLICATION_HPP
