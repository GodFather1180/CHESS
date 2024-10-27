// Chessboard.h
#ifndef board_H
#define board_H

#include <SFML/Graphics.hpp>

using namespace sf;

void Draw_chessboard(RenderWindow& window, int board, int size);

class Board {
public:
    // Constructor to initialize the board
    Board();

    // The chess board array representing the layout
    int board[8][8] = {
        2, 3, 4, 5, 6, 4, 3, 2,
        1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0,
        0,0, 0, 0, 0, 0, 0, 0,
        -1,-1, -1, -1, -1, -1, -1, -1,
        -2, -3, -4, -5, -6, -4, -3, -1
    };
};



#endif // CHESSBOARD_H
