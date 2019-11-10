//
// Created by Dan on 11/3/2019.
//

#include "EntityBuilder.hpp"

namespace dt
{

    EntityBuilder::EntityBuilder(Entity& entity) : entity(entity)
    {}

    void EntityBuilder::addPositionComponent(const sf::Vector2i& pos)
    {
      auto component = std::unique_ptr<Position>(new Position(pos));

      entity.addComponent(component);
    }

    void EntityBuilder::addVelocityComponent(const sf::Vector2i& vel)
    {
      auto component = std::unique_ptr<Velocity>(new Velocity(vel));

      entity.addComponent(component);
    }

    void EntityBuilder::addVisualComponent(const std::string vis)
    {
        auto component = std::unique_ptr<Visual>(new Visual(vis));

        entity.addComponent(component);
    }
}