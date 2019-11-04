//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_POSITION_HPP
#define DINOTRACKS_POSITION_HPP

#include "components/Component.hpp"

namespace dt
{
    class Position : public Component
    {
    public:
        Position(int x, int y);
        Position(const sf::Vector2i& vec);

        std::string getName() const override;

        const ComponentData& getData() const override;
        void setData(const ComponentData& data) override;

    private:
        ComponentData pos;
    };
}

#endif //DINOTRACKS_POSITION_HPP
