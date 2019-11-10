//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_ENTITY_HPP
#define DINOTRACKS_ENTITY_HPP

#include <unordered_map>
#include <memory>

#include "components/Component.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"
#include "components/Visual.hpp"

namespace dt
{
    class Entity
    {
    public:
        template <class T>
        void addComponent(std::unique_ptr<T>& comp) { //add components to entity
          components.emplace(comp->getName(), std::move(comp));
        }
        const Component& getComponent(const std::string& name) const; //get component specified in parameter
        Component& getComponent(const std::string& name); // non-const version of above
        bool hasComponent(const std::string& name) const; //check if entity has a component

        const ComponentData& getData(const std::string& name) const;
        void setData(const std::string& name, const ComponentData& data);

    private:
        std::unordered_map<std::string, std::unique_ptr<Component>> components; //map that stores the components of an entity
    };
}

#endif //DINOTRACKS_ENTITY_HPP
