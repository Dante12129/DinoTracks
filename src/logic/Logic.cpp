//
// Created by Dan on 10/13/2019.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

#include <SFML/System/Time.hpp>
#include <Thor/Graphics/ToString.hpp>

#include <Application.hpp>
#include <Logic.hpp>
#include <Entity.hpp>
#include <EntityBuilder.hpp>
#include <Map.hpp>
#include <DinosaurType.hpp>
#include <components/Visual.hpp>
#include <Tags.hpp>
#include "SoundManager.hpp"

namespace dt
{
    Logic::Logic(const std::string& playerDino, int level)
    {
      // Load the default map
      map.loadMapFromFile(level);

      // Resize vector and assign Entity IDs based on position
      entities.resize(MAX_ENTITIES);
      for(int i=0; i<MAX_ENTITIES; i++){
          entities[i].setID(i);
          entities[i].setRegen(false);
      }

      // Generate random coordinates
      std::vector<sf::Vector2i> entityCoords = generateCoords(MAX_ENTITIES);

      // Create player
      DinosaurType dino = ResourceManager::currentManager->getDinosaurType(playerDino);
      EntityBuilder playerBuilder(entities[PLAYER]);
      playerBuilder.addPositionComponent(entityCoords[PLAYER]);
      playerBuilder.addVelocityComponent({0, 0});
      playerBuilder.addEnergyComponent(MAX_ENERGY);
      playerBuilder.addHealthComponent(dino.getHealth()*2); // Increase the health a bit
      playerBuilder.addVisualComponent(playerDino); // To be changed when textures added
      playerBuilder.addAttributesComponent(dino.getAttack(), dino.getDefense());


      // Create escape pod
      Entity escapePod;
      EntityBuilder escapePodBuilder(entities[ESCAPE_POD]); // entities[1]
      escapePodBuilder.addPositionComponent(entityCoords[ESCAPE_POD]);
      escapePodBuilder.addVisualComponent(ESCAPE_TEX); //To be changed when textures added

        // Assign types and coordinates to enemies
      std::mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
      std::uniform_int_distribution<int> dinoType(1, NUM_TYPES);  
      
      for (int i = ENEMY_START; i <= ENEMY_END; ++i)
      {
        EntityBuilder dinoBuilder(entities[i]);
        DinosaurType dino;
        std::string dinoString;
        
        int type = dinoType(mt);

        switch(type)
        {
        case (1):
          dino = ResourceManager::currentManager->getDinosaurType(STEGOSAURUS);
          dinoString = STEGOSAURUS;
          break;
        case (2):
          dino = ResourceManager::currentManager->getDinosaurType(TYRANNOSAURUS);
          dinoString = TYRANNOSAURUS;
          break;
        case (3):
          dino = ResourceManager::currentManager->getDinosaurType(PARASAUROLOPHUS);
          dinoString = PARASAUROLOPHUS;
          break;
        case (4):
          dino = ResourceManager::currentManager->getDinosaurType(SPINOSAURUS);
          dinoString = SPINOSAURUS;
          break;
        case (5):
          dino = ResourceManager::currentManager->getDinosaurType(ALLOSAURUS);
          dinoString = ALLOSAURUS;
          break;
        case (6):
          dino = ResourceManager::currentManager->getDinosaurType(PACHYCEPHALOSAURUS);
          dinoString = PACHYCEPHALOSAURUS;
          break;
        case (7):
          dino = ResourceManager::currentManager->getDinosaurType(PROTOCERATOPS);
          dinoString = PROTOCERATOPS;
          break;
        case (8):
          dino = ResourceManager::currentManager->getDinosaurType(VELOCIRAPTOR);
          dinoString = VELOCIRAPTOR;
          break;
        }

        dinoBuilder.addPositionComponent(entityCoords.at(i));
        dinoBuilder.addHealthComponent(dino.getHealth());
        dinoBuilder.addAttributesComponent(dino.getAttack(), dino.getDefense());
        dinoBuilder.addVisualComponent(dinoString);
        dinoBuilder.addVelocityComponent({0, 0});
	    }

      // Create herb food
      for(int i = FOOD_HERB_START; i <= FOOD_HERB_END; ++i)
      {
          EntityBuilder herbBuilder(entities[i]);

          herbBuilder.addPositionComponent(entityCoords.at(i));
          herbBuilder.addVisualComponent(FRUIT);
          herbBuilder.addFoodComponent(15, 20);
      }

      // Create carn food
      for(int i = FOOD_CARN_START; i <= FOOD_CARN_END; ++i)
      {
          EntityBuilder carnBuilder(entities[i]);

          carnBuilder.addPositionComponent({-5, -5});
          carnBuilder.addVisualComponent(MEAT);
          carnBuilder.addFoodComponent(40, 50);
      }

      // Create eggs
        for (int i = EGG_START; i <= EGG_END; ++i)
        {
            EntityBuilder eggBuilder(entities[i]);

            eggBuilder.addPositionComponent(entityCoords.at(i));
            eggBuilder.addVisualComponent(EGG);
            eggBuilder.addScoreComponent(1);
        }

        health.init(entities);
        energy.init(entities);
    }

    void Logic::update(const sf::Time& delta)
    {
        if(actionPerformed)
        {
          std::cout << "\nNew Turn" << std::endl;
          doTurn();
          actionPerformed = false;
        }
    }

    void Logic::doTurn()
    {
//      std::cout << "Starting Energy: " << entities[0].getData(ENERGY).asInt << std::endl;
        std::cout << "Starting Health: " << entities[PLAYER].getData(HEALTH).asVec2i.x << std::endl;

        // Go through each entity and update it with systems
        for(Entity& entity : entities)
        {
            if(entity.hasComponent(POSITION) && entity.hasComponent(VELOCITY)){
                movement.update(entity);
            }
        }
      for(Entity& entity : entities)
      {
        if(entity.hasComponent(ENERGY)){
          energy.update(entity);
        }

        if(entity.hasComponent(HEALTH)){
          health.update(entity);
        }
      }

//      std::cout << "Ending Energy: " << entities[0].getData(ENERGY).asInt << std::endl;
        std::cout << "Ending Health: " << entities[PLAYER].getData(HEALTH).asVec2i.x << std::endl;

        // Stop player
        movement.stop(entities[PLAYER]);

        //update map
        map.updateCenter(getPlayerPosition().x, getPlayerPosition().y);

        // Decrement turn count; end game if turn count is 0
        turnCount -= 1;
        if(turnCount <= 0)
        {
//            std::cout << "Game over." << std::endl;
          SoundManager::curSoundManager->addToQueue(SOUND_LOSE);
          Application::currentApplication->endGame(EndMenu::Reason::Meteor);
        }

        // End game if no health
        if(entities[PLAYER].getData(HEALTH).asVec2i.x <= 0)
        {
//            std::cout << "Game over because of low health." << std::endl;
          SoundManager::curSoundManager->addToQueue(SOUND_LOSE);
          Application::currentApplication->endGame(EndMenu::Reason::Health);
        }

        // End game if no energy
        if(entities[PLAYER].getData(ENERGY).asInt <= 0)
        {
          SoundManager::curSoundManager->addToQueue(SOUND_LOSE);
          Application::currentApplication->endGame(EndMenu::Reason::Energy);
        }

//        std::cout << "Current health: " << entities[0].getComponent("Health").getData().asInt << "\n";
//        std::cout << "Current energy: " << entities[0].getComponent("Energy").getData().asInt << "\n";


		for (Entity& entity: entities)
		{
			if(entity.getRegen()){
				occupiedSpaces.clear();
				
				for(Entity& entity : entities)
				{
					occupiedSpaces.push_back(entity.getComponent(POSITION).getData().asVec2i);
				}
				
				if (entity.getID() <= ENEMY_END && entity.getID() >= ENEMY_START)
				{
					for (int i = FOOD_CARN_START; i <= FOOD_CARN_END; i++)
					{
					  // Reset health
					  health.set(entity, entity.getData(HEALTH).asVec2i.y);

						sf::Vector2i testPos = {-5, -5};
						if (entities[i].getComponent(POSITION).getData().asVec2i == testPos)
						{
							Component& positionComponent = entities[i].getComponent(POSITION);
							sf::Vector2i meatPos = entity.getComponent(POSITION).getData().asVec2i;
							positionComponent.setData(ComponentData(meatPos));
							break;
						}
					}
				}
								
				if (entity.getID() <= FOOD_CARN_END && entity.getID() >= FOOD_CARN_START)
				{
					Component& positionComponent = entity.getComponent(POSITION);
					sf::Vector2i newPosition = {-5, -5};
					positionComponent.setData(ComponentData(newPosition));
				}
				else
				{
				
					std::vector<sf::Vector2i> newCoords = generateCoords(1);
					Component& positionComponent = entity.getComponent(POSITION);
					sf::Vector2i newPosition = newCoords[0];
					positionComponent.setData(ComponentData(newPosition));
				}
				
				entity.setRegen(false);
			}
		}
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
            std::string dinoType = dynamic_cast<const Visual&>(entities[0].getComponent(VISUAL)).getString();
            DinosaurType dino = ResourceManager::currentManager->getDinosaurType(dinoType);
            velocity = dino.getSpeed();
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

    void Logic::moveEnemy(int id, Direction dir)
    {
		sf::Vector2i curPos = entities[id].getData(POSITION).asVec2i;
		sf::Vector2i playerPos = entities[0].getData(POSITION).asVec2i;
		
		switch (dir)
        {
            case Direction::Up:
                movement.stop(entities[id]);
                
                if (map.getTile(curPos.x, curPos.y - 1) != 1)
                {
					if (playerPos.x < curPos.x)
					{
						movement.moveLeft(entities[id], 1);
					}
					else
					{
						movement.moveRight(entities[id], 1);
					}
				}
				else
				{
					movement.moveUp(entities[id], 1);
				}
                break;
            case Direction::Down:
                movement.stop(entities[id]);
                
                if (map.getTile(curPos.x, curPos.y + 1) != 1)
                {
					if (playerPos.x < curPos.x)
					{
						movement.moveLeft(entities[id], 1);
					}
					else
					{
						movement.moveRight(entities[id], 1);
					}
				}
				else
				{
					movement.moveDown(entities[id], 1);
				}
                break;
            case Direction::Left:
                movement.stop(entities[id]);
                
                if (map.getTile(curPos.x - 1, curPos.y) != 1)
                {
					if (playerPos.y < curPos.y)
					{
						movement.moveUp(entities[id], 1);
					}
					else
					{
						movement.moveDown(entities[id], 1);
					}
				}
				else
				{
					movement.moveLeft(entities[id], 1);
				}
                break;
            case Direction::Right:
                movement.stop(entities[id]);
                
                if (map.getTile(curPos.x + 1, curPos.y) != 1)
                {
					if (playerPos.y < curPos.y)
					{
						movement.moveUp(entities[id], 1);
					}
					else
					{
						movement.moveDown(entities[id], 1);
					}
				}
				else
				{
					movement.moveRight(entities[id], 1);
				}
                break;
        }
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
      return entities[PLAYER].getComponent(ENERGY).getData().asVec2i.x;
    }

    int Logic::getPlayerHealth() const {
      return entities[PLAYER].getComponent(HEALTH).getData().asVec2i.x;
    }

    int Logic::getPlayerMaxHealth() const {
        return entities[PLAYER].getComponent(HEALTH).getData().asVec2i.y;
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
        std::uniform_int_distribution<int> x_cord(21, 130);
        std::uniform_int_distribution<int> y_cord(12, 139);

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
