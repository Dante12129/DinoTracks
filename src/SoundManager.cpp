//
// Created by Cindy on 12/1/2019.
//

#include <iostream>
#include "SoundManager.hpp"

namespace dt
{
    SoundManager* SoundManager::curSoundManager = nullptr;

    void SoundManager::addToQueue(std::string sound)
    {
        soundQueue.push(sound);
    }

    std::queue<std::string>& SoundManager::getQueue()
    {
        return soundQueue;
    }

    sf::Music& SoundManager::getMusic()
    {
        return curMusic;
    }

    sf::Music& SoundManager::setMusic(std::string soundFile)
    {
        curMusic.openFromFile(soundFile);
    }
}
