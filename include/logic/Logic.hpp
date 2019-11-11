//
// Created by Dan on 10/13/2019.
//

#ifndef DINOTRACKS_LOGIC_HPP
#define DINOTRACKS_LOGIC_HPP

#include <vector>
#include <Map.hpp>

#include "logic/Entity.hpp"
#include "MovementSystem.hpp"

// Forward Declarations
namespace sf { class Time; }

namespace dt
{
    enum class Direction
    {
        Up,
        Down,
        Left,
        Right,
        None
    };

    class Logic
    {
    public:
        // Constructors
        Logic();

        // Game Loop
        void update(const sf::Time& delta);
        void doTurn();
        int getTurn(const Logic& logic) const;

        // View-Logic Communication
        void movePlayer(Direction dir);
        const sf::Vector2i& getPlayerPosition() const;
        const std::string getPlayerVisual() const;

    private:
        std::vector<Entity> entities;
        std::vector<sf::Vector2i> occupiedSpaces;

        // Systems
        MovementSystem movement;

        // State
        bool actionPerformed = false;

        // Turns
        int turnCount = 10;

        // Entity Coordinates
        std::vector<sf::Vector2i> generateCoords(const Map& map, int numOfCoords);

    };
}


#endif //DINOTRACKS_LOGIC_HPP
