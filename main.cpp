// necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h
#include "imgui.h" 

// for ImGui::SFML::* functions and SFML-specific overloads
#include "imgui-SFML.h" 

#include "Picture.h"
#include "Settings.h"

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <ctime>

#include <SFML/Graphics.hpp>

#include <Thor/Input/Action.hpp>
#include <Thor/Input/ActionMap.hpp>

int main(int argc, char** argv) 
{
    std::srand(std::time(nullptr));
    sf::VideoMode videoMode{sf::VideoMode::getDesktopMode()};

    sf::RenderWindow window{videoMode, "dvdscr", sf::Style::Fullscreen};
    window.setFramerateLimit(60);

    ImGui::SFML::Init(window);

    ds::Settings settings{};
    thor::ActionMap<std::string> actionMap{};
    actionMap["quit"] = thor::Action{sf::Keyboard::Escape, 
        thor::Action::PressOnce};
    actionMap["settings"] = thor::Action{
                thor::Action{sf::Keyboard::LControl, thor::Action::Hold} && 
                thor::Action{sf::Keyboard::O, thor::Action::ReleaseOnce}};

    ds::Picture picture{settings.imageFilename, videoMode};
    picture.setOffset({settings.offset, settings.offset});

    sf::Clock deltaClock;
    while (window.isOpen()) 
    {
        static bool settingsWindow{false};
        actionMap.clearEvents();
        sf::Event event{};
        while (window.pollEvent(event)) 
        {   
            actionMap.pushEvent(event);
            ImGui::SFML::ProcessEvent(window, event);

            if (actionMap.isActive("quit"))
            {
                window.close();
            }

            if (actionMap.isActive("settings"))
            {
                settingsWindow = (settingsWindow ? false : true);
            }

        }

        picture.update();

        ImGui::SFML::Update(window, deltaClock.restart());
        if (settingsWindow)
        {
            ImGui::Begin("Settings");
            ImGui::InputText("filename", settings.imageFilename.data(), 
                settings.imageFilenameSize);
            ImGui::SliderFloat("Speed", &settings.offset, 1.f, 10.f);
            if (ImGui::Button("Apply"))
            {
                picture.updateTexture(settings.imageFilename);
                auto offset{picture.getOffset()};
                offset.x = (offset.x < 0 ? -settings.offset : settings.offset);
                offset.y = (offset.y < 0 ? -settings.offset : settings.offset);
                picture.setOffset(offset);
            }
            ImGui::End();

        }

        window.clear();
        window.draw(picture.getSprite());
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}
