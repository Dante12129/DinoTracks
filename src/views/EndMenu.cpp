//
// Created by Dan on 12/2/2019.
//

#include "EndMenu.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <InputManager.hpp>
#include <Tags.hpp>

namespace dt
{
    EndMenu::EndMenu()
    {}

    void EndMenu::registerActions(class dt::InputManager& input)
    {
      // Clear previous state actions
      input.clearActions();

      // Create actions
      thor::Action nextState(sf::Keyboard::Enter);

      // Register actions
      input.associate(nextState, NEXT_STATE);
    }

    void EndMenu::processEvents(const InputManager& input)
    {}

    void EndMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
      sf::RectangleShape rect({300, 300});
      rect.setFillColor(sf::Color::Yellow);
      target.draw(rect, states);
    }
}