//
// Created by cinde on 10/19/2019.
//

#ifndef DINOTRACKS_VELOCITY_HPP
#define DINOTRACKS_VELOCITY_HPP

#include "logic/Entity.hpp"
#include "components/ComponentsBase.hpp"

namespace dt
{
    class Velocity : ComponentsBase
    {
    public:
        virtual std::string getName() const = 0;
        virtual int getIntData() const = 0;
        virtual sf::Vector2f getVectorData() const = 0;
        virtual void setData(const sf::Vector2f velVec) = 0;
        virtual void setData(int velInt) = 0;
    };
}

#endif //DINOTRACKS_VELOCITY_HPP
