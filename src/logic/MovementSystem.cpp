//
// Created by ywzKe on 2019/10/21.
//

#include "MovementSystem.hpp"

#include <iostream>

#include <SFML/System/Vector2.hpp>
#include "components/Component.hpp"
#include "Entity.hpp"
#include "Tags.hpp"


namespace dt
{
  MovementSystem::MovementSystem(EnergySystem& enesys, Map& map):enesys(enesys), map(map)
  {}

  void MovementSystem::update(Entity& entity)
  {
    // Get position and velocity components
    Component& positionComponent = entity.getComponent(POSITION);
    Component& velocityComponent = entity.getComponent(VELOCITY);

    // Variables for calculating collision
    sf::Vector2i position = positionComponent.getData().asVec2i;
    sf::Vector2i velocity = velocityComponent.getData().asVec2i;
    sf::Vector2i finalVelocity = velocity;

    // Test collision in all four directions
    for(int i = 0; abs(i) <= abs(velocity.x); i += velocity.x > 0 ? 1 : -1)
    {
      if(map.getTile(position.x + i, position.y) != 1)
        break;
      else
        finalVelocity.x = i;
    }
    for(int i = 0; abs(i) <= abs(velocity.y); i += velocity.y > 0 ? 1 : -1)
    {
      if(map.getTile(position.x, position.y + i) != 1)
        break;
      else
        finalVelocity.y = i;
    }

    // Calculate new position based on velocity
    sf::Vector2i newPosition = position + finalVelocity;
    positionComponent.setData(ComponentData(newPosition));

    // Deduct energy based on terrain
    int terrain = map.getTile(newPosition.x-1, newPosition.y-1);
    if(terrain == 0)
    {
        enesys.adjust(entity, -20);
    }
    else if(terrain == 1)
    {
        enesys.adjust(entity, -1);
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
}