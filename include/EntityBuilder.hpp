//
// Created by Dan on 11/3/2019.
//

#ifndef DINOTRACKS_ENTITYBUILDER_HPP
#define DINOTRACKS_ENTITYBUILDER_HPP

#include <Entity.hpp>

namespace dt
{
    class EntityBuilder
    {
    public:
        // Constructors
        EntityBuilder(Entity& entity);

        // Create components on entity
        void addPositionComponent(const sf::Vector2i& pos);
        void addVelocityComponent(const sf::Vector2i& vel);

    private:
        Entity& entity;
    };
}


#endif //DINOTRACKS_ENTITYBUILDER_HPP
