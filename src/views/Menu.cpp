//
// Created by Dan on 12/2/2019.
//

#include <views/Menu.hpp>

#include "Menu.hpp"

namespace dt
{
  Menu::~Menu()
  {}

  void centerTextHorizontal(sf::Text& text, const sf::Vector2u& dimensions)
  {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   0);
    text.setPosition(sf::Vector2f(dimensions.x/2.0f, text.getPosition().y));
  }
}
