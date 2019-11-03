//
// Created by Cindy on 10/19/2019.
//

#include <SFML/System/Vector2.hpp>
#include "components/Component.hpp"
#include "components/Position.hpp"

namespace dt
{
    Position::Position(int x, int y) : pos(x, y)
    {}

    const ComponentData& Position::getData() const
    {
      return pos;
    }

    void Position::setData(const ComponentData& data)
    {
      pos.asVec2i = data.asVec2i;
    }
}