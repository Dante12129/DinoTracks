//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_ENTITY_HPP
#define DINOTRACKS_ENTITY_HPP

#include <vector>
#include "Component.hpp"

namespace dt {
    class Entity {
    private:
        bool alive{true};
        std::vector<std::unique_ptr<Component>> components;
    public:
        void update()
        void draw()
        bool checkAlive() const
        void destroy()
    };
}
#endif //DINOTRACKS_ENTITY_HPP
