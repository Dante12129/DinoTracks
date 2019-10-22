//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_COMPONENT_HPP
#define DINOTRACKS_COMPONENT_HPP

#include <string>
#include <SFML/System/Vector2.hpp>

namespace dt
{
    class Component
    {
    public:
        virtual std::string getName() const = 0;
        virtual int getIntData() const = 0;
        virtual const sf::Vector2i& getVectorData() const = 0;
        virtual void setData(const sf::Vector2i&) = 0;
        virtual void setData(int) = 0;
    };
}
#endif //DINOTRACKS_COMPONENT_HPP
