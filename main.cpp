// necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h
#include "imgui.h" 

// for ImGui::SFML::* functions and SFML-specific overloads
#include "imgui-SFML.h" 

#include "Picture.h"

#include <iostream>
#include <cstdlib>
#include <vector>

#include <SFML/Graphics.hpp>

int main(int argc, char** argv) 
{
    std::vector<sf::VideoMode> const videoModes{
        sf::VideoMode::getFullscreenModes()};

    if (videoModes.empty())
    {
        std::cerr << "No available fullscreen modes. Exiting...";
        std::exit(EXIT_FAILURE);
    }

    sf::RenderWindow window{videoModes.front(), "dvdscr", 
        sf::Style::Fullscreen};
    window.setFramerateLimit(60);

    ImGui::SFML::Init(window);

    ds::Picture picture{"dvd.png", videoModes.front()};
    picture.setOffset({1.0f, 1.0f});


    sf::Clock deltaClock;
    while (window.isOpen()) 
    {
        sf::Event event{};
        while (window.pollEvent(event)) 
        {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }

        }

        picture.update();

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear();
        window.draw(picture.getSprite());
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}
