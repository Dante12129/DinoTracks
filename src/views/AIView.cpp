//
// Created by Ben on 12/2/2019
//

#include "views/AIView.hpp"

#include <iostream>

#include <Logic.hpp>
#include <Tags.hpp>

namespace dt
{
	
	AIView::AIView()
	{
		enemyStates.resize(ENEMY_END - ENEMY_START + 1);
		
		for (int i = 0; i < enemyStates.size(); i++)
		{
			enemyStates[i] = false;
		}
	}
	
	void AIView::processEvents(Logic& logic)
	{
		std::vector<sf::Vector2i> entities;
		sf::Vector2i player;
		
		entities = logic.getEntityPositions();
		player = logic.getPlayerPosition();
		
		int xMin = player.x - 5;
		int xMax = player.x + 5;
		int yMin = player.y - 5;
		int yMax = player.y + 5;
		
		for (int i = 0; i < enemyStates.size(); i++)
		{
			if (entities[i + ENEMY_START - 1].x <= xMax && entities[i + ENEMY_START - 1].x >= xMin && entities[i + ENEMY_START - 1].y <= yMax && entities[i + ENEMY_START - 1].y >= yMin)
			{
				enemyStates[i] = true;
				//std::cout << player.x << " " << player.y << " " << entities[i + ENEMY_START].x << " " << entities[i + ENEMY_START].y << std::endl;
				//std::cout << i << ": true" << std::endl;
			}
			else
			{
				enemyStates[i] = false;
				//std::cout << player.x << " " << player.y << " " << entities[i + ENEMY_START].x << " " << entities[i + ENEMY_START].y << std::endl;
				//std::cout << i << ": false" << std::endl;
			}
		}
	}
	
	void AIView::sendCommands(Logic& logic) const
	{
		
	}
	
	void AIView::updateFrom(const Logic& logic)
	{
		
	}
}
