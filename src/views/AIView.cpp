//
// Created by Ben on 12/2/2019
//

#include "views/AIView.hpp"

#include <iostream>

#include "Tags.hpp"

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
	
	void AIView::sendCommands(Logic& logic) const
	{
		
	}
	
	void AIView::updateFrom(const Logic& logic)
	{
		
	}
}
