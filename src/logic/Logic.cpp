//
// Created by Dan on 10/13/2019.
//

#include "logic/Logic.hpp"
#include "logic/Entity.hpp"

namespace dt
{
    Logic::Logic()
    {
      // Create player's components
      auto playerPosition = std::unique_ptr<Position>(new Position(5, 5));
      auto playerVelocity = std::unique_ptr<Velocity>(new Velocity(0, 0));

      // Create player and add components
      Entity player;
      player.addComponent<Position>(playerPosition);
      player.addComponent<Velocity>(playerVelocity);
    }

    void Logic::update(const sf::Time& delta)
    {

    }
}