//
// Created by Dan on 10/13/2019.
//

#ifndef DINOTRACKS_LOGIC_HPP
#define DINOTRACKS_LOGIC_HPP

#include <vector>

#include "logic/Entity.hpp"

// Forward Declarations
namespace sf { class Time; }

namespace dt
{
    class Logic
    {
    public:
        // Constructors
        Logic();

        // Game Loop
        void update(const sf::Time& delta);

    private:
        std::vector<Entity> entities;
    };
}


#endif //DINOTRACKS_LOGIC_HPP
