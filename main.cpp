#include <SFML/Graphics.hpp>
#include <iostream>
#include "board.h"
#include "Piece.h"

using namespace sf;

int main() {
    std::cout << "Chess begins!" << std::endl;
    int Cboard = 8;
    int Csize = 100;

    Board Chessboard;
    RenderWindow window(VideoMode(Cboard * Csize, Cboard * Csize), "Chess Begins!");
    Piece::loadTextures();

    bool isMove = false;
    Vector2i selectedPos(-1, -1);

    while (window.isOpen()) {
        Vector2i mousePos = Mouse::getPosition(window);
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                int col = mousePos.x / Csize;
                int row = mousePos.y / Csize;

                if (!isMove && Chessboard.board[row][col] != Piece::None) {
                    selectedPos = Vector2i(row, col);
                    isMove = true;
                } else if (isMove) {
                    int startRow = selectedPos.x;
                    int startCol = selectedPos.y;
                    int endRow = row;
                    int endCol = col;

                    int piece = Chessboard.board[startRow][startCol];

                    // Validate move logic
                    if (true) { // Simplified for now
                        Chessboard.board[endRow][endCol] = piece;
                        Chessboard.board[startRow][startCol] = Piece::None;
                        std::cout << "Move made from (" << startRow << ", " << startCol << ") to (" << endRow << ", " << endCol << ")" << std::endl;
                    } else {
                        std::cout << "Invalid move" << std::endl;
                    }

                    isMove = false;
                }
            }
        }

        window.clear();
        Chessboard.Draw_chessboard(window, Csize);
        window.display();
    }

    return 0;
}
