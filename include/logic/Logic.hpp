//
// Created by Dan on 10/13/2019.
//

#ifndef DINOTRACKS_LOGIC_HPP
#define DINOTRACKS_LOGIC_HPP

#include <vector>
#include <SoundManager.hpp>

#include "logic/Entity.hpp"
#include "MovementSystem.hpp"
#include "EnergySystem.hpp"
#include "HealthSystem.hpp"
#include "Map.hpp"
#include <SFML/Audio/Music.hpp>

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
    
    enum class Speed
    {
		  Slow,
		  Fast
	  };

    class Logic
    {
    public:
        // Constructors
        Logic(const std::string& playerDino, int level);

        // Game Loop
        void update(const sf::Time& delta);
        void doTurn();
        int getTurn() const;
        int getScore() const;

        // View-Logic Communication For Player
        void movePlayer(Direction dir, Speed spd);
        const sf::Vector2i& getPlayerPosition() const;
        const std::string& getPlayerVisual() const;
        int getPlayerEnergy() const;
        int getPlayerHealth() const;
        int getPlayerMaxHealth() const;

        // View-Logic Communication For Map
        const Map& getMap() const;

        // View-Logic Communication For Enemies
        std::vector<std::string> getEntityVisuals() const;
        void moveEnemy(int id, Direction dir);

        //View-Logic Communication for Enemies, Food, and Eggs
        std::vector<sf::Vector2i> getEntityPositions() const;

    private:
        std::vector<Entity> entities;
        std::vector<sf::Vector2i> occupiedSpaces;

        // State
        Map map;
        bool actionPerformed = false;
        int turnCount = 100;

        // Systems
        EnergySystem energy;
        HealthSystem health;
        MovementSystem movement = MovementSystem(entities, energy, map, health);

        // Entity Coordinates
        std::vector<sf::Vector2i> generateCoords(int numOfCoords);
    };
}


#endif //DINOTRACKS_LOGIC_HPP
