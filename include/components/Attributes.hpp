//
// Created by ywzKe on 2019/12/2.
//

#ifndef DINOTRACKS_ATTRIBUTES_HPP
#define DINOTRACKS_ATTRIBUTES_HPP

#include "components/Component.hpp"

namespace dt
{
    class Attributes : public Component
    {
    public:
        Attributes(int attack, int defense);

        std::string getName() const override;

        const ComponentData& getData() const override;
        void setData(const ComponentData& data) override;

    private:
        ComponentData attributes;
    };
}


#endif //DINOTRACKS_ATTRIBUTES_HPP
