//
// Created by Ben on 10/19/2019.
//

#ifndef DINOTRACKS_MAPLOADER_HPP
#define DINOTRACKS_MAPLOADER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>

#include "../ResourceManager.hpp"

namespace dt
{
	// Forward Delcarations
    class Logic;
    
    class MapLoader
    {
    public:
        void loadMapFromFile(int mapNumber);
        void draw(sf::RenderWindow & window);
        void updateFrom(const Logic& logic);


    private:
        std::vector<int> terrainMap;
        int curX;
        int curY;
    };
}


#endif //DINOTRACKS_MAPLOADER_HPP

