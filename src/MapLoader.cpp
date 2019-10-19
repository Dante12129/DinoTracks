
//
// Created by Ben on 10/19/2019.
//

#include "MapLoader.hpp"

namespace dt
{
	
	void MapLoader::loadMapFromFile(int mapNumber)
	{
		std::ifstream mapFile;
		std::string filePath = "../data/maps/" + std::to_string(mapNumber) + ".map";
		mapFile.open(filePath);
		
		int tile;
		while (mapFile >> tile)
		{
			terrainMap.push_back((int) tile);
		}
		
		mapFile.close();
	}
   
}
