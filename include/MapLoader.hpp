//
// Created by Ben on 10/19/2019.
//

#ifndef DINOTRACKS_MAPLOADER_HPP
#define DINOTRACKS_MAPLOADER_HPP

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

namespace dt
{
    class MapLoader
    {
    public:
        void loadMapFromFile(int mapNumber);


    private:
        std::vector<int> terrainMap;
    };
}


#endif //DINOTRACKS_HUMANVIEW_HPP

