//
// Created by Dan on 12/2/2019.
//

#ifndef DINOTRACKS_ENDMENU_HPP
#define DINOTRACKS_ENDMENU_HPP

#include <string>

#include <SFML/Graphics/Drawable.hpp>

#include <Menu.hpp>

// Forward Declarations
namespace sf { class RenderTarget; }

namespace dt
{
  // Forward Declarations
  class InputManager;
  class Logic;

  class EndMenu : public Menu
  {
  public:
      // Enums
      enum class Reason {
          Meteor,
          Health,
          Energy,
          Pod,
          None
      };

      // Constructors
      EndMenu(const Logic& logic, Reason reason);

      // Input
      void registerActions(InputManager& input) override;
      void processEvents(const InputManager& input) override;

      // Drawing
      void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  private:
      int finalScore;
      std::string message;
  };
}


#endif //DINOTRACKS_ENDMENU_HPP
