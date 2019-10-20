//
// Created by Cindy on 10/19/2019.
//

#include "logic/Entity.hpp"
#include "components/ComponentsBase.hpp"
#include "components/Velocity.hpp"

namespace dt
{
    sf::Vector2f dinoVelocity;
    std::string Velocity::getName() const
    {
        return "Velocity";
    }
    sf::Vector2f Velocity::getVectorData() const
    {
        return dinoVelocity;
    }
    void Velocity::setData(const sf::Vector2f velVec)
    {
        dinoVelocity = velVec;
    }
    int Velocity::getIntData() const{}
    void Velocity::setData(int velInt){}
}