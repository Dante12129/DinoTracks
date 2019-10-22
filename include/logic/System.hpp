//
// Created by dan9c on 10/22/2019.
//

#ifndef DINOTRACKS_SYSTEM_HPP
#define DINOTRACKS_SYSTEM_HPP

#include <vector>

#include <Entity.hpp>

// Forward Declarations
namespace sf { class Time; }

namespace dt
{
  class System
  {
      virtual void update(const sf::Time& delta, std::vector<Entity>& entities) = 0;
  };
}

#endif //DINOTRACKS_SYSTEM_HPP
