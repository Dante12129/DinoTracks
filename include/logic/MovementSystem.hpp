//
// Created by ywzKe on 2019/10/21.
//

#ifndef DINOTRACKS_MOVEMENTSYSTEM_HPP
#define DINOTRACKS_MOVEMENTSYSTEM_HPP

#include <string>

#include "components/Component.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"
#include "Entity.hpp"
#include "System.hpp"
#include "EnergySystem.hpp"
#include "Map.hpp"

namespace dt
{
  class MovementSystem : public System //This system deals with functionality of movement
  {
  public:
      MovementSystem(const std::vector<Entity>& entities, EnergySystem& enesys, Map& map);
      virtual void update(Entity& entity) override;

      void moveUp(dt::Entity& dino, int velocity);
      void moveDown(dt::Entity& dino, int velocity);
      void moveLeft(dt::Entity& dino, int velocity);
      void moveRight(dt::Entity& dino, int velocity);
      void stop(dt::Entity& dino);
      void entityCollision(Entity& entity, Entity* collidedEntity);

      int getScoreCount() const;

  private:
      const std::vector<Entity>& entities;
      EnergySystem& enesys;
      Map& map;
      int score = 0;
  };
}

#endif //DINOTRACKS_MOVEMENTSYSTEM_HPP
