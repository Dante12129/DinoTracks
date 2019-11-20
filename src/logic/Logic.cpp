//
// Created by Dan on 10/13/2019.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

#include <SFML/System/Time.hpp>

#include <Logic.hpp>
#include <Entity.hpp>
#include <EntityBuilder.hpp>
#include <Map.hpp>
#include <DinosaurType.hpp>
#include <components/Visual.hpp>


namespace dt
{
    Logic::Logic()
    {
        // Load the default map
        map.loadMapFromFile(1);

        // Resize vector and assign Entity IDs based on position
        entities.resize(10);
        for(int i=0; i<=9; i++){
            entities[i].setID(i);
        }

        // Generate random coordinates
        std::vector<sf::Vector2i> entityCoords = generateCoords(10);

        // Create player
        EntityBuilder playerBuilder(entities[0]);
        playerBuilder.addPositionComponent(entityCoords[0]);
        playerBuilder.addVelocityComponent({0, 0});
        playerBuilder.addEnergyComponent(100);
        playerBuilder.addHealthComponent(100);
        playerBuilder.addVisualComponent("TYRANNOSAURUS"); // To be changed when textures added

        // Create escape pod
        Entity escapePod;
        EntityBuilder escapePodBuilder(escapePod); // entities[1]
        escapePodBuilder.addPositionComponent(entityCoords[1]);
        escapePodBuilder.addVisualComponent("ESCAPEPOD"); //To be changed when textures added

        // Assign types and coordinates to enemies
      for (int i = 2; i < 10; ++i)
      {
		  EntityBuilder dinoBuilder(entities[i]);
		  DinosaurType dino;
		  std::string dinoString;

		  if (i % 2 == 0)
		  {
			  dino = ResourceManager::currentManager->getDinosaurType("STEGOSAURUS");
			  dinoString = "STEGOSAURUS";
		  }
		  else
		  {
			  dino = ResourceManager::currentManager->getDinosaurType("TYRANNOSAURUS");
			  dinoString = "TYRANNOSAURUS";
		  }

		  dinoBuilder.addPositionComponent(entityCoords.at(i));
		  dinoBuilder.addHealthComponent(dino.getHealth());
		  dinoBuilder.addVisualComponent(dinoString);
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
                movement.moveUp(entities[0], velocity);
                break;
            case Direction::Down:
                movement.moveDown(entities[0], velocity);
                break;
            case Direction::Left:
                movement.moveLeft(entities[0], velocity);
                break;
            case Direction::Right:
                movement.moveRight(entities[0], velocity);
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

    const std::string& Logic::getPlayerVisual() const
    {
        return dynamic_cast<const Visual&>(entities[0].getComponent("Visual")).getString();
    }

    int Logic::getPlayerEnergy() {
      return entities[0].getComponent("Energy").getData().asInt;
    }

    int Logic::getPlayerHealth(){
      return entities[0].getComponent("Health").getData().asInt;
    }

    const Map& Logic::getMap() const
    {
      return map;
    }

    std::vector<sf::Vector2i> Logic::getEnemyPositions() const
    {
      std::vector<sf::Vector2i> coords;

      for(int i = 2; i < 10; ++i)
      {
        coords.push_back(entities.at(i).getData("Position").asVec2i);
      }

      return coords;
    }

    std::vector<std::string> Logic::getEnemyVisuals() const
    {
      std::vector<std::string> visuals;

      for(int i = 2; i < 10; ++i)
      {
        const Visual& visComponent = dynamic_cast<const Visual&>(entities.at(i).getComponent("Visual"));
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

            std::cout << "Chosen coords for " << num << " are " << coord.x << ", " << coord.y << std::endl;
            std::cout << "Type is " << map.getTile(coord.x, coord.y) << std::endl;

            // Vector of coordinates returned
            coordinates.push_back(coord);

            //Vector of coordinates that holds all spaces that are occupied
            occupiedSpaces.push_back(coord);
        }

        return coordinates;
    }
}
