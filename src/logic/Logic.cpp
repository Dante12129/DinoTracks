//
// Created by Dan on 10/13/2019.
//

#include <SFML/System/Time.hpp>

#include <Logic.hpp>
#include <Entity.hpp>
#include <EntityBuilder.hpp>

#include <iostream>

namespace dt
{
    Logic::Logic()
    {
      // Resize vector and assign Entity IDs based on position
      entities.resize(1);
      Entity player;
      entities[0] = std::move(player);
      // Generate random coordinates

      // Create player
      EntityBuilder playerBuilder(entities[0]); // Change to entities[0] when vector has pre-set size
      playerBuilder.addPositionComponent({5, 5}); // Replace with random coordinates
      playerBuilder.addVelocityComponent({0, 0});

      // Create escape pod

      // Assign types and coordinates to enemies

      // Add player to entities
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