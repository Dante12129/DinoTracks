//
// Created by Dan on 10/17/2019.
//

#include "ResourceManager.hpp"

#include <stdexcept>

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

void dt::ResourceManager::load(dt::ResourceManager::Type type, const std::string& id, const std::string& filename)
{
  bool fileResult = false;
  bool insertResult = false;

  // Try loading appropriate resources
  if(type == Type::Texture)
  {
    sf::Texture tex;
    fileResult = tex.loadFromFile("resources/textures/" + filename);
    insertResult = textures.insert(tex).second;
  }
  else if(type == Type::Font)
  {
    sf::Font font;
    fileResult = font.loadFromFile("resources/fonts/" + filename);
    insertResult = fonts.insert(font).second;
  }
  else if(type == Type::SoundBuffer)
  {
    sf::SoundBuffer sbuf;
    fileResult = sbuf.loadFromFile("resources/sounds/" + filename);
    insertResult = sounds.insert(sbuf).second;
  }

  if(!fileResult)
  {
    throw std::runtime_error("Could not resource file: " + filename);
  }
  if(!insertResult)
  {
    throw std::runtime_error("Could not save resource: " + filename);
  }
}

sf::Texture& dt::ResourceManager::getTexture(const std::string& id) const
{
  return textures.at(id);
}

sf::Font& dt::ResourceManager::getFont(const std::string& id) const
{
  return fonts.at(id);
}

sf::SoundBuffer& dt::ResourceManager::getSoundBuffer(const std::string& id) const
{
  return sounds.at(id);
}
