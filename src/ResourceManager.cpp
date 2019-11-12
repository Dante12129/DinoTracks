//
// Created by Dan on 10/17/2019.
//

#include "ResourceManager.hpp"

#include <stdexcept>

namespace dt
{
    ResourceManager* ResourceManager::currentManager = nullptr;

    void ResourceManager::load(dt::ResourceManager::Type type, const std::string& id, const std::string& filename)
    {
      bool fileResult = false;
      bool insertResult = false;

      // Try loading appropriate resources
      if (type == Type::Texture)
      {
        sf::Texture tex;
        fileResult = tex.loadFromFile("../resources/textures/" + filename);
        insertResult = textures.insert({id, tex}).second;
      }
      else if (type == Type::Font)
      {
        sf::Font font;
        fileResult = font.loadFromFile("../resources/fonts/" + filename);
        insertResult = fonts.insert({id, font}).second;
      }
      else if (type == Type::SoundBuffer)
      {
        sf::SoundBuffer sbuf;
        fileResult = sbuf.loadFromFile("../resources/sounds/" + filename);
        insertResult = sounds.insert({id, sbuf}).second;
      }
      else if (type == Type::DinosaurType)
      {
        DinosaurType dtype;
        fileResult = dtype.loadFromFile("../resources/dinosaurs/" + filename);
        insertResult = dinosaurs.insert({id, dtype}).second;
	  }

      if (!fileResult)
      {
        throw std::runtime_error("Could not resource file: " + filename);
      }
      if (!insertResult)
      {
        throw std::runtime_error("Could not save resource: " + filename);
      }
    }

    sf::Texture& ResourceManager::getTexture(const std::string& id)
    {
      return textures.at(id);
    }

    sf::Font& ResourceManager::getFont(const std::string& id)
    {
      return fonts.at(id);
    }

    sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& id)
    {
      return sounds.at(id);
    }
    
    DinosaurType& ResourceManager::getDinosaurType(const std::string& id)
    {
		  return dinosaurs.at(id);
	  }
}
