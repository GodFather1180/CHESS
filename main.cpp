#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>


void Draw_chessboard(sf::RenderWindow& window,int board,int size){
    sf::RectangleShape();
    sf::Color Whitecol(255,255,255);
    sf::Color Blackcol(0,0,0);
    
    for (int row =0; row<board;row++){
        for (int col=0; col<board;col++){
            sf::RectangleShape square(sf::Vector2f(size,size));
            square.setPosition(col*size,row*size);
            square.setFillColor(( row + col) %2 == 0 ? Whitecol : Blackcol);
            window.draw(square);
        }
    } 
    

}

int main(){
    std::cout<< "Chess begins0!" << std::endl;
    int Cboard = 8;
    int Csize = 100;
    sf::RenderWindow window(sf::VideoMode(Cboard*Csize,Cboard*Csize), "Chess Begins!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        Draw_chessboard(window,Cboard,Csize);
        window.display();
    }

    return 0;
}