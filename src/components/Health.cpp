//
// Created by ywzKe on 2019/11/10.
//

#include "components/Component.hpp"
#include "components/Health.hpp"
#include "Tags.hpp"

namespace dt
{
    Health::Health(int x)
    {
        hea_per.asVec2i.x = x;
        hea_per.asVec2i.y = x;
    }

    std::string Health::getName() const
    {
        return HEALTH;
    }

    const ComponentData& Health::getData() const
    {
        return hea_per;
    }

    void Health::setData(const ComponentData& data)
    {
        hea_per.asVec2i.x = data.asInt;
    }
}
