//
// Created by ywzKe on 2019/11/10.
//

#include "components/Component.hpp"
#include "components/Food.hpp"
#include "Tags.hpp"

namespace dt
{
    Food::Food(int x, int y){
        food_enehea.asVec2i.x = x;
        food_enehea.asVec2i.y = y;
    }

    std::string Food::getName() const
    {
        return FOOD;
    }

    const ComponentData& Food::getData() const
    {
        return food_enehea;
    }

    void Food::setData(const ComponentData& data)
    {
        food_enehea.asVec2i = data.asVec2i;
    }
}
