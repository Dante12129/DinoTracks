
//
// Created by Ben on 10/19/2019.
//

#include "Map.hpp"

namespace dt
{
	
	void Map::loadMapFromFile(int mapNumber)
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
	
	void Map::draw(sf::RenderWindow & window)
	{
		sf::Sprite grass;
		grass.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
		grass.setTextureRect(sf::IntRect(0, 0, 32, 32));
		
		sf::Sprite water;
		water.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
		water.setTextureRect(sf::IntRect(32, 0, 32, 32));
		
		sf::Sprite grassEdgeBottomLeft;
		grassEdgeBottomLeft.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
		grassEdgeBottomLeft.setTextureRect(sf::IntRect(64, 32, 32, 32));
		
		sf::Sprite grassEdgeBottomRight;
		grassEdgeBottomRight.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
		grassEdgeBottomRight.setTextureRect(sf::IntRect(64, 0, 32, 32));
		
		sf::Sprite grassEdgeTopLeft;
		grassEdgeTopLeft.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
		grassEdgeTopLeft.setTextureRect(sf::IntRect(0, 32, 32, 32));
		
		sf::Sprite grassEdgeTopRight;
		grassEdgeTopRight.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
		grassEdgeTopRight.setTextureRect(sf::IntRect(32, 32, 32, 32));
		
		sf::Sprite mountain;
		mountain.setTexture(ResourceManager::currentManager->getTexture("TERRAIN"));
		mountain.setTextureRect(sf::IntRect(0, 64, 32, 32));
		
		mapView.setCenter(sf::Vector2f(curX, curY));
        mapView.setSize(sf::Vector2f(1366, 768));
		
		window.setView(mapView);
		
		int posX = 0;
		int posY = 0;
		
		for (int r = 0; r < 66; ++r)
		{
			for (int c = 0; c < 96; ++c)
			{
				switch (terrainMap[c + (96 * r)])
				{
					case 0:
						water.setPosition(sf::Vector2f(posX, posY));
						window.draw(water);
						break;
					case 1:
						grass.setPosition(sf::Vector2f(posX, posY));
						window.draw(grass);
						break;
					case 2:
						grassEdgeBottomLeft.setPosition(sf::Vector2f(posX, posY));
						window.draw(grassEdgeBottomLeft);
						break;
					case 3:
						grassEdgeBottomRight.setPosition(sf::Vector2f(posX, posY));
						window.draw(grassEdgeBottomRight);
						break;
					case 4:
						grassEdgeTopRight.setPosition(sf::Vector2f(posX, posY));
						window.draw(grassEdgeTopRight);
						break;
					case 5:
						grassEdgeTopLeft.setPosition(sf::Vector2f(posX, posY));
						window.draw(grassEdgeTopLeft);
						break;
					case 6:
						mountain.setPosition(sf::Vector2f(posX, posY));
						window.draw(mountain);
				}
				
				posX += 32;
			}
			
			posX = 0;
			posY += 32;
		}
		
		window.setView(window.getDefaultView());
		
	}
	
	void Map::updateFrom(const Logic& logic)
	{
		curX = logic.getPlayerPosition().x * 32;
		curY = logic.getPlayerPosition().y * 32;
	}
   
}
