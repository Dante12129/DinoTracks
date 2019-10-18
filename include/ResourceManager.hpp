//
// Created by Dan on 10/17/2019.
//

#ifndef DINOTRACKS_RESOURCEMANAGER_HPP
#define DINOTRACKS_RESOURCEMANAGER_HPP

#include <string>
#include <unordered_map>

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace dt
{
    class ResourceManager
    {
    public:
        // Enums
        enum class Type {
            Texture,
            Font,
            SoundBuffer
        };

        // The Global ResourceManager (will be initialized by application)
        static ResourceManager* currentManager;

        // Loading Functions
        void load(dt::ResourceManager::Type type, const std::string& id, const std::string& filename);

        // Retrieval Functions
        // Can't be const if we want the returned resource to be modifiable
        sf::Texture& getTexture(const std::string& id);
        sf::Font& getFont(const std::string& id);
        sf::SoundBuffer& getSoundBuffer(const std::string& id);

    private:
        // Maps of resource identifiers to actual resources
        std::unordered_map<std::string, sf::Texture> textures;
        std::unordered_map<std::string, sf::Font> fonts;
        std::unordered_map<std::string, sf::SoundBuffer> sounds;
    };
}


#endif //DINOTRACKS_RESOURCEMANAGER_HPP
