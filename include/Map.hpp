//
// Created by Ben on 10/19/2019.
//

#ifndef DINOTRACKS_MAP_HPP
#define DINOTRACKS_MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>

#include "../ResourceManager.hpp"
#include "logic/Logic.hpp"

namespace dt
{
	// Forward Delcarations
    class Logic;
    
    class Map
    {
    public:
    
        void loadMapFromFile(int mapNumber);
        void draw(sf::RenderWindow & window);
        void updateFrom(const Logic& logic);
        int getTile (int x, int y) const;


    private:
        std::vector<int> terrainMap;
        sf::View mapView;
        int curX;
        int curY;
    };
}


#endif //DINOTRACKS_MAP_HPP

