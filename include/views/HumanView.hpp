//
// Created by dan9c on 10/16/2019.
//

#ifndef DINOTRACKS_HUMANVIEW_HPP
#define DINOTRACKS_HUMANVIEW_HPP

#include <functional>

#include <SFML/Graphics/RenderWindow.hpp>

#include <InputManager.hpp>
#include <UserInterface.hpp>
#include <Map.hpp>

namespace dt
{
    // Forward Delcarations
    class Logic;

    class HumanView
    {
    public:
        // Constructors
        HumanView();

        // Game Loop
        void processEvents();
        void sendCommands(Logic& logic) const;
        void updateFrom(const Logic& logic);
        void draw();

        // Signals
        void setWindowClosedCallback(std::function<void()> callback);

    private:
        // Window-Related
        sf::RenderWindow window;
        std::function<void()> windowClosedCallback;
        UserInterface ui;
        Map map;

        // Input-Related
        InputManager input;
    };
}


#endif //DINOTRACKS_HUMANVIEW_HPP
