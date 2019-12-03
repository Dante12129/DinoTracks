//
// Created by dan9c on 12/2/2019.
//

#ifndef DINOTRACKS_MENU_HPP
#define DINOTRACKS_MENU_HPP

#include <SFML/Graphics/Drawable.hpp>

// Forward Declarations
namespace sf { class RenderTarget; }

namespace dt
{
  // Forward Declarations
  class InputManager;

  // Interface for Menus
  class Menu: public sf::Drawable
  {
  public:
      // Destructor
      virtual ~Menu();

      // Input
      virtual void registerActions(InputManager& input) = 0;
      virtual void processEvents(const InputManager& input) = 0;

      // Drawing
      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
  };
}


#endif //DINOTRACKS_MENU_HPP
