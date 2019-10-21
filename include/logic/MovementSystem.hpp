//
// Created by ywzKe on 2019/10/21.
//

#ifndef DINOTRACKS_MOVEMENTSYSTEM_HPP
#define DINOTRACKS_MOVEMENTSYSTEM_HPP

#include "components/ComponentsBase.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"
#include "Entity.hpp"

namespace dt
{
    class MovementSystem //This system deals with functionality of movement
    {
        public:
            void moveUp(dt::Entity& dino);
            void moveDown(dt::Entity& dino);
            void moveLeft(dt::Entity& dino);
            void moveRight(dt::Entity& dino);
            void stop(dt::Entity& dino);
    };
}

#endif //DINOTRACKS_MOVEMENTSYSTEM_HPP
