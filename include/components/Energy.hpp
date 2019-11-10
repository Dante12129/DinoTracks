//
// Created by ywzKe on 2019/11/10.
//

#ifndef DINOTRACKS_ENERGY_HPP
#define DINOTRACKS_ENERGY_HPP

#include "components/Component.hpp"

namespace dt
{
    class Energy : public Component
    {
    public:
        Energy(int x);

        std::string getName() const override;

        const ComponentData& getData() const override;
        void setData(const ComponentData& data) override;

    private:
        ComponentData ene;
    };
}



#endif //DINOTRACKS_ENERGY_HPP
