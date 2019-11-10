//
// Created by Dan on 11/2/2019.
//

#ifndef DINOTRACKS_COMPONENTDATA_HPP
#define DINOTRACKS_COMPONENTDATA_HPP

#include <SFML/System/Vector2.hpp>
#include <string>

namespace dt
{
    union ComponentData
    {
        ComponentData();
        ComponentData(int val);
        ComponentData(sf::Vector2i vec);
        ComponentData(int x, int y);
        ComponentData(std::string str);
        ~ComponentData();

        int asInt;
        sf::Vector2i asVec2i;
        std::string asString;
    };
}

#endif //DINOTRACKS_COMPONENTDATA_HPP
