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
#include "Map.hpp"

// Forward Declarations
namespace sf { class Time; }

namespace dt
{
    //class Map;

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

        // View-Logic Communication For Player
        void movePlayer(Direction dir);
        const sf::Vector2i& getPlayerPosition() const;
        const std::string& getPlayerVisual() const;
        int getPlayerEnergy() const;
        int getPlayerHealth() const;

        // View-Logic Communication For Map
        const Map& getMap() const;

        // View-Logic Communication For Enemies
        std::vector<sf::Vector2i> getEnemyPositions() const;
        std::vector<std::string> getEnemyVisuals() const;

    private:
        std::vector<Entity> entities;
        std::vector<sf::Vector2i> occupiedSpaces;

        // Systems

        EnergySystem energy;
        HealthSystem health;
        MovementSystem movement = MovementSystem(energy);
        // State
        Map map;
        bool actionPerformed = false;
        int turnCount = 10;

        // Entity Coordinates
        std::vector<sf::Vector2i> generateCoords(int numOfCoords);
    };
}


#endif //DINOTRACKS_LOGIC_HPP
