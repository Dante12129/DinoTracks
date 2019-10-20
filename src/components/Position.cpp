//
// Created by Cindy on 10/19/2019.
//

#include "logic/Entity.hpp"
#include "components/Position.hpp"

namespace dt
{
    sf::Vector2f dinoPos;
    std::string Position::getName() const
    {
         return "Position";
    }
    sf::Vector2f Position::getVectorData() const
    {
        return dinoPos;
    }
    void Position::setData(const sf::Vector2f posVec)
    {
        dinoPos = posVec;
    }
    int Position::getIntData() const{}
    void Position::setData(int posInt){};
}