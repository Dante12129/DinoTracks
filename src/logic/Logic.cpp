//
// Created by Dan on 10/13/2019.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

#include <SFML/System/Time.hpp>
#include <Thor/Graphics/ToString.hpp>

#include <Logic.hpp>
#include <Entity.hpp>
#include <EntityBuilder.hpp>
#include <Map.hpp>
#include <DinosaurType.hpp>
#include <components/Visual.hpp>
#include "Tags.hpp"

namespace dt
{
    Logic::Logic()
    {
      // Load the default map
      map.loadMapFromFile(1);

      // Resize vector and assign Entity IDs based on position
      entities.resize(35);
      for(int i=0; i<=34; i++)
      {
          entities[i].setID(i);
      }

      // Generate random coordinates
      std::vector<sf::Vector2i> entityCoords = generateCoords(35);
//      for(const sf::Vector2i& coords : entityCoords)
//      {
//        std::cout << "Coords: " << thor::toString(coords) << std::endl;
//      }

      // Create player
      EntityBuilder playerBuilder(entities[PLAYER]);
      playerBuilder.addPositionComponent(entityCoords[PLAYER]);
      playerBuilder.addVelocityComponent({0, 0});
      playerBuilder.addEnergyComponent(100);
      playerBuilder.addHealthComponent(100);
      playerBuilder.addVisualComponent(TYRANNOSAURUS); // To be changed when textures added

      // Create escape pod
      Entity escapePod;
      EntityBuilder escapePodBuilder(entities[ESCAPE_POD]); // entities[1]
      escapePodBuilder.addPositionComponent(entityCoords[ESCAPE_POD]);
      escapePodBuilder.addVisualComponent(ESCAPE_TEX); //To be changed when textures added

        // Assign types and coordinates to enemies
      for (int i = ENEMY_START; i <= ENEMY_END; ++i)
      {
        EntityBuilder dinoBuilder(entities[i]);
        DinosaurType dino;
        std::string dinoString;

        if (i % 2 == 0)
        {
          dino = ResourceManager::currentManager->getDinosaurType(STEGOSAURUS);
          dinoString = STEGOSAURUS;
        }
        else
        {
          dino = ResourceManager::currentManager->getDinosaurType(TYRANNOSAURUS);
          dinoString = TYRANNOSAURUS;
        }

        dinoBuilder.addPositionComponent(entityCoords.at(i));
        dinoBuilder.addHealthComponent(dino.getHealth());
        dinoBuilder.addVisualComponent(dinoString);
	    }

      // Create herb food
      for(int i = FOOD_HERB_START; i <= FOOD_HERB_END; ++i)
      {
          EntityBuilder herbBuilder(entities[i]);

          herbBuilder.addPositionComponent(entityCoords.at(i));
          herbBuilder.addVisualComponent(TREE);
          herbBuilder.addFoodComponent(10, 10);
      }

      // Create carn food
      for(int i = FOOD_CARN_START; i <= FOOD_CARN_END; ++i)
      {
          EntityBuilder carnBuilder(entities[i]);

          carnBuilder.addPositionComponent(entityCoords.at(i));
          carnBuilder.addVisualComponent(MEAT);
          carnBuilder.addFoodComponent(10, 10);
      }

      // Create eggs
        for (int i = EGG_START; i <= EGG_END; ++i)
        {
            EntityBuilder eggBuilder(entities[i]);

            eggBuilder.addPositionComponent(entityCoords.at(i));
            eggBuilder.addVisualComponent(EGG);
            eggBuilder.addScoreComponent(1);
        }

    }

    void Logic::update(const sf::Time& delta)
    {
        if(actionPerformed)
        {
            doTurn();
            actionPerformed = false;
        }
    }

    void Logic::doTurn()
    {
//      std::cout << "Starting Energy: " << entities[0].getData(ENERGY).asInt << std::endl;

        // Go through each entity and update it with systems
        for(Entity& entity : entities)
        {
            if(entity.hasComponent(POSITION) && entity.hasComponent(VELOCITY)){
                movement.update(entity);
            }

            if(entity.hasComponent(ENERGY)){
                energy.update(entity);
            }

            if(entity.hasComponent(HEALTH)){
                health.update(entity);
            }
        }

//      std::cout << "Ending Energy: " << entities[0].getData(ENERGY).asInt << std::endl;

        // Stop player
        movement.stop(entities[PLAYER]);

        //update map
        map.updateCenter(getPlayerPosition().x, getPlayerPosition().y);

        // Decrement turn count; end game if turn count is 0
        turnCount -= 1;
        if(turnCount <= 0)
        {
            std::cout << "Game over." << std::endl;
        }

        // End game if no health
        if(entities[PLAYER].getComponent("Health").getData().asInt<=0){
            std::cout << "Game over because of low health." << std::endl;
        }

//        std::cout << "Current health: " << entities[0].getComponent("Health").getData().asInt << "\n";
//        std::cout << "Current energy: " << entities[0].getComponent("Energy").getData().asInt << "\n";
    }

    int Logic::getTurn() const
    {
        return turnCount;
    }

    int Logic::getScore() const
    {
        return movement.getScoreCount();
    }

    void Logic::movePlayer(Direction dir, Speed spd)
    {
        int velocity;

        if (spd == Speed::Fast)
        {
            velocity = 3;
        }
        else
        {
            velocity = 1;
        }

        switch (dir)
        {
            case Direction::Up:
                movement.moveUp(entities[PLAYER], velocity);
                break;
            case Direction::Down:
                movement.moveDown(entities[PLAYER], velocity);
                break;
            case Direction::Left:
                movement.moveLeft(entities[PLAYER], velocity);
                break;
            case Direction::Right:
                movement.moveRight(entities[PLAYER], velocity);
                break;
            case Direction::None:
                movement.stop(entities[PLAYER]);
                break;
        }

        actionPerformed = true;
    }

    const sf::Vector2i& Logic::getPlayerPosition() const
    {
        return entities[PLAYER].getComponent(POSITION).getData().asVec2i;
    }

    const std::string& Logic::getPlayerVisual() const
    {
        return dynamic_cast<const Visual&>(entities[PLAYER].getComponent(VISUAL)).getString();
    }

    int Logic::getPlayerEnergy() const {
      return entities[PLAYER].getComponent(ENERGY).getData().asInt;
    }

    int Logic::getPlayerHealth() const {
      return entities[PLAYER].getComponent(HEALTH).getData().asInt;
    }

    const Map& Logic::getMap() const
    {
      return map;
    }

    std::vector<sf::Vector2i> Logic::getEntityPositions() const
    {
        std::vector<sf::Vector2i> coords;
        for(int i = ESCAPE_POD; i <= EGG_END; ++i)
        {
            coords.push_back(entities.at(i).getData(POSITION).asVec2i);
        }

        return coords;
    }

    std::vector<std::string> Logic::getEntityVisuals() const
    {
      std::vector<std::string> visuals;

      for(int i = ESCAPE_POD; i <= EGG_END; ++i)
      {
        const Visual& visComponent = dynamic_cast<const Visual&>(entities.at(i).getComponent(VISUAL));
        visuals.push_back(visComponent.getString());
//        visuals.push_back("STEGOSAURUS");
      }

      return visuals;
    }

    std::vector<sf::Vector2i> Logic::generateCoords(int numOfCoords)
    {
        std::mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> x_cord(1, 96);
        std::uniform_int_distribution<int> y_cord(1, 66);

        std::vector<sf::Vector2i> coordinates;

        for (int num = 0; num < numOfCoords; num++)
        {
            int x = x_cord(mt);
            int y = y_cord(mt);
            sf::Vector2i coord(x, y);

            while (map.getTile(coord.x,coord.y) != 1 && (std::find(occupiedSpaces.begin(), occupiedSpaces.end(), coord) == occupiedSpaces.end()))
            {
                coord.x = x_cord(mt);
                coord.y = y_cord(mt);
            }

//            std::cout << "Chosen coords for " << num << " are " << coord.x << ", " << coord.y << std::endl;
//            std::cout << "Type is " << map.getTile(coord.x, coord.y) << std::endl;

            // Vector of coordinates returned
            coordinates.push_back(coord);

            //Vector of coordinates that holds all spaces that are occupied
            occupiedSpaces.push_back(coord);
        }

        return coordinates;
    }
}
