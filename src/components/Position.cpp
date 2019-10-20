//
// Created by Cindy on 10/19/2019.
//

#include <SFML/System/Vector2.hpp>
#include "components/ComponentsBase.hpp"
#include "components/Position.hpp"

namespace dt
{
    std::string Position::getName() const
    {
         return "Position";
    }
    sf::Vector2i Position::getVectorData() const
    {
        return dinoPos;
    }
    void Position::setData(const sf::Vector2i& posVec)
    {
        dinoPos = posVec;
    }
    int Position::getIntData() const{}
    void Position::setData(int posInt){}
}