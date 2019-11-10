//
// Created by ywzKe on 2019/11/10.
//

#ifndef DINOTRACKS_FOOD_HPP
#define DINOTRACKS_FOOD_HPP

#include "components/Component.hpp"

namespace dt
{
    class Food : public Component
    {
    public:
        Food(int x);

        std::string getName() const override;

        const ComponentData& getData() const override;
        void setData(const ComponentData& data) override;

    private:
        ComponentData food_ene;
    };
}


#endif //DINOTRACKS_FOOD_HPP
