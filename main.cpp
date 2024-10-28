#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include "board.h"

//using namespace instead of sf::
using namespace sf;

int main(){
    std::cout<< "Chess begins!" << std::endl;
    int Cboard = 8;
    int Csize = 100;
    //iniialize board
    Board Chessboard;
    RenderWindow window(VideoMode(8*Csize,8*Csize), "Chess Begins!");
        Piece::loadTextures();  // Load textures for all pieces

    Sprite sprite;

    bool ismove = false;
    float dx =0, dy = 0;
    while (window.isOpen())
    {
        Vector2i pos = Mouse:: getPosition(window);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
                //FIX drag and drop pieces
            if(event.type == Event::MouseButtonPressed)
                if(event.key.code == Mouse::Left){
                if(sprite.getGlobalBounds().contains(pos.x, pos.y))
                {
                    ismove = true;
                    dx = pos.x - sprite.getPosition().x;
                    dy = pos.y -  sprite.getPosition().y;
                }
            }
            if(event.type == Event::MouseButtonReleased)
                if(event.key.code == Mouse::Left)
                ismove = false;
        }

        if (ismove) sprite.setPosition(pos.x - dx, pos.y - dy);
        window.clear();
        Chessboard.Draw_chessboard(window,Csize);
        window.display();
    }

    return 0;
}