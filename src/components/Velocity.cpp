//
// Created by Cindy on 10/19/2019.
//

#include <SFML/System/Vector2.hpp>
#include "components/ComponentsBase.hpp"
#include "components/Velocity.hpp"

namespace dt
{
    std::string Velocity::getName() const
    {
        return "Velocity";
    }
    sf::Vector2i Velocity::getVectorData() const
    {
        return dinoVelocity;
    }
    void Velocity::setData(const sf::Vector2i& velVec)
    {
        dinoVelocity = velVec;
    }
    int Velocity::getIntData() const{}
    void Velocity::setData(int velInt){}
}