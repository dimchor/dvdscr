#include "Picture.h"

namespace ds
{
    
Picture::Picture(std::string filename, sf::VideoMode videoMode): _videoMode(std::move(videoMode))
{
    this->updateTexture(std::move(filename));
}

void Picture::updateTexture(std::string filename)
{
    if (not _texture.loadFromFile(filename))
    {
        throw ds::Exception("Failed to load image file.");
    };
    _sprite.setTexture(_texture);
}

void Picture::update()
{
    // collision and bouncing
    if (_sprite.getPosition().x < 0)
    {
        _sprite.setPosition({0.f, _sprite.getPosition().y});
        _offset.x = -_offset.x;
        changeColour();
    }
    if (_sprite.getPosition().y < 0)
    {
        _sprite.setPosition({_sprite.getPosition().x, 0.f});
        _offset.y = -_offset.y;
        changeColour();
    }
    if (_sprite.getPosition().x + _sprite.getGlobalBounds().width > 
        _videoMode.width)
    {
        _sprite.setPosition(_videoMode.width - _sprite.getGlobalBounds().width,
             _sprite.getPosition().y);
        _offset.x = -_offset.x;
        changeColour();
    }
    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 
        _videoMode.height)
    {
        _sprite.setPosition(_sprite.getPosition().x, 
            _videoMode.height - _sprite.getGlobalBounds().height);
        _offset.y = -_offset.y;
        changeColour();
    }
    
    _sprite.move(_offset);
}

void Picture::changeColour()
{
    _sprite.setColor(sf::Color(ds::random<unsigned char>(0, 255),
                               ds::random<unsigned char>(0, 255), 
                               ds::random<unsigned char>(0, 255)));
}

}
