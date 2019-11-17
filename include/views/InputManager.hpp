//
// Created by Dan on 10/18/2019.
//

#ifndef DINOTRACKS_INPUTMANAGER_HPP
#define DINOTRACKS_INPUTMANAGER_HPP

#include <string>
#include <unordered_map>

#include <SFML/Window/Keyboard.hpp>
#include <Thor/Input/Action.hpp>
#include <Thor/Input/ActionMap.hpp>
#include <Input/EventSystem.hpp>

namespace dt
{
    class InputManager
    {
    public:
        // Constructors
        InputManager();

        // Action Creation
        void associate(const thor::Action& action, const std::string& tag);
        void setWindowCloseCallback(std::function<void()> callback);

        // Game Loop
        void clearEvents();
        void updateAll(sf::Window& window);

        // Action State
        bool isActive(const std::string& tag) const;

    private:
        mutable thor::ActionMap<std::string> map;
        thor::ActionMap<std::string>::CallbackSystem callbacks;
    };
}


#endif //DINOTRACKS_INPUTMANAGER_HPP
