//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_COMPONENTSBASE_HPP
#define DINOTRACKS_COMPONENTSBASE_HPP

#include <string>
#include <SFML/System/Vector2.hpp>

namespace dt
{
    class ComponentsBase
    {
    public:
        virtual std::string getName() const = 0;
        virtual int getIntData() const = 0;
        virtual sf::Vector2i getVectorData() const = 0;
        virtual void setData(const sf::Vector2i&) = 0;
        virtual void setData(int) = 0;
    };
}
#endif //DINOTRACKS_COMPONENTSBASE_HPP
