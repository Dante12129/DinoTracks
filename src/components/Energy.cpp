//
// Created by ywzKe on 2019/11/10.
//

#include "components/Component.hpp"
#include "components/Energy.hpp"

namespace dt
{
    Energy::Energy(int x) : ene(x)
    {}

    std::string Energy::getName() const
    {
        return "Energy";
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
