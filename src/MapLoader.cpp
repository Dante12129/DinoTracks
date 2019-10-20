
//
// Created by Ben on 10/19/2019.
//

#include "MapLoader.hpp"

namespace dt
{
	
	void MapLoader::loadMapFromFile(int mapNumber)
	{
		std::ifstream mapFile;
		std::string filePath = "../resources/maps/" + std::to_string(mapNumber) + ".map";
		mapFile.open(filePath);
		
		int tile;
		while (mapFile >> tile)
		{
			terrainMap.push_back((int) tile);
		}
		
		mapFile.close();
	}
	
	void MapLoader::draw(sf::RenderWindow & window)
	{
		sf::Sprite grass;
		grass.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
		grass.setTextureRect(sf::IntRect(32, 64, 32, 32));
		
		sf::Sprite water;
		water.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
		water.setTextureRect(sf::IntRect(96, 672, 32, 32));
		
		int posX = 0;
		int posY = 0;
		
		for (int r = curY; r < curY + 24; ++r)
		{
			for (int c = curX; c < curX + 43; ++c)
			{
				switch (terrainMap[c + (48 * r)])
				{
					case 0:
						water.setPosition(sf::Vector2f(posX, posY));
						window.draw(water);
						break;
					case 1:
						grass.setPosition(sf::Vector2f(posX, posY));
						window.draw(grass);
						break;
				}
				
				posX += 32;
			}
			
			posX = 0;
			posY += 32;
		}
		
	}
	
	void MapLoader::updateFrom(const Logic& logic)
	{
		curX = 0;
		curY = 0;
	}
   
}
