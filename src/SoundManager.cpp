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

    void SoundManager::setMusic(const std::string& soundFile)
    {
        curMusic.openFromFile("../resources/sounds/" + soundFile);
        currentFile = soundFile;
    }

    void SoundManager::playMusic(const std::string& soundFile)
    {
      if (soundFile != currentFile)
      {
        setMusic(soundFile);
        curMusic.play();
        curMusic.setLoop(true);
        curMusic.setVolume(40);
      }
    }
}
