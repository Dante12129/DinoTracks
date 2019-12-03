//
// Created by Cindy on 12/1/2019.
//

#ifndef DINOTRACKS_SOUNDMANAGER_HPP
#define DINOTRACKS_SOUNDMANAGER_HPP

#include <queue>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

namespace dt
{
    class SoundManager
    {
    public:
        static SoundManager* curSoundManager;
        void addToQueue(std::string sound);
        std::queue<std::string>& getQueue();
        sf::Music& getMusic();
        sf::Music& setMusic(std::string);

    private:
        std::queue<std::string> soundQueue;
        sf::Music curMusic;

    };
}

#endif //DINOTRACKS_SOUNDMANAGER_HPP
