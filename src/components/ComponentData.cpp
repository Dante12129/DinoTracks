//
// Created by Dan on 11/2/2019.
//

#include "ComponentData.hpp"

namespace dt
{
    ComponentData::ComponentData()
    {}

    ComponentData::ComponentData(int val)
    {
      asInt = val;
    }

    ComponentData::ComponentData(sf::Vector2i vec) : ComponentData(vec.x, vec.y)
    {}

    ComponentData::ComponentData(int x, int y) : asVec2i(x, y)
    {}
}
