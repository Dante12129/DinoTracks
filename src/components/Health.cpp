//
// Created by ywzKe on 2019/11/10.
//

#include "components/Component.hpp"
#include "components/Health.hpp"

namespace dt
{
    Health::Health(int x)
    {}

    std::string Health::getName() const
    {
        return "Energy";
    }

    const ComponentData& Health::getData() const
    {
        return hea;
    }

    void Health::setData(const ComponentData& data)
    {
        hea.asInt = data.asInt;
    }
}
