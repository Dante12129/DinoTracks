//
// Created by ywzKe on 2019/10/21.
//

#include "MovementSystem.hpp"

#include <SFML/System/Vector2.hpp>
#include "components/Component.hpp"
#include "Entity.hpp"
#include "EnergySystem.hpp"


namespace dt
{
  const std::string MovementSystem::posi_str = "Position";
  const std::string MovementSystem::velo_str = "Velocity";

  MovementSystem::MovementSystem(EnergySystem& enesys):enesys(enesys){}

  void MovementSystem::update(Entity& entity)
  {
    // Get position and velocity components
    Component& positionComponent = entity.getComponent(posi_str);
    Component& velocityComponent = entity.getComponent(velo_str);

    // Calculate new position based on velocity
    sf::Vector2i newPosition = positionComponent.getData().asVec2i + velocityComponent.getData().asVec2i;
    positionComponent.setData(ComponentData(newPosition));
  }

  void MovementSystem::moveUp(dt::Entity& dino)
  {
      //get position and velocity from component
      Component& velo = dino.getComponent(velo_str);

      // Set velocity
      velo.setData({velo.getData().asVec2i.x, -1});

      // Adjust energy
      enesys.adjust(dino, -5);

  }
  void MovementSystem::moveDown(dt::Entity& dino)
  {
      //get position and velocity from component
      Component& posi = dino.getComponent(posi_str);
      Component& velo = dino.getComponent(velo_str);

    // Set velocity
    velo.setData({velo.getData().asVec2i.x, 1});

      // Adjust energy
      enesys.adjust(dino, -5);

  }
  void MovementSystem::moveLeft(dt::Entity& dino)
  {
      //get position and velocity from component
      Component& posi = dino.getComponent(posi_str);
      Component& velo = dino.getComponent(velo_str);

    // Set velocity
    velo.setData({-1, velo.getData().asVec2i.y});

      // Adjust energy
      enesys.adjust(dino, -5);

  }
  void MovementSystem::moveRight(dt::Entity& dino)
  {
    //get position and velocity from component
    Component& posi = dino.getComponent(posi_str);
    Component& velo = dino.getComponent(velo_str);

    // Set velocity
    velo.setData({1, velo.getData().asVec2i.y});

      // Adjust energy
      enesys.adjust(dino, -5);
  }
  void MovementSystem::stop(dt::Entity& dino)
  {
    //get position and velocity from component
    Component& velo = dino.getComponent(velo_str);

    //set velocity as 0
    velo.setData({0, 0});
  }



}