
//
// Created by Ben on 10/18/2019.
//

#include <ResourceManager.hpp>
#include "views/UserInterface.hpp"
#include <Logic.hpp>
#include "Tags.hpp"
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
        uidivider.setPosition(uiview.getSize().x/4, 0);

        // set size according to health percentage
        healthbar.setSize(sf::Vector2f(uidivider.getPosition().x - 100, uiview.getSize().y/35));
        healthbar.setFillColor(sf::Color::Red);
        healthbar.setPosition(10, healthbar.getSize().y);

        // set size according to energy percentage
        energybar.setSize(sf::Vector2f(uidivider.getPosition().x - 100, uiview.getSize().y/35));
        energybar.setFillColor(sf::Color::Yellow);
        energybar.setPosition(10,  3 * energybar.getSize().y);

        // set health text
        heanum.setString("100");
        heanum.setCharacterSize(20);
        heanum.setFillColor(sf::Color::Black);
        heanum.setPosition(uidivider.getPosition().x - 80,healthbar.getSize().y);

        // set energy text
        enenum.setString("100");
        enenum.setCharacterSize(20);
        enenum.setFillColor(sf::Color::Black);
        enenum.setPosition(uidivider.getPosition().x - 80,3 * energybar.getSize().y);

        meteorcountdown.setString("METEOR HIT IN: ");
        meteorcountdown.setCharacterSize(25);
        meteorcountdown.setFillColor(sf::Color::Black);
        meteorcountdown.setPosition(4 * uiview.getSize().x/5,0);

        turns.setCharacterSize(55);
        turns.setFillColor(sf::Color::Black);
        turns.setPosition(13 * uiview.getSize().x/15,35);

        scorecount.setString("EGGS COLLECTED: ");
        scorecount.setCharacterSize(25);
        scorecount.setFillColor(sf::Color::Black);
        scorecount.setPosition(11 * uiview.getSize().x/20,0);

        score.setCharacterSize(55);
        score.setFillColor(sf::Color::Black);
        score.setPosition(63 * uiview.getSize().x/100,35);
	}

	void UserInterface::draw(sf::RenderWindow & window)
	{
		window.setView(uiview);

        meteorcountdown.setFont(ResourceManager::currentManager->getFont(METEOR_FONT));
        turns.setFont(ResourceManager::currentManager->getFont(METEOR_FONT));
        scorecount.setFont(ResourceManager::currentManager->getFont(METEOR_FONT));
        score.setFont(ResourceManager::currentManager->getFont(METEOR_FONT));
        heanum.setFont(ResourceManager::currentManager->getFont(METEOR_FONT));
        enenum.setFont(ResourceManager::currentManager->getFont(METEOR_FONT));

		window.draw(uibackground);
		window.draw(uidivider);
		window.draw(healthbar);
		window.draw(energybar);
		window.draw(meteorcountdown);
		window.draw(turns);
		window.draw(scorecount);
		window.draw(score);
		window.draw(heanum);
		window.draw(enenum);

		window.setView(window.getDefaultView());
	}

    void UserInterface::setTurn(const Logic& logic)
    {
        turns.setString(std::to_string(logic.getTurn()));
    }

    void UserInterface::setScore(const dt::Logic &logic)
    {
        score.setString(std::to_string(logic.getScore()));
    }

    // This method adjust energy bar according energy percentage get from logic
    // Currently using 100 as maximum energy
    void UserInterface::setEnergy(const dt::Logic &logic) {
	    int cur_ene = logic.getPlayerEnergy();
	    //std::cout<<cur_ene;
        energybar.setSize(sf::Vector2f((uidivider.getPosition().x - 100)*cur_ene/100, uiview.getSize().y/35));
        enenum.setString(std::to_string(cur_ene));
	}

    // This method adjust health bar according energy percentage get from logic
	void UserInterface::setHealth(const dt::Logic &logic) {
        int cur_hea = logic.getPlayerHealth();
        int max_hea = logic.getPlayerMaxHealth();
        //std::cout<<cur_hea;
        healthbar.setSize(sf::Vector2f((uidivider.getPosition().x - 100)*cur_hea/max_hea, uiview.getSize().y/35));
        heanum.setString(std::to_string(cur_hea));
	}
}
