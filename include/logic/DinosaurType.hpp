//
// Created by Ben on 11/10/2019.
//

#ifndef DINOTRACKS_DINOSAURTYPE_HPP
#define DINOTRACKS_DINOSAURTYPE_HPP

#include <string>
#include <fstream>

namespace dt
{
    class DinosaurType
    {
		public:
			//public setters for stats
			void setHealth(int health);
			void setSpeed(int speed);
			void setAttack(int speed);
			void setDefense(int defense);
			
			//public getters for stats
			int getHealth();
			int getSpeed();
			int getAttack();
			int getDefense();
			
			//loading dinosaur types
			bool loadFromFile(std::string filePath);
		
		private:
			//integers that represent a dinosaur's stats
			int health;
			int speed;
			int attack;
			int defense;
		
	};
}

#endif //DINOTRACKS_DINOSAURTYPE_HPP
