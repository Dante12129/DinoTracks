//
// Created by Dan on 11/2/2019.
//

#ifndef DINOTRACKS_COMPONENTDATA_HPP
#define DINOTRACKS_COMPONENTDATA_HPP

#include <SFML/System/Vector2.hpp>

namespace dt
{
    union ComponentData
    {
        ComponentData();
        ComponentData(int val);
        ComponentData(int x, int y);

        int asInt;
        sf::Vector2i asVec2i;
    };
}

#endif //DINOTRACKS_COMPONENTDATA_HPP
