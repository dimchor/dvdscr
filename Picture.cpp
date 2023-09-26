#include "Picture.h"

namespace ds
{
    
Picture::Picture(std::string filename)
{
    this->updateTexture(std::move(filename));
}

void Picture::updateTexture(std::string filename)
{
    if (not texture.loadFromFile(filename))
    {
        throw ds::Exception("Failed to load image file.");
    };
    sprite.setTexture(texture);
}

}
