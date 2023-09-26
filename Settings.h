#pragma once

#include <string>
#include <fstream>
#include <ios>
#include <iostream>

namespace ds
{

struct Settings
{
    std::string imageFilename{"dvd.png"};
    float offset{3.f};

    Settings();
    ~Settings();
};

}
