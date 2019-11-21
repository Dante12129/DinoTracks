//
// Created by ywzKe on 2019/10/21.
//

#include "MovementSystem.hpp"

#include <SFML/System/Vector2.hpp>
#include "components/Component.hpp"


namespace dt
{
  const std::string MovementSystem::posi_str = "Position";
  const std::string MovementSystem::velo_str = "Velocity";

  MovementSystem::MovementSystem(EnergySystem& enesys, Map& map):enesys(enesys), map(map)
  {}

  void MovementSystem::update(Entity& entity)
  {
    // Get position and velocity components
    Component& positionComponent = entity.getComponent(posi_str);
    Component& velocityComponent = entity.getComponent(velo_str);

    // Calculate new position based on velocity
    sf::Vector2i newPosition = positionComponent.getData().asVec2i + velocityComponent.getData().asVec2i;
    positionComponent.setData(ComponentData(newPosition));

    // Deduct energy based on terrain
    int terrain = map.getTile(newPosition.x-1, newPosition.y-1);
    if(terrain == 0){
        enesys.adjust(entity, -20);
    }
    else if(terrain == 1){
        enesys.adjust(entity, -1);
    }

  }

  void MovementSystem::moveUp(dt::Entity& dino)
  {
      //get position and velocity from component
      Component& velo = dino.getComponent(velo_str);

      // Set velocity
      velo.setData({velo.getData().asVec2i.x, -1});

      // Adjust energy
      //enesys.adjust(dino, -1);

  }
  void MovementSystem::moveDown(dt::Entity& dino)
  {
      //get position and velocity from component
      Component& posi = dino.getComponent(posi_str);
      Component& velo = dino.getComponent(velo_str);

    // Set velocity
    velo.setData({velo.getData().asVec2i.x, 1});

      // Adjust energy
      //enesys.adjust(dino, -1);

  }
  void MovementSystem::moveLeft(dt::Entity& dino)
  {
      //get position and velocity from component
      Component& posi = dino.getComponent(posi_str);
      Component& velo = dino.getComponent(velo_str);

    // Set velocity
    velo.setData({-1, velo.getData().asVec2i.y});

      // Adjust energy
      //enesys.adjust(dino, -1);

  }
  void MovementSystem::moveRight(dt::Entity& dino)
  {
    //get position and velocity from component
    Component& posi = dino.getComponent(posi_str);
    Component& velo = dino.getComponent(velo_str);

    // Set velocity
    velo.setData({1, velo.getData().asVec2i.y});

      // Adjust energy
      //enesys.adjust(dino, -1);
  }
  void MovementSystem::stop(dt::Entity& dino)
  {
    //get position and velocity from component
    Component& velo = dino.getComponent(velo_str);

    //set velocity as 0
    velo.setData({0, 0});
  }



}