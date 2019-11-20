//
// Created by ywzKe on 2019/11/10.
//

#ifndef DINOTRACKS_HEALTH_HPP
#define DINOTRACKS_HEALTH_HPP

#include "components/Component.hpp"

namespace dt
{
    class Health : public Component
    {
    public:
        Health(int x);

        std::string getName() const override;

        const ComponentData& getData() const override;
        void setData(const ComponentData& data) override;

    private:
        ComponentData hea;
        ComponentData Max_hea;
    };
}

#endif //DINOTRACKS_HEALTH_HPP
