#pragma once

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "Exception.h"

namespace ds
{

class Picture
{
public:
    Picture(std::string, sf::VideoMode);

    sf::Sprite const& getSprite() const { return _sprite; }
    sf::Sprite& getSprite() { return _sprite; }

    sf::Vector2f const& getOffset() const { return _offset; }
    void setOffset(sf::Vector2f const offset) { _offset = offset; }

    sf::VideoMode const& getVideoMode() const { return _videoMode; }
    void setVideoMode(sf::VideoMode const& videoMode)
    { 
        _videoMode = videoMode; 
    }

    void update();

    void updateTexture(std::string);
private:
    sf::Sprite _sprite{};
    sf::Texture _texture{};
    sf::Vector2f _offset{};
    sf::VideoMode _videoMode{};
};

}
