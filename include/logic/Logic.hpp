//
// Created by Dan on 10/13/2019.
//

#ifndef DINOTRACKS_LOGIC_HPP
#define DINOTRACKS_LOGIC_HPP

#include <vector>

#include "logic/Entity.hpp"
#include "MovementSystem.hpp"
#include "EnergySystem.hpp"
#include "HealthSystem.hpp"

// Forward Declarations
namespace sf { class Time; }

namespace dt
{
    class Map;

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
        int getTurn() const;

        // View-Logic Communication
        void movePlayer(Direction dir);
        const sf::Vector2i& getPlayerPosition() const;
        const std::string getPlayerVisual() const;
        int getPlayerEnergy();
        int getPlayerHealth();

    private:
        std::vector<Entity> entities;
        std::vector<sf::Vector2i> occupiedSpaces;

        // Systems
        MovementSystem movement;
        EnergySystem energy;
        HealthSystem health;

        // State
        bool actionPerformed = false;

        // Turns
        int turnCount = 10;

        // Entity Coordinates
        std::vector<sf::Vector2i> generateCoords(const Map& map, int numOfCoords);

    };
}


#endif //DINOTRACKS_LOGIC_HPP
