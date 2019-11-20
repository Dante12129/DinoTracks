
//
// Created by Ben on 10/18/2019.
//

#include <ResourceManager.hpp>
#include "views/UserInterface.hpp"
#include <Logic.hpp>
#include <string>
#include <iostream>

namespace dt
{
	UserInterface::UserInterface()
	{
	}

	UserInterface::UserInterface(sf::Vector2u windowSize)
	{
		uiview.reset(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
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

    // set size according to health percentage
    healthbar.setSize(sf::Vector2f(uidivider.getPosition().x - 20, uiview.getSize().y/35));
    healthbar.setFillColor(sf::Color::Red);
    healthbar.setPosition(10, healthbar.getSize().y);

    // set size according to energy percentage
    energybar.setSize(sf::Vector2f(uidivider.getPosition().x - 20, uiview.getSize().y/35));
    energybar.setFillColor(sf::Color::Yellow);
    energybar.setPosition(10,  3 * energybar.getSize().y);

    meteorcountdown.setString("METEOR HIT IN: ");
    meteorcountdown.setCharacterSize(25);
    meteorcountdown.setFillColor(sf::Color::Black);
    meteorcountdown.setPosition(4 * uiview.getSize().x/5,0);
    
    turns.setCharacterSize(55);
    turns.setFillColor(sf::Color::Black);
    turns.setPosition(13 * uiview.getSize().x/15,35);
	}

	void UserInterface::draw(sf::RenderWindow & window)
	{
		window.setView(uiview);

    meteorcountdown.setFont(ResourceManager::currentManager->getFont("METEOR_FONT"));
    turns.setFont(ResourceManager::currentManager->getFont("METEOR_FONT"));

		window.draw(uibackground);
		window.draw(uidivider);
		window.draw(healthbar);
		window.draw(energybar);
		window.draw(meteorcountdown);
		window.draw(turns);

		window.setView(window.getDefaultView());
	}

    void UserInterface::setTurn(const Logic& logic)
    {
        int rem = logic.getTurn();
        turns.setString(std::to_string(logic.getTurn()));
    }

    // This method adjust energy bar according energy percentage get from logic
    // Currently using 100 as maximum energy
    void UserInterface::setEnergy(const dt::Logic &logic) {
	    int cur_ene = logic.getPlayerEnergy();
	    //std::cout<<cur_ene;
        energybar.setSize(sf::Vector2f((uidivider.getPosition().x - 20)*cur_ene/100, uiview.getSize().y/35));
	}

    // This method adjust health bar according energy percentage get from logic
    // Currently using 100 as maximum health
	void UserInterface::setHealth(const dt::Logic &logic) {
        int cur_hea = logic.getPlayerHealth();
        //std::cout<<cur_hea;
        healthbar.setSize(sf::Vector2f((uidivider.getPosition().x - 20)*cur_hea/100, uiview.getSize().y/35));
	}
}
