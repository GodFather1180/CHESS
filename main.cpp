#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
using namespace sf;
#include "board.h"

int main(){
    std::cout<< "Chess begins0!" << std::endl;
    int Cboard = 8;
    int Csize = 100;
    RenderWindow window(VideoMode(Cboard*Csize,Cboard*Csize), "Chess Begins!");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        Draw_chessboard(window,Cboard,Csize);
        window.display();
    }

    return 0;
}