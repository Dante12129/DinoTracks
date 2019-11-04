//
// Created by Dan on 10/13/2019.
//

#include <SFML/System/Time.hpp>
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

      // Add player to entities
      entities.push_back(std::move(player));
    }

    void Logic::update(const sf::Time& delta)
    {
      if(actionPerformed)
      {
        doTurn();
        actionPerformed = false;
      }
    }

    void Logic::doTurn() {
      // Go through each entity and update it with systems
      for(Entity& entity : entities)
      {
        movement.update(entity);
      }

      // Stop player
      movement.stop(entities[0]);
    }

    void Logic::movePlayer(Direction dir)
    {
      switch (dir)
      {
        case Direction::Up:
          movement.moveUp(entities[0]);
          break;
        case Direction::Down:
          movement.moveDown(entities[0]);
          break;
        case Direction::Left:
          movement.moveLeft(entities[0]);
          break;
        case Direction::Right:
          movement.moveRight(entities[0]);
          break;
        case Direction::None:
          movement.stop(entities[0]);
          break;
      }

      actionPerformed = true;
    }

    const sf::Vector2i& Logic::getPlayerPosition() const
    {
      return entities[0].getComponent("Position").getData().asVec2i;
    }
}