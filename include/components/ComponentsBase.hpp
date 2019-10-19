//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_COMPONENTSBASE_HPP
#define DINOTRACKS_COMPONENTSBASE_HPP

#include "Entity.hpp"

namespace dt {
    struct ComponentsBase {
        virtual void update() {}
        virtual void draw() {}
        virtual ~ComponentsBase() {}
    };
}
#endif //DINOTRACKS_COMPONENTSBASE_HPP
