//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_POSITION_HPP
#define DINOTRACKS_POSITION_HPP

#include <SFML/System/Vector2.hpp>
#include "components/ComponentsBase.hpp"

namespace dt
{
    class Position : ComponentsBase
    {
    public:
        virtual std::string getName() const = 0;
        virtual int getIntData() const = 0;
        virtual sf::Vector2f getVectorData() const = 0;
        virtual void setData(const sf::Vector2f posVec) = 0;
        virtual void setData(int posInt) = 0;
    };
}

#endif //DINOTRACKS_POSITION_HPP
