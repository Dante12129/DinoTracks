//
// Created by Cindy on 11/10/2019.
//

#include "components/Component.hpp"
#include "components/Visual.hpp"

namespace dt
{
    Visual::Visual(std::string str)
    {}

    std::string Visual::getName() const
    {
        return "Visual";
    }

    const ComponentData& Visual::getData() const
    {
        return vis;
    }

    void Visual::setData(const ComponentData& data)
    {
        vis.asString = data.asString;
    }
}
