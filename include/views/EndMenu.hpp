//
// Created by Dan on 12/2/2019.
//

#ifndef DINOTRACKS_ENDMENU_HPP
#define DINOTRACKS_ENDMENU_HPP

#include <SFML/Graphics/Drawable.hpp>

// Forward Declarations
namespace sf { class RenderTarget; }

namespace dt
{
  class EndMenu : public sf::Drawable
  {
  public:
      void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  };
}


#endif //DINOTRACKS_ENDMENU_HPP
