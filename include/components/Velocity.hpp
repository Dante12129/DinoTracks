//
// Created by cinde on 10/19/2019.
//

#ifndef DINOTRACKS_VELOCITY_HPP
#define DINOTRACKS_VELOCITY_HPP

#include <SFML/System/Vector2.hpp>
#include "components/Components.hpp"

namespace dt
{
    class Velocity : public Components
    {
    public:
        std::string getName() const;
        int getIntData() const;
        sf::Vector2i getVectorData() const;
        void setData(const sf::Vector2i& velVec);
        void setData(int velInt);
    private:
        sf::Vector2i dinoVelocity;
    };
}

#endif //DINOTRACKS_VELOCITY_HPP
