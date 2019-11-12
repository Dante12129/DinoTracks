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

namespace dt
{
	// Forward Delcarations
    //class Logic;
    
    class Map
    {
    public:
    
        void loadMapFromFile(int mapNumber);
        void updateCenter(int x, int y);
        int getTile (int x, int y) const;
        int getSize() const;

    private:
        std::vector<int> terrainMap;
        int curX;
        int curY;
    };
}


#endif //DINOTRACKS_MAP_HPP

