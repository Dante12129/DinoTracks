//
// Created by ywzKe on 2019/10/21.
//

#include "MovementSystem.hpp"

#include <SFML/System/Vector2.hpp>
#include "components/Component.hpp"
#include "Entity.hpp"




namespace dt
{
  const std::string MovementSystem::posi_str = "Position";
  const std::string MovementSystem::velo_str = "Velocity";

  void MovementSystem::update(std::vector<Entity>& entities)
  {
    for(Entity& entity : entities)
    {
      // Get position and velocity components
      Component& positionComponent = entity.getComponent(posi_str);
      Component& velocityComponent = entity.getComponent(velo_str);

      // Calculate new position based on velocity
      sf::Vector2i newPosition = positionComponent.getVectorData() + velocityComponent.getVectorData();
      positionComponent.setData(newPosition);
    }
  }

  void MovementSystem::moveUp(dt::Entity& dino)
  {
      //get position and velocity from component
      Component& velo = dino.getComponent(velo_str);

      // Set velocity
      velo.setData({velo.getVectorData().x, -1});

  }
  void MovementSystem::moveDown(dt::Entity& dino)
  {
      //get position and velocity from component
      Component& posi = dino.getComponent(posi_str);
      Component& velo = dino.getComponent(velo_str);

    // Set velocity
    velo.setData({velo.getVectorData().x, 1});

  }
  void MovementSystem::moveLeft(dt::Entity& dino)
  {
      //get position and velocity from component
      Component& posi = dino.getComponent(posi_str);
      Component& velo = dino.getComponent(velo_str);

    // Set velocity
    velo.setData({-1, velo.getVectorData().y});

  }
  void MovementSystem::moveRight(dt::Entity& dino)
  {
    //get position and velocity from component
    Component& posi = dino.getComponent(posi_str);
    Component& velo = dino.getComponent(velo_str);

    // Set velocity
    velo.setData({1, velo.getVectorData().y});
  }
  void MovementSystem::stop(dt::Entity& dino)
  {
    //get position and velocity from component
    Component& velo = dino.getComponent(velo_str);

    //set velocity as 0
    velo.setData({0, 0});
  }
}