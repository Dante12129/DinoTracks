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
    class MovementSystem
    {
        public:
            void moveUp(Entity dino);
            void moveDown(Entity dino);
            void moveLeft(Entity dino);
            void moveRight(Entity dino);
            void stop(Entity dino);
    };
}

#endif //DINOTRACKS_MOVEMENTSYSTEM_HPP
