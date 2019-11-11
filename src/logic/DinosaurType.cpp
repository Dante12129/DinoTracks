//
// Created by Ben on 11/10/2019.
//

#include "DinosaurType.hpp"

namespace dt
{
	bool DinosaurType::loadFromFile(std::string filePath)
	{
		std::ifstream dinosaurFile;
		dinosaurFile.open(filePath);
		
		if (!dinosaurFile.is_open())
		{
			return false;
		}
		
		int stat;
		
		for (int i = 0; i < 4; ++i)
		{
			dinosaurFile >> stat;
			
			switch(i)
			{
				case 0:
					this->health = stat;
					break;
				case 1:
					this->speed = stat;
					break;
				case 2:
					this->attack = stat;
					break;
				case 3:
					this->defense = stat;
					break;
			}
		}
		
		dinosaurFile.close();
		
		return true;
	}
	
    void DinosaurType::setHealth(int health)
    {
		this->health = health;
	}
	
	void DinosaurType::setSpeed(int speed)
    {
		this->speed = speed;
	}
	
	void DinosaurType::setAttack(int attack)
    {
		this->attack = attack;
	}
	
	void DinosaurType::setDefense(int defense)
    {
		this->defense = defense;
	}
	
	int DinosaurType::getHealth()
    {
		return health;
	}
	
	int DinosaurType::getSpeed()
    {
		return speed;
	}
	
	int DinosaurType::getAttack()
    {
		return attack;
	}
	
	int DinosaurType::getDefense()
    {
		return defense;
	}
}

