//
// Created by Dan on 10/13/2019.
//

#include <SFML/System/Time.hpp>

#include <Logic.hpp>
#include <Entity.hpp>
#include <EntityBuilder.hpp>
#include <Map.hpp>
#include <iostream>
#include <random>
#include <algorithm>

namespace dt
{
    Logic::Logic()
    {
      // Resize vector and assign Entity IDs based on position
      entities.resize(10);
      for(int i=0; i<=9; i++){
          entities[i].setID(i);
      }

      // Generate random coordinates
      //generateCoords(map, 10);

      // Create player
      EntityBuilder playerBuilder(entities[0]); // Change to entities[0] when vector has pre-set size
      playerBuilder.addPositionComponent({25, 15}); // Replace with random coordinates
      playerBuilder.addVelocityComponent({0, 0});
      playerBuilder.addEnergyComponent(100);
      playerBuilder.addHealthComponent(100);
      playerBuilder.addVisualComponent("TYRANNOSAURUS"); // To be changed when textures added

      // Create escape pod
      Entity escapePod;
      EntityBuilder escapePodBuilder(escapePod); // entities[1]
      escapePodBuilder.addPositionComponent({40,50}); // Replace with random coordinates
      escapePodBuilder.addVisualComponent("ESCAPEPOD"); //To be changed when textures added

      // Assign types and coordinates to enemies
      
      // Load the default map
      map.loadMapFromFile(1);
      mapVector = map.getMap();
    }

    void Logic::update(const sf::Time& delta)
    {
      if(actionPerformed)
      {
        doTurn();
        actionPerformed = false;
      }
    }

    void Logic::doTurn() {
      // Go through each entity and update it with systems
      for(Entity& entity : entities)
      {
          if(entity.hasComponent("Position") && entity.hasComponent("Velocity")){
              movement.update(entity);
          }

          if(entity.hasComponent("Energy")){
              energy.update(entity);
          }

          if(entity.hasComponent("Health")){
              health.update(entity);
          }
      }

      // Stop player
      movement.stop(entities[0]);
      
      //update map
      map.updateCenter(getPlayerPosition().x, getPlayerPosition().y);

      // Decrement turn count; end game if turn count is 0
      turnCount -= 1;
      if(turnCount <= 0)
      {
          std::cout << "Game over." << std::endl;
      }
    }

    int Logic::getTurn() const
    {
        return turnCount;
    }

    void Logic::movePlayer(Direction dir)
    {
      switch (dir)
      {
        case Direction::Up:
          movement.moveUp(entities[0]);
          break;
        case Direction::Down:
          movement.moveDown(entities[0]);
          break;
        case Direction::Left:
          movement.moveLeft(entities[0]);
          break;
        case Direction::Right:
          movement.moveRight(entities[0]);
          break;
        case Direction::None:
          movement.stop(entities[0]);
          break;
      }

      actionPerformed = true;
    }

    const sf::Vector2i& Logic::getPlayerPosition() const
    {
      return entities[0].getComponent("Position").getData().asVec2i;
    }

    const std::string Logic::getPlayerVisual() const
    {
        return entities[0].getComponent("Visual").getData().asString;
    }
	/**
    std::vector<sf::Vector2i> Logic::generateCoords(const Map& map, int numOfCoords)
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> x_cord(1, 96);
        std::uniform_int_distribution<int> y_cord(1, 66);

        std::vector<sf::Vector2i> coordinates;

        for (int num = 0; num < numOfCoords; num++)
        {
            int x = x_cord(mt);
            int y = y_cord(mt);
            sf::Vector2i coord(x, y);

            while (map.getTile(x,y) != 1 && std::find(occupiedSpaces.begin(), occupiedSpaces.end(), coord) != occupiedSpaces.end())
            {
                x = x_cord(mt);
                y = y_cord(mt);
                sf::Vector2i coord(x, y);
            }

            // Vector of coordinates returned
            coordinates.push_back(coord);

            //Vector of coordinates that holds all spaces that are occupied
            occupiedSpaces.push_back(coord);
        }

        return coordinates;
    }
    * */

    int Logic::getPlayerEnergy() {
        return entities[0].getComponent("Energy").getData().asInt;
    }

    int Logic::getPlayerHealth(){
        return entities[0].getComponent("Health").getData().asInt;
    }
    
    const std::vector<int> & Logic::getMap() const
    {
		return mapVector;
	}
}
