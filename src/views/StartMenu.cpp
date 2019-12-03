//
// Created by Dan on 12/2/2019.
//

#include "StartMenu.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <InputManager.hpp>

namespace dt
{
    void StartMenu::registerActions(InputManager& input)
    {
      // Clear previous state actions
      input.clearActions();

      // Create actions
      thor::Action nextState(sf::Keyboard::Enter);

      // Register actions
      input.associate(nextState, "NEXT_STATE");
    }

    void StartMenu::processEvents(const InputManager& input)
    {

    }

    void StartMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
      sf::RectangleShape rect({300, 300});
      rect.setFillColor(sf::Color::Cyan);
      target.draw(rect, states);
    }
}