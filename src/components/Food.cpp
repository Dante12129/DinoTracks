//
// Created by ywzKe on 2019/11/10.
//

#include "components/Component.hpp"
#include "components/Food.hpp"
#include "Tags.hpp"

namespace dt
{
    Food::Food(int x) : food_ene(x)
    {}

    std::string Food::getName() const
    {
        return FOOD;
    }

    const ComponentData& Food::getData() const
    {
        return food_ene;
    }

    void Food::setData(const ComponentData& data)
    {
        food_ene.asInt = data.asInt;
    }
}
