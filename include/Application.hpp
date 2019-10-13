//
// Created by Dan on 10/13/2019.
//

#ifndef DINOTRACKS_APPLICATION_HPP
#define DINOTRACKS_APPLICATION_HPP

class Application
{
public:
    // Setup
    Application();

    // Main Game Loop
    int loop();

private:
    bool running = true;
};


#endif //DINOTRACKS_APPLICATION_HPP
