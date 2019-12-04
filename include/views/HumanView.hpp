//
// Created by dan9c on 10/16/2019.
//

#ifndef DINOTRACKS_HUMANVIEW_HPP
#define DINOTRACKS_HUMANVIEW_HPP

#include <functional>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <InputManager.hpp>
#include <UserInterface.hpp>
#include <Map.hpp>
#include <Menu.hpp>
#include <UserInterface.hpp>
#include "EndMenu.hpp"
#include <SoundManager.hpp>
#include <queue>

namespace dt
{
    // Forward Declarations
    class Application;
    class Logic;

    class HumanView
    {
    public:
        // Enums
        enum class State {
            Start,
            Playing,
            End,
            None
        };

        // Constructors
        HumanView();

        // Game Loop
        void processEvents();
        void sendCommands(Logic& logic) const;
        void updateFrom(const Logic& logic);
        void draw();
        void drawMap();

        // Signals
        void setWindowClosedCallback(std::function<void()> callback);

        // State
        void setState(const State& state, const Logic* logic = nullptr, EndMenu::Reason reason = EndMenu::Reason::None);

    private:
        // Methods
        void loadActionsFromFile();
        void goToStart();
        void createFrom(const Logic& logic);
        void goToEnd(const Logic& logic, EndMenu::Reason reason);

        // Window-Related
        sf::RenderWindow window;

        // State-Related
        State currentState = State::None;
        std::unique_ptr<Menu> menu;

        // Drawn objects
        UserInterface ui;
        sf::Sprite player;

        std::vector<sf::Sprite> entities; // escape pod, enemies, food, and eggs
        
        // Map related
        const int dinoWidth = 32;
        const int dinoHeight = 32;
        const Map* map = nullptr;
        int centerX;
        int centerY;
        sf::View mapView;

        // Input-Related
        InputManager input;

        sf::Sound playSound;
        sf::SoundBuffer soundBuffer;
    };
}


#endif //DINOTRACKS_HUMANVIEW_HPP
