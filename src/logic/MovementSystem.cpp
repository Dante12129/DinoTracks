//
// Created by ywzKe on 2019/10/21.
//

#include "MovementSystem.hpp"

#include <iostream>

#include <SFML/System/Vector2.hpp>
#include <Thor/Graphics/ToString.hpp>

#include "components/Component.hpp"
#include "Entity.hpp"
#include "Tags.hpp"


namespace dt
{
  MovementSystem::MovementSystem(std::vector<Entity>& entities, EnergySystem& enesys, Map& map, HealthSystem& heasys)
      : entities(entities), enesys(enesys), map(map), heasys(heasys)
  {}

  void MovementSystem::update(Entity& entity)
  {
    // Get position and velocity components
    Component& positionComponent = entity.getComponent(POSITION);
    Component& velocityComponent = entity.getComponent(VELOCITY);

    // Variables for calculating collision
    sf::Vector2i position = positionComponent.getData().asVec2i;
    sf::Vector2i velocity = velocityComponent.getData().asVec2i;
    sf::Vector2i finalVelocity;

    // Variables for responding to collision
    Entity* collidedEntity = nullptr;

    // Test collision in all four directions
    for(int i = velocity.x > 0 ? 1 : -1; velocity.x != 0 && abs(i) <= abs(velocity.x); i += velocity.x > 0 ? 1 : -1)
    {
      auto it = std::find_if(entities.cbegin() + 1, entities.cend(), [&](const Entity& e)
      {
        return e.hasComponent(POSITION) ? e.getData(POSITION).asVec2i == sf::Vector2i(position.x + i, position.y) : false;
      });
      if(it != entities.cend())
      {
        collidedEntity = const_cast<Entity*>(&*it);
        break;
      }
      else if(map.getTile(position.x + i, position.y) != 1)
        break;
      else
        finalVelocity.x = i;
    }
    for(int i = velocity.y > 0 ? 1 : -1; velocity.y != 0 && abs(i) <= abs(velocity.y); i += velocity.y > 0 ? 1 : -1)
    {
      auto it = std::find_if(entities.cbegin() + 1, entities.cend(), [&](const Entity& e)
      {
          return e.hasComponent(POSITION) ? e.getData(POSITION).asVec2i == sf::Vector2i(position.x, position.y + i) : false;
      });
      if(it != entities.cend())
      {
        collidedEntity = const_cast<Entity*>(&*it);
        break;
      }
      if(map.getTile(position.x, position.y + i) != 1)
        break;
      else
        finalVelocity.y = i;
    }

    // Perform actions on entities based on collision
    int spacesMoved = entityCollision(entity, collidedEntity, velocity, position);

    // Calculate new position based on velocity
    sf::Vector2i newPosition = position + finalVelocity;
    positionComponent.setData(ComponentData(newPosition));

    // Deduct energy based on spaces moved
    if(entity.hasComponent(ENERGY))
    {
      if(finalVelocity.x != 0)
        enesys.adjust(entity, -1 * abs(finalVelocity.x));
      if(finalVelocity.y != 0)
        enesys.adjust(entity, -1 * abs(finalVelocity.y));
      if(spacesMoved != 0)
        enesys.adjust(entity, -1 * spacesMoved);
    }
  }

  void MovementSystem::moveUp(dt::Entity& dino, int vel)
  {
    //get position and velocity from component
    Component& velo = dino.getComponent(VELOCITY);

    // Set velocity
    velo.setData({velo.getData().asVec2i.x, -1*vel});

      // Adjust energy
      //enesys.adjust(dino, -1);

  }
  void MovementSystem::moveDown(dt::Entity& dino, int vel)
  {
    //get position and velocity from component
    Component& posi = dino.getComponent(POSITION);
    Component& velo = dino.getComponent(VELOCITY);

    // Set velocity
    velo.setData({velo.getData().asVec2i.x, vel});

      // Adjust energy
      //enesys.adjust(dino, -1);

  }
  void MovementSystem::moveLeft(dt::Entity& dino, int vel)
  {
    //get position and velocity from component
    Component& posi = dino.getComponent(POSITION);
    Component& velo = dino.getComponent(VELOCITY);

    // Set velocity
    velo.setData({-1*vel, velo.getData().asVec2i.y});

      // Adjust energy
      //enesys.adjust(dino, -1);

  }
  void MovementSystem::moveRight(dt::Entity& dino, int vel)
  {
    //get position and velocity from component
    Component& posi = dino.getComponent(POSITION);
    Component& velo = dino.getComponent(VELOCITY);

    // Set velocity
    velo.setData({vel, velo.getData().asVec2i.y});

    // Adjust energy
    //enesys.adjust(dino, -1);
  }
  void MovementSystem::stop(dt::Entity& dino)
  {
    //get position and velocity from component
    Component& velo = dino.getComponent(VELOCITY);

    //set velocity as 0
    velo.setData({0, 0});
  }
  int MovementSystem::entityCollision(Entity& entity, const Entity* collidedEntity, const sf::Vector2i& velocity, sf::Vector2i& position)
  {
      int spacesMoved = 0;
      if (collidedEntity != nullptr)
      {
          if (entity.getID() == 0) // Player initiates collision
          {
//            std::cout << "Initiator: " << entity.getID() << std::endl;
              int id = collidedEntity->getID();
              std::cout << "Entity Collision: " << id << std::endl;

              if (id >= ENEMY_START && id <= ENEMY_END) // Collision with enemy
              {
//                std::cout << "Collision with enemy." << std::endl;
                  fight(entities[0], entities[id]);
              }
              else if(id >= FOOD_HERB_START && id <= FOOD_CARN_END) //Collision with any food
              {
                  // Check velocity and move player over food
                  if (velocity.x > 0) { position.x += 1;  }
                  else if (velocity.x < 0) { position.x += -1; spacesMoved = 1; }

                  if (velocity.y > 0) { position.y += 1; spacesMoved = 1; }
                  else if (velocity.y < 0) { position.y += -1; spacesMoved = 1; }

                  std::cout << "Collision with food: " << thor::toString(collidedEntity->getData(FOOD).asVec2i) << std::endl;

//                  HealthSystem and EnergySystem eat
                  heasys.eat(entity, *collidedEntity);
                  enesys.eat(entity, *collidedEntity);
              }
              else if (id >= EGG_START && id <= EGG_END) // Collision with egg
              {
                  // Check velocity and move player over egg
                  if (velocity.x > 0) { position.x += 1; spacesMoved = 1; }
                  else if (velocity.x < 0) { position.x += -1; spacesMoved = 1; }

                  if (velocity.y > 0) { position.y += 1; spacesMoved = 1; }
                  else if (velocity.y < 0) { position.y += -1; spacesMoved = 1; }

//                  std::cout << "Collision with egg." << std::endl;
                  const Component& scoreComponent = collidedEntity->getComponent(SCORE);
                  int eggScore = scoreComponent.getData().asInt;
                  score += eggScore;
//                  std::cout << "Score: " << score << std::endl;
              }

          }
      }

      return spacesMoved;
  }
  int MovementSystem::getScoreCount() const
  {
      return score;
  }

  void MovementSystem::fight(dt::Entity &player, dt::Entity &enemy) {
      std::cout << "Enter combat";
      while(player.getComponent(HEALTH).getData().asInt>0 && enemy.getComponent(HEALTH).getData().asInt>0){
          int playerhea = player.getComponent(HEALTH).getData().asInt;
          int playerattack = player.getComponent(ATTRIBUTES).getData().asVec2i.x;
          int playerdefense = player.getComponent(ATTRIBUTES).getData().asVec2i.y;
          int enemyhea = enemy.getComponent(HEALTH).getData().asInt;
          int enemyattack = enemy.getComponent(ATTRIBUTES).getData().asVec2i.x;
          int enemydefense = enemy.getComponent(ATTRIBUTES).getData().asVec2i.y;

            std::cout<<"combating ..."<<"\n";

          if(playerhea + playerdefense - enemyattack <= 0){
              heasys.set(player, 0);
              std::cout << "Game Over in Combat";
          }
          else if(enemyhea + enemydefense - playerattack <= 0){
              heasys.set(enemy, 0);
              std::cout<<enemy.getComponent(HEALTH).getData().asInt;
              std::cout << "Enemy Dinosaur die";
          }
          else if(enemyattack-playerdefense<=0 || playerattack-enemydefense<=0){
              std::cout << "can't lose health";
          }
          else{
              //player.getComponent(HEALTH).setData(playerhea + playerdefense - enemyattack);
              //enemy.getComponent(HEALTH).setData(enemyhea + enemydefense - playerattack);
              heasys.heal(player, playerdefense - enemyattack);
              heasys.heal(enemy, enemydefense - playerattack);
              std::cout<<enemy.getComponent(HEALTH).getData().asInt<<"\n";
          }
          heasys.update(player);
          heasys.update(enemy);
      }
  }
}