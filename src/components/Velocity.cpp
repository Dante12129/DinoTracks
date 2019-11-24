//
// Created by Cindy on 10/19/2019.
//

#include <SFML/System/Vector2.hpp>
#include "components/Component.hpp"
#include "components/Velocity.hpp"
#include "Tags.hpp"

namespace dt
{
    Velocity::Velocity(int x, int y) : vel(x, y)
    {}

    Velocity::Velocity(const sf::Vector2i& vec) : vel(vec)
    {}

    std::string Velocity::getName() const
    {
      return VELOCITY;
    }

    const ComponentData& Velocity::getData() const
    {
      return vel;
    }

    void Velocity::setData(const ComponentData& data)
    {
      vel.asVec2i = data.asVec2i;
    }
}