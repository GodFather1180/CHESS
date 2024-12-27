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
    bool isWhiteTurn = true; // White starts first

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
                    int piece = Chessboard.board[row][col];
                    int pieceColor = piece & 0x18;

                    // Ensure the correct player's turn
                    if ((isWhiteTurn && pieceColor == Piece::White) || (!isWhiteTurn && pieceColor == Piece::Black)) {
                        selectedPos = Vector2i(row, col);
                        isMove = true;
                    } else {
                        std::cout << "It's not your turn!" << std::endl;
                    }
                } else if (isMove) {
                    int startRow = selectedPos.x;
                    int startCol = selectedPos.y;
                    int endRow = row;
                    int endCol = col;

                    int piece = Chessboard.board[startRow][startCol];
                    int pieceType = piece & 0x7;
                    int pieceColor = piece & 0x18;

                    // Call isMoveLegal to validate the move
                    if (Piece::isMoveLegal(pieceType, pieceColor, startRow, startCol, endRow, endCol, Chessboard.board)) {
                        // Update the board if the move is valid
                        Chessboard.board[endRow][endCol] = piece;
                        Chessboard.board[startRow][startCol] = Piece::None;
                        std::cout << "Move made from (" << startRow << ", " << startCol << ") to (" << endRow << ", " << endCol << ")" << std::endl;

                        // Switch turns
                        isWhiteTurn = !isWhiteTurn;
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
