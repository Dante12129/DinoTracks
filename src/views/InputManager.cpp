//
// Created by Dan on 10/18/2019.
//

#include "InputManager.hpp"

#include <stdexcept>

namespace dt
{
    void InputManager::associate(sf::Keyboard::Key key, const std::string& action)
    {
      keys.insert({key, action});
      state.insert({action, false});
    }

    void InputManager::activate(sf::Keyboard::Key key)
    {
        // Get action associated with key
        auto keyIterator = keys.find(key);
        if(keyIterator == keys.end()) // Key not found (no associated action)
        {
          throw std::runtime_error("No action found for key");
        }
        else // Key is found
        {
          // Set state for action
          state[keyIterator->second] = true;
        }
    }

    void InputManager::deactivate(sf::Keyboard::Key key)
    {
      // Get action associated with key
      auto keyIterator = keys.find(key);
      if(keyIterator == keys.end()) // Key not found (no associated action)
      {
        throw std::runtime_error("No action found for key");
      }
      else // Key is found
      {
        // Set state for action
        state[keyIterator->second] = false;
      }
    }

    bool InputManager::isActive(const std::string& action) const
    {
      // Get action
      auto actionIterator = state.find(action);
      if(actionIterator == state.end()) // Action not found
      {
        throw std::runtime_error("Action not found: " + action);
      }
      else // Action found
      {
        return actionIterator->second;
      }
    }

    bool InputManager::isActiveOnce(const std::string& action) const
    {
      // Get action
      auto actionIterator = state.find(action);
      if(actionIterator == state.end()) // Action not found
      {
        throw std::runtime_error("Action not found: " + action);
      }
      else // Action found
      {
        bool result = actionIterator->second; // Save action state to return
        actionIterator->second = false; // Reset state
        return result;
      }
    }
}
