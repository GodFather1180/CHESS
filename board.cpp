#include "board.h"
#include "Piece.h"

Board::Board() {
    // This can be empty, or you can initialize anything if needed
}

void Board::Draw_chessboard(sf::RenderWindow& window, int size) {
    //Color for the square
    sf::Color Whitecol(255, 255, 255);
    sf::Color Blackcol(255, 192, 203); // forced by anini

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            sf::RectangleShape square(sf::Vector2f(size, size));
            square.setPosition(col * size, row * size);
            //fill the color of the square based on its position
            square.setFillColor((row + col) % 2 == 0 ? Whitecol : Blackcol);
            window.draw(square);

            int piece = board[row][col];
            int pieceType = piece & 0x7;  // Extract type
            int color = piece & 0x18;     // Extract color

            if (pieceType != Piece::None) {
                Piece::drawPiece(window, pieceType, color, col * size, row * size, size);
            }
        }
    }
}

