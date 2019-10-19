//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_COMPONENT_HPP
#define DINOTRACKS_COMPONENT_HPP

#include "Entity.hpp"

namespace dt {
    struct Component {
        virtual void update() {}
        virtual void draw() {}
        virtual ~Component() {}
    };
}
#endif //DINOTRACKS_COMPONENT_HPP
