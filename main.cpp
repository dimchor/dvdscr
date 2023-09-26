// necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h
#include "imgui.h" 

// for ImGui::SFML::* functions and SFML-specific overloads
#include "imgui-SFML.h" 

#include "Picture.h"
#include "Settings.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>

int main(int argc, char** argv) 
{
    std::srand(std::time(nullptr));
    sf::VideoMode videoMode{sf::VideoMode::getDesktopMode()};

    sf::RenderWindow window{videoMode, "dvdscr", sf::Style::Fullscreen};
    window.setFramerateLimit(60);

    ImGui::SFML::Init(window);

    ds::Settings settings{};

    ds::Picture picture{settings.imageFilename, videoMode};
    picture.setOffset({settings.offset, settings.offset});

    sf::Clock deltaClock;
    while (window.isOpen()) 
    {
        sf::Event event{};
        while (window.pollEvent(event)) 
        {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed
                or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
            {
                window.close();
            }

        }

        picture.update();

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Settings");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear();
        window.draw(picture.getSprite());
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}
