#include <SFML/Graphics.hpp>
#include <iostream>
#include "board.h"
#include "Piece.h"
#include "move.h"

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
    Move lastMove = {-1, -1, -1, -1}; // Initialize last move

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
                    if (Piece::isMoveLegal(pieceType, pieceColor, startRow, startCol, endRow, endCol, Chessboard.board, lastMove)) {
                        // Handle castling
                        if (pieceType == Piece::KingType && std::abs(endCol - startCol) == 2) {
                            if (endCol == 6) { // King-side castling
                                Chessboard.board[startRow][5] = Chessboard.board[startRow][7]; // Move rook
                                Chessboard.board[startRow][7] = Piece::None; // Clear old rook position
                            } else if (endCol == 2) { // Queen-side castling
                                Chessboard.board[startRow][3] = Chessboard.board[startRow][0]; // Move rook
                                Chessboard.board[startRow][0] = Piece::None; // Clear old rook position
                            }
                        }

                        // Handle en passant
                        if (pieceType == Piece::PawnType && Chessboard.board[endRow][endCol] == Piece::None && std::abs(endCol - startCol) == 1) {
                            if (pieceColor == Piece::White) {
                                Chessboard.board[endRow + 1][endCol] = Piece::None; // Remove captured black pawn
                            } else {
                                Chessboard.board[endRow - 1][endCol] = Piece::None; // Remove captured white pawn
                            }
                        }

                        // Update the board for the current move
                        Chessboard.board[endRow][endCol] = Chessboard.board[startRow][startCol];
                        Chessboard.board[startRow][startCol] = Piece::None;

                        // Update last move
                        lastMove = {startRow, startCol, endRow, endCol};

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
