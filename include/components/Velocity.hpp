//
// Created by cinde on 10/19/2019.
//

#ifndef DINOTRACKS_VELOCITY_HPP
#define DINOTRACKS_VELOCITY_HPP

#include "components/Component.hpp"

namespace dt
{
    class Velocity : public Component
    {
    public:
        Velocity(int x, int y);
        Velocity(const sf::Vector2i& vec);

        std::string getName() const override;

        const ComponentData& getData() const override;
        void setData(const ComponentData& data) override;

    private:
        ComponentData vel;
    };
}

#endif //DINOTRACKS_VELOCITY_HPP
