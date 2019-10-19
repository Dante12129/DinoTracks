//
// Created by Cindy on 10/19/2019.
//

#include <vector>
#include "logic\Entity.hpp"

namespace dt
{
    void Entity::update()
    {

    }
    void Entity::draw()
    {

    }
    bool Entity::checkAlive() const
    {
        return alive;
    }
    void Entity::destroy()
    {
        alive = false;
    }
}