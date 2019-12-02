//
// Created by dan9c on 12/2/2019.
//

#include "EndMenu.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace dt
{
    void EndMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
      sf::RectangleShape rect({300, 300});
      rect.setFillColor(sf::Color::Yellow);
      target.draw(rect, states);
    }
}