//
// Created by Dan on 12/2/2019.
//

#ifndef DINOTRACKS_STARTMENU_HPP
#define DINOTRACKS_STARTMENU_HPP

#include <SFML/Graphics/Drawable.hpp>

#include <Menu.hpp>

// Forward Declarations
namespace sf { class RenderTarget; }

namespace dt
{
  // Forward Declarations
  class InputManager;

  class StartMenu : public Menu
  {
  public:
      // Constructors
      explicit StartMenu();

      // Input
      void registerActions(InputManager& input) override;
      void processEvents(const InputManager& input) override;

      // Drawing
      void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  };
}


#endif //DINOTRACKS_STARTMENU_HPP
