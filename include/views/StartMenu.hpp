//
// Created by dan9c on 12/2/2019.
//

#ifndef DINOTRACKS_STARTMENU_HPP
#define DINOTRACKS_STARTMENU_HPP

#include <SFML/Graphics/Drawable.hpp>

#include <InputManager.hpp>
#include <Menu.hpp>

// Forward Declarations
namespace sf { class RenderTarget; }

namespace dt
{
  class StartMenu : public Menu
  {
  public:
      // Input
      void registerActions(InputManager& input) override;

      // Drawing
      void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  };
}


#endif //DINOTRACKS_STARTMENU_HPP
