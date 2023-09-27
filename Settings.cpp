#include "Settings.h"

namespace ds
{

Settings::Settings()
{
    std::ifstream ifs{"settings.dat", std::ios::binary};
    if (ifs.bad())
    {
        std::cerr << "Couldn't open file. Using defaults instead...\n";
        return;
    }

    imageFilename.resize(imageFilenameSize);
    ifs.read((char*)imageFilename.c_str(), imageFilename.size());
    ifs.read((char*)&offset, sizeof(float));

    ifs.close();
    if (ifs.bad())
    {
        std::cerr << "An error occured while reading settings.\n";
    }
}


Settings::~Settings()
{
    std::ofstream ofs{"settings.dat", std::ios::binary};
    if (ofs.bad())
    {
        std::cerr << "Couldn't open file to write settings. \
Your changes won't be saved.\n";
        return ;
    }

    ofs.write((char*)imageFilename.c_str(), imageFilename.size());
    ofs.write((char*)&offset, sizeof(float));

    ofs.close();
    if (ofs.bad())
    {
        std::cerr << "An error occured while writing settings. \
Your changes may not be saved.";
    }
}

}
