//
// Created by Cindy on 11/20/2019.
//

#ifndef DINOTRACKS_TAGS_HPP
#define DINOTRACKS_TAGS_HPP

#include <string>

namespace dt
{
//    Key input
    const std::string RUN_UP = "RUN_UP";
    const std::string RUN_DOWN = "RUN_DOWN";
    const std::string RUN_LEFT = "RUN_LEFT";
    const std::string RUN_RIGHT = "RUN_RIGHT";
    const std::string WALK_UP = "WALK_UP";
    const std::string WALK_DOWN = "WALK_DOWN";
    const std::string WALK_LEFT = "WALK_LEFT";
    const std::string WALK_RIGHT = "WALK_RIGHT";

// Combined input
    const std::string NEXT_STATE = "NEXT_STATE";

//    Resources
    const std::string TERRAIN = "TERRAIN";
    const std::string TREX_TEX = "TREX_TEX";
    const std::string STEGO_TEX = "STEGO_TEX";
    const std::string METEOR_FONT = "METEOR_FONT";
    const std::string EGG = "EGG";
    const std::string ESCAPE_TEX = "ESCAPE_TEX";
    const std::string MEAT = "MEAT";
    const std::string TREE = "TREE";

//    Dinosaurs
    const std::string STEGOSAURUS = "STEGOSAURUS";
    const std::string TYRANNOSAURUS = "TYRANNOSAURUS";
    const std::string VELOCIRAPTOR = "VELOCIRAPTOR";
    const std::string SPINOSAURUS = "SPINOSAURUS";
    const std::string ALLOSAURUS = "ALLOSAURUS";
    const std::string PACHYCEPHALOSAURUS = "PACHYCEPHALOSAURUS";
    const std::string PROTOCERATOPS = "PROTOCERATOPS";
    const std::string PARASAUROLOPHUS = "PARASAUROLOPHUS";


//    Components
    const std::string POSITION = "Position";
    const std::string VELOCITY = "Velocity";
    const std::string HEALTH = "Health";
    const std::string ENERGY = "Energy";
    const std::string FOOD = "Food";
    const std::string VISUAL = "Visual";
    const std::string SCORE = "Score";

//    Tiles
    const int WATER = 0;
    const int GRASS = 1;
    const int GRASS_BOTTOM_LEFT = 2;
    const int GRASS_BOTTOM_RIGHT = 3;
    const int GRASS_TOP_RIGHT = 4;
    const int GRASS_TOP_LEFT = 5;
    const int MOUNTAIN = 6;

//    Entity ranges

    const int PLAYER = 0;
    const int ESCAPE_POD = 1;
    const int ENEMY_START = 2;
    const int ENEMY_END = 9;
    const int FOOD_HERB_START = 10;
    const int FOOD_HERB_END = 19;
    const int FOOD_CARN_START = 20;
    const int FOOD_CARN_END = 24;
    const int EGG_START = 25;
    const int EGG_END = 34;

//    Sounds and music

}


#endif //DINOTRACKS_TAGS_HPP
