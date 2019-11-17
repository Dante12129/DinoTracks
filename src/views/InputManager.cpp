//
// Created by Dan on 10/18/2019.
//

#include "InputManager.hpp"

#include <stdexcept>

namespace dt
{
    InputManager::InputManager()
    {
      map["EXIT"] = thor::Action(sf::Event::Closed);
    }

    void InputManager::associate(const thor::Action& action, const std::string& tag)
    {
      map[tag] = action;
    }

    void InputManager::setWindowCloseCallback(std::function<void()> callback)
    {
      callbacks.connect0("EXIT", callback);
    }

    void InputManager::clearEvents()
    {
      map.clearEvents();
    }

    void InputManager::updateAll(sf::Window& window)
    {
      map.update(window);
      map.invokeCallbacks(callbacks, &window);
    }

    bool InputManager::isActive(const std::string& tag) const
    {
      bool result = map.isActive(tag);
      return result;
    }
}
