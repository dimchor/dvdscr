#pragma once

#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Exception.h"

namespace ds
{

class Picture
{
public:
    Picture(std::string);

    sf::Sprite const& getSprite() const { return sprite; }
    sf::Sprite& getSprite() { return sprite; }

    void updateTexture(std::string);
private:
    sf::Sprite sprite{};
    sf::Texture texture{};
};

}
