//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_COMPONENT_HPP
#define DINOTRACKS_COMPONENT_HPP

#include <string>
#include <SFML/System/Vector2.hpp>

#include <ComponentData.hpp>

namespace dt
{
    class Component
    {
    public:
        virtual std::string getName() const = 0;

        virtual const ComponentData& getData() const = 0;
        virtual void setData(const ComponentData& data) = 0;
    };
}
#endif //DINOTRACKS_COMPONENT_HPP
