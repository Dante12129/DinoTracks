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

namespace dt
{
    // Forward Declarations
    class Logic;

    class HumanView
    {
    public:
        // Enums
        enum class State {
            Start,
            Playing,
            End
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
        void setState(const State& state, const Logic* logic = nullptr);

    private:
        // Methods
        void loadActionsFromFile();
        void createFrom(const Logic& logic);

        // Window-Related
        sf::RenderWindow window;

        // State-Related
        State currentState = State::Playing;

        // Drawn objects
        UserInterface ui;
        sf::Sprite player;
        std::vector<sf::Sprite> enemies;
        std::vector<sf::Sprite> eggs;

        std::vector<sf::Sprite> entities; // enemies, food, and eggs
        
        // Map related
        const int dinoWidth = 32;
        const int dinoHeight = 32;
        const Map* map = nullptr;
        int centerX;
        int centerY;
        sf::View mapView;

        // Input-Related
        InputManager input;
    };
}


#endif //DINOTRACKS_HUMANVIEW_HPP
