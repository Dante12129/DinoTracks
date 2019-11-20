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

namespace dt
{
  class MovementSystem : public System //This system deals with functionality of movement
  {
  public:
    virtual void update(Entity& entity) override;

    void moveUp(dt::Entity& dino, int spd);
    void moveDown(dt::Entity& dino, int spd);
    void moveLeft(dt::Entity& dino, int spd);
    void moveRight(dt::Entity& dino, int spd);
    void stop(dt::Entity& dino);

  private:
      // Component Identifiers
      static const std::string posi_str;
      static const std::string velo_str;
  };
}

#endif //DINOTRACKS_MOVEMENTSYSTEM_HPP
