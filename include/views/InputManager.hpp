//
// Created by Dan on 10/18/2019.
//

#ifndef DINOTRACKS_INPUTMANAGER_HPP
#define DINOTRACKS_INPUTMANAGER_HPP

#include <string>
#include <unordered_map>

#include <SFML/Window/Keyboard.hpp>

namespace dt
{
    class InputManager
    {
    public:
        // Action Creation
        void associate(sf::Keyboard::Key key, const std::string& action);

        // Action State
        void activate(sf::Keyboard::Key key);
        void deactivate(sf::Keyboard::Key key);
        bool isActive(const std::string& action) const;
        bool isActiveOnce(const std::string& action) const;

    private:
        std::unordered_map<sf::Keyboard::Key, std::string> keys; // Map actions to keys
        mutable std::unordered_map<std::string, bool> state;
    };
}


#endif //DINOTRACKS_INPUTMANAGER_HPP
