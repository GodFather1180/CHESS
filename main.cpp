#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include "board.h"


using namespace sf;

int main(){
    std::cout<< "Chess begins!" << std::endl;
    int Cboard = 8;
    int Csize = 100;

    Board Chessboard;
    RenderWindow window(VideoMode(8*Csize,8*Csize), "Chess Begins!");
        Piece::loadTextures();  // Load textures for all pieces

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        Chessboard.Draw_chessboard(window,Csize);
        window.display();
    }

    return 0;
}