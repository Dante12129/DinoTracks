//
// Created by Dan on 12/2/2019.
//

#include "StartMenu.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace dt
{
    void StartMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
      sf::RectangleShape rect({300, 300});
      rect.setFillColor(sf::Color::Cyan);
      target.draw(rect, states);
    }
}