//
// Created by ywzKe on 2019/12/2.
//

#include "components/Attributes.hpp"
#include "components/Component.hpp"
#include "Tags.hpp"

namespace dt
{
    Attributes::Attributes(int attack, int defense){
        attributes.asVec2i.x = attack;
        attributes.asVec2i.y = defense;
    }

    std::string Attributes::getName() const
    {
        return ATTRIBUTES;
    }

    const ComponentData& Attributes::getData() const
    {
        return attributes;
    }

    void Attributes::setData(const ComponentData& data)
    {
        attributes.asVec2i = data.asVec2i;
    }
}