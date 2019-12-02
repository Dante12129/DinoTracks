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
	
	void AIView::updateFrom(const Logic& logic)
	{
		std::vector<sf::Vector2i> entities;
		sf::Vector2i player;
		
		entities = logic.getEntityPositions();
		player = logic.getPlayerPosition();
		
		int xMin = player.x - 7;
		int xMax = player.x + 7;
		int yMin = player.y - 7;
		int yMax = player.y + 7;
		
		for (int i = 0; i < enemyStates.size(); i++)
		{
			if (entities[i + ENEMY_START - 1].x <= xMax && entities[i + ENEMY_START - 1].x >= xMin && entities[i + ENEMY_START - 1].y <= yMax && entities[i + ENEMY_START - 1].y >= yMin)
			{
				enemyStates[i] = true;
				//std::cout << player.x << " " << player.y << " " << entities[i + ENEMY_START - 1].x << " " << entities[i + ENEMY_START - 1].y << std::endl;
				//std::cout << i << ": true" << std::endl;
			}
			else
			{
				enemyStates[i] = false;
				//std::cout << player.x << " " << player.y << " " << entities[i + ENEMY_START - 1].x << " " << entities[i + ENEMY_START - 1].y << std::endl;
				//std::cout << i << ": false" << std::endl;
			}
		}
	}
	
	void AIView::sendCommands(Logic& logic) const
	{
		std::vector<sf::Vector2i> entities;
		sf::Vector2i player;
		
		entities = logic.getEntityPositions();
		player = logic.getPlayerPosition();
		
		std::cout << entities.size() << std::endl;
		
		for (int i = 0; i < enemyStates.size(); i++)
		{
			std::cout << i + ENEMY_START - 1 << std::endl;
			if (enemyStates[i] == true)
			{
				if (entities[i + ENEMY_START - 1].x < player.x)
				{
					logic.moveEnemy(i + ENEMY_START - 1, Direction::Right);
				}
				if (entities[i + ENEMY_START - 1].x > player.x)
				{
					logic.moveEnemy(i + ENEMY_START - 1, Direction::Left);
				}
				if (entities[i + ENEMY_START - 1].y < player.y)
				{
					logic.moveEnemy(i + ENEMY_START - 1, Direction::Down);
				}
				if (entities[i + ENEMY_START - 1].y < player.y)
				{
					logic.moveEnemy(i + ENEMY_START - 1, Direction::Up);
				}
			}
		}
	}

}
