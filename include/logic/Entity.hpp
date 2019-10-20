//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_ENTITY_HPP
#define DINOTRACKS_ENTITY_HPP

#include <unordered_map>
#include "components/ComponentsBase.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"

namespace dt
{
    class Entity
    {
    public:
        void addComponent(ComponentsBase& comp); //add components to entity
        const ComponentsBase& getComponent(const std::string& name) const; //get component specified in parameter
        bool hasComponent(const std::string& name) const; //check if entity has a component
    private:
        std::unordered_map<std::string, ComponentsBase> components; //map that stores the components of an entity
    };
}

#endif //DINOTRACKS_ENTITY_HPP
