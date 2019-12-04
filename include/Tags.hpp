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
    const std::string CHOOSE_UP = "CHOOSE_UP";
    const std::string CHOOSE_DOWN = "CHOOSE_DOWN";
    const std::string CHOOSE_LEFT = "CHOOSE_LEFT";
    const std::string CHOOSE_RIGHT = "CHOOSE_RIGHT";

//    Resources
    const std::string TERRAIN = "TERRAIN";
    const std::string MAIN_FONT = "MAIN_FONT";
    const std::string EGG = "EGG";
    const std::string ESCAPE_TEX = "ESCAPE_TEX";
    const std::string MEAT = "MEAT";
    const std::string FRUIT = "FRUIT";
    const std::string BACKGROUND_START = "BACKGROUND_START";
    const std::string BACKGROUND_END = "BACKGROUND_END";

//    Dinosaurs
    const std::string STEGOSAURUS = "STEGOSAURUS";
    const std::string TYRANNOSAURUS = "TYRANNOSAURUS";
    const std::string VELOCIRAPTOR = "VELOCIRAPTOR";
    const std::string SPINOSAURUS = "SPINOSAURUS";
    const std::string ALLOSAURUS = "ALLOSAURUS";
    const std::string PACHYCEPHALOSAURUS = "PACHYCEPHALOSAURUS";
    const std::string PROTOCERATOPS = "PROTOCERATOPS";
    const std::string PARASAUROLOPHUS = "PARASAUROLOPHUS";
    const int NUM_TYPES = 8; 


//    Components
    const std::string POSITION = "Position";
    const std::string VELOCITY = "Velocity";
    const std::string HEALTH = "Health";
    const std::string ENERGY = "Energy";
    const std::string FOOD = "Food";
    const std::string VISUAL = "Visual";
    const std::string SCORE = "Score";
    const std::string ATTRIBUTES = "Attributes";

//    Tiles
    const int WATER = 0;
    const int GRASS = 1;
    const int GRASS_BOTTOM_LEFT = 2;
    const int GRASS_BOTTOM_RIGHT = 3;
    const int GRASS_TOP_RIGHT = 4;
    const int GRASS_TOP_LEFT = 5;
    const int MOUNTAIN = 6;
    const int FOREST = 7;
    
//    Map
	  const int MAP_HEIGHT = 150;
	  const int MAP_WIDTH = 153;

//    Entity ranges
    const int MAX_ENTITIES = 57;
    const int PLAYER = 0;
    const int ESCAPE_POD = 1;
    const int ENEMY_START = 2;
    const int ENEMY_END = 16;
    const int FOOD_HERB_START = 17;
    const int FOOD_HERB_END = 31;
    const int FOOD_CARN_START = 32;
    const int FOOD_CARN_END = 36;
    const int EGG_START = 37;
    const int EGG_END = 56;

//    Sounds and music
    const std::string SOUND_WIN = "SOUND_WIN";
    const std::string SOUND_LOSE = "SOUND_LOSE";
    const std::string SOUND_EAT_HERB = "SOUND_EAT_HERB";
    const std::string SOUND_EAT_CARN = "SOUND_EAT_CARN";
    const std::string SOUND_COMBAT = "SOUND_COMBAT";
    const std::string SOUND_TER_COLLISION = "SOUND_TER_COLLISION";
    const std::string MUSIC_COMBAT = "combat_song.wav";
    const std::string MUSIC_GAMEPLAY = "gameplay_song.wav";
    const std::string MUSIC_LOSE = "lose_song.wav";
    const std::string MUSIC_WIN = "win_song.wav";
    const std::string MUSIC_MENU = "menu_song.wav";

//    Other
    const int MAX_ENERGY = 150;
}


#endif //DINOTRACKS_TAGS_HPP
