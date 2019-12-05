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
#include "HealthSystem.hpp"
#include "SoundManager.hpp"
#include "Visual.hpp"

namespace dt
{
  class MovementSystem : public System //This system deals with functionality of movement
  {
  public:
      MovementSystem(std::vector<Entity>& entities, EnergySystem& enesys, Map& map, HealthSystem& heasys);
      virtual void update(Entity& entity) override;

      void moveUp(dt::Entity& dino, int velocity);
      void moveDown(dt::Entity& dino, int velocity);
      void moveLeft(dt::Entity& dino, int velocity);
      void moveRight(dt::Entity& dino, int velocity);
      void stop(dt::Entity& dino);
      int entityCollision(Entity& entity, Entity* collidedEntity, const sf::Vector2i& velocity, sf::Vector2i& position, std::string dinoType);

      int getScoreCount() const;

      void fight(dt::Entity &player, dt::Entity &enemy);

  private:
      std::vector<Entity>& entities;
      EnergySystem& enesys;
      HealthSystem& heasys;
      Map& map;
      int score = 0;
      bool win = false;
  };
}

#endif //DINOTRACKS_MOVEMENTSYSTEM_HPP
