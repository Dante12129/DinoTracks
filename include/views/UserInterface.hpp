//
// Created by Ben on 10/18/2019.
//

#ifndef DINOTRACKS_USERINTERFACE_HPP
#define DINOTRACKS_USERINTERFACE_HPP

#include <SFML/Graphics.hpp>

namespace dt
{
	//Forward Declarations
	class Logic;
	
    class UserInterface
    {
    public: 
		//Constructors
		UserInterface();
		UserInterface(sf::Vector2u windowSize);

    //Game Loop
    void draw(sf::RenderWindow & window);
    void setTurn(const Logic& logic);
        
    private:
	    sf::View uiview;
	    
	    sf::RectangleShape uibackground;
	    sf::RectangleShape uidivider;
	    sf::RectangleShape healthbar;
	    sf::RectangleShape energybar;

	    sf::Text meteorcountdown;
	    sf::Text turns;

	    std::string remainingTurns;
    };
}


#endif //DINOTRACKS_USERINTERFACE_HPP
