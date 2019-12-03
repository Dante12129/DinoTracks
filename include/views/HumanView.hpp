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
#include <SoundManager.hpp>
#include <queue>

namespace dt
{
    // Forward Delcarations
    class Logic;

    class HumanView
    {
    public:
        // Constructors
        HumanView(const Logic& initial);

        // Game Loop
        void processEvents();
        void sendCommands(Logic& logic) const;
        void updateFrom(const Logic& logic);
        void draw();
        void drawMap();
        void playSounds();

        // Signals
        void setWindowClosedCallback(std::function<void()> callback);

    private:
        // Window-Related
        sf::RenderWindow window;

        // Drawn objects
        UserInterface ui;
        sf::Sprite player;

        std::vector<sf::Sprite> entities; // enemies, food, and eggs
        
        //Map related
        const Map* map = nullptr;
        int centerX;
        int centerY;
        sf::View mapView;

        // Input-Related
        InputManager input;

        SoundManager sounds;
    };
}


#endif //DINOTRACKS_HUMANVIEW_HPP
