#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>


int main(){
    std::cout<< "Hello SFML!!" << std::endl;

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Board");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}
