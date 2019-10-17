//
// Created by Dan on 10/17/2019.
//

#ifndef DINOTRACKS_RESOURCEMANAGER_HPP
#define DINOTRACKS_RESOURCEMANAGER_HPP

#include <string>
#include <unordered_map>

// Forward Declarations
namespace sf { class Font; class Texture; class SoundBuffer; }

namespace dt
{
    class ResourceManager
    {
        // Enums
        enum class Type {
            Texture,
            Font,
            SoundBuffer
        };

        // Loading Functions
        void load(dt::ResourceManager::Type type, const std::string& id, const std::string& filename);

        // Retrieval Functions
        sf::Texture& getTexture(const std::string& id) const;
        sf::Font& getFont(const std::string& id) const;
        sf::SoundBuffer& getSoundBuffer(const std::string& id) const;

    private:
        // Maps of resource identifiers to actual resources
        std::unordered_map<std::string, sf::Texture> textures;
        std::unordered_map<std::string, sf::Font> fonts;
        std::unordered_map<std::string, sf::SoundBuffer> sounds;
    };
}


#endif //DINOTRACKS_RESOURCEMANAGER_HPP
