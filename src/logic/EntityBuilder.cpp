//
// Created by Dan on 11/3/2019.
//

#include "EntityBuilder.hpp"

#include <components/Position.hpp>
#include <components/Velocity.hpp>
#include <components/Energy.hpp>
#include <components/Health.hpp>
#include <components/Food.hpp>
#include <components/Visual.hpp>
#include <components/Score.hpp>

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

    void EntityBuilder::addEnergyComponent(int ene)
    {
        auto component = std::unique_ptr<Energy>(new Energy(ene));

        entity.addComponent(component);
    }

    void EntityBuilder::addHealthComponent(int hea)
    {
        auto component = std::unique_ptr<Health>(new Health(hea));

        entity.addComponent(component);
    }

    void EntityBuilder::addFoodComponent(int food_ene, int food_hea)
    {
        auto component = std::unique_ptr<Food>(new Food(food_ene, food_hea));

        entity.addComponent(component);
    }

    void EntityBuilder::addVisualComponent(const std::string& vis)
    {
        auto component = std::unique_ptr<Visual>(new Visual(vis));

        entity.addComponent(component);
    }

    void EntityBuilder::addScoreComponent(int sc)
    {
        auto component = std::unique_ptr<Score>(new Score(sc));

        entity.addComponent(component);
    }
}