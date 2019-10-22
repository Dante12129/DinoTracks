//
// Created by Cindy on 10/19/2019.
//

#ifndef DINOTRACKS_POSITION_HPP
#define DINOTRACKS_POSITION_HPP

#include <SFML/System/Vector2.hpp>
#include "components/Component.hpp"

namespace dt
{
    class Position : public Component
    {
    public:
        Position(int x, int y);

        std::string getName() const;
        int getIntData() const;
        const sf::Vector2i& getVectorData() const;
        void setData(const sf::Vector2i& posVec);
        void setData(int posInt);
    private:
        sf::Vector2i dinoPos;
    };
}

#endif //DINOTRACKS_POSITION_HPP
