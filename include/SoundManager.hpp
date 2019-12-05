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

        // Sound effects
        void addToQueue(const std::string& sound);
        std::queue<std::string>& getQueue();

        // Music
        sf::Music& getMusic();
        void setMusic(const std::string& soundFile);
        void playMusic(const std::string& soundFile);

    private:
        std::queue<std::string> soundQueue;
        sf::Music curMusic;
        std::string currentFile;
    };
}

#endif //DINOTRACKS_SOUNDMANAGER_HPP
