//
// Created by Cindy on 10/19/2019.
//

#include <unordered_map>
#include "logic/Entity.hpp"
#include "components/ComponentsBase.hpp"

namespace dt
{
    const ComponentsBase& Entity::getComponent(const std::string& name) const
    {
        return *components.at(name);
    }
    bool Entity::hasComponent(const std::string& name) const
    {
        if(components.find(name) != components.end()) {return true;}
    }

}