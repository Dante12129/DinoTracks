//
// Created by Cindy on 11/10/2019.
//

#include "components/Component.hpp"
#include "components/Visual.hpp"
#include "Tags.hpp"

namespace dt
{
    Visual::Visual(std::string str) : vis(str)
    {}

    std::string Visual::getName() const
    {
        return VISUAL;
    }

    const ComponentData& Visual::getData() const
    {
        return dummy;
    }

    void Visual::setData(const ComponentData& data)
    {
        dummy.asInt = data.asInt;
    }

    const std::string& Visual::getString() const
    {
      return vis;
    }

    void Visual::setString(const std::string& string)
    {
      vis = string;
    }
}
