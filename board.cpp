// Chessboard.cpp
#include "board.h"

void Draw_chessboard(RenderWindow& window, int board, int size) {
    Color Whitecol(255, 255, 255);
    Color Blackcol(0, 0, 0);
    //loop for the box
    for (int row = 0; row < board; row++) {
        for (int col = 0; col < board; col++) {
            RectangleShape square(Vector2f(size, size));
            square.setPosition(col * size, row * size);
            //checks for even and give the color
            square.setFillColor((row + col) % 2 == 0 ? Whitecol : Blackcol);
            window.draw(square);
        }
    }
}
