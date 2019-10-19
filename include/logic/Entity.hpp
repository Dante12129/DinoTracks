//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_ENTITY_HPP
#define DINOTRACKS_ENTITY_HPP

#include <vector>
#include "components/ComponentsBase.hpp"

namespace dt {
    class Entity {
    private:
        bool alive{true};
//        std::vector<std::unique_ptr<ComponentsBase>> components;

    public:
        void update(float flt)
       /* void draw()
        bool checkAlive() const
        void destroy()*/
    };
}
#endif //DINOTRACKS_ENTITY_HPP
