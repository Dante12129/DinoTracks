//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_COMPONENTSBASE_HPP
#define DINOTRACKS_COMPONENTSBASE_HPP

#include "logic/Entity.hpp"

namespace dt
{
    class Entity;
    struct ComponentsBase {
        Entity* entity{nullptr};
        virtual void update(float flt) {}
        virtual void draw() {}
        virtual ~ComponentsBase() {}
    };
}
#endif //DINOTRACKS_COMPONENTSBASE_HPP
