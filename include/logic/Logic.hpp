//
// Created by Dan on 10/13/2019.
//

#ifndef DINOTRACKS_LOGIC_HPP
#define DINOTRACKS_LOGIC_HPP

#include "logic/Entity.hpp"

// Forward Declarations
namespace sf { class Time; }

namespace dt
{
    class Logic
    {
    public:
        // Game Loop
        void update(const sf::Time& delta);
    };
}


#endif //DINOTRACKS_LOGIC_HPP
