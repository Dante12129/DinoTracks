//
// Created by Dan on 10/17/2019.
//

#ifndef DINOTRACKS_RESOURCEMANAGER_HPP
#define DINOTRACKS_RESOURCEMANAGER_HPP

#include <string>

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
        bool load(Type type, const std::string& id);

        // Retrieval Functions
        sf::Texture& getTexture(const std::string& id) const;
        sf::Font& getFont(const std::string& id) const;
        sf::SoundBuffer& getSoundBuffer(const std::string& id) const;

    private:
        //
    };
}


#endif //DINOTRACKS_RESOURCEMANAGER_HPP
