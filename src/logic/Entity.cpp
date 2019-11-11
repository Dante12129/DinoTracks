//
// Created by Cindy on 10/19/2019.
//

#include <stdexcept>
#include <unordered_map>

#include "logic/Entity.hpp"
#include "components/Component.hpp"

namespace dt
{
    const Component& Entity::getComponent(const std::string& name) const
    {
        return *components.at(name);
    }

    Component& Entity::getComponent(const std::string& name)
    {
      return *components.at(name);
    }

    bool Entity::hasComponent(const std::string& name) const
    {
        if(components.find(name) != components.end()) {return true;}
        return false;
    }

    const ComponentData& Entity::getData(const std::string& name) const
    {
      if(hasComponent(name))
      {
        return getComponent(name).getData();
      }
      else
        throw std::runtime_error("Attempt to get data from a component that does not exist for entity.");
    }

    void Entity::setData(const std::string& name, const ComponentData& data)
    {
      if(hasComponent(name))
      {
        getComponent(name).setData(data);
      }
    }

    void Entity::setID(int x) {
        id = x;
    }

    int Entity::getID() {
        return id;
    }
}