
//
// Created by Ben on 10/18/2019.
//

#include <ResourceManager.hpp>
#include "views/UserInterface.hpp"

namespace dt
{
	UserInterface::UserInterface()
	{
	}
	
	UserInterface::UserInterface(sf::Vector2u windowSize)
	{
		uiview.reset(sf::FloatRect(0, 0, windowSize.x, windowSize.y/5));
        uiview.setViewport(sf::FloatRect(0.f, 0.85f, 1.f, 1.f));
		
		sf::Color background(160, 160, 160);
		sf::Color border(96, 96, 96);
		
        uibackground.setSize(uiview.getSize());
        uibackground.setFillColor(background);
        uibackground.setOutlineColor(border);
        uibackground.setOutlineThickness(2);
        uibackground.setPosition(0, 1);
        
        uidivider.setSize(sf::Vector2f(7, uiview.getSize().y));
        uidivider.setFillColor(border);
        uidivider.setPosition(uiview.getSize().x/5, 0);
        
        healthbar.setSize(sf::Vector2f(uidivider.getPosition().x - 20, uiview.getSize().y/35));
        healthbar.setFillColor(sf::Color::Red);
        healthbar.setPosition(10, 5);
        
        energybar.setSize(sf::Vector2f(uidivider.getPosition().x - 20, uiview.getSize().y/35));
        energybar.setFillColor(sf::Color::Yellow);
        energybar.setPosition(10, 15);

        meteorcountdown.setString("METEOR HIT IN: ");
        meteorcountdown.setCharacterSize(50);
        meteorcountdown.setFillColor(sf::Color::Black);
        meteorcountdown.setPosition(30,15);
	}
	
	void UserInterface::draw(sf::RenderWindow & window)
	{
		window.setView(uiview);

        meteorcountdown.setFont(ResourceManager::currentManager->getFont("METEOR_FONT"));

		window.draw(uibackground);
		window.draw(uidivider);
		window.draw(healthbar);
		window.draw(energybar);
		window.draw(meteorcountdown);

		window.setView(window.getDefaultView());
	}
   
}
