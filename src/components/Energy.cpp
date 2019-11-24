//
// Created by ywzKe on 2019/11/10.
//

#include "components/Component.hpp"
#include "components/Energy.hpp"
#include "Tags.hpp"

namespace dt
{
    Energy::Energy(int x) : ene(x)
    {}

    std::string Energy::getName() const
    {
        return ENERGY;
    }

    const ComponentData& Energy::getData() const
    {
        return ene;
    }

    void Energy::setData(const ComponentData& data)
    {
        ene.asInt = data.asInt;
    }
}
