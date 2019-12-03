
//
// Created by Ben on 10/19/2019.
//

#include "Map.hpp"

#include <Tags.hpp>

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
	
	void Map::updateCenter(int x, int y)
	{
		curX = x * 32 + 11;
		curY = y * 32;
	}

	int Map::getTile(int x, int y) const 
	{
    int tileType = terrainMap[x + (MAP_WIDTH * y)];
    return tileType;
	}

	int Map::getSize() const
  {
	  return terrainMap.size();
  }
}
