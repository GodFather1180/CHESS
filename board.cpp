#include "board.h"
#include "Piece.h"

Board::Board() {
    // This can be empty, or you can initialize anything if needed
}

void Board::Draw_chessboard(sf::RenderWindow& window, int size) {
    sf::Color Whitecol(255, 255, 255);
    sf::Color Blackcol(50, 50, 50);

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            sf::RectangleShape square(sf::Vector2f(size, size));
            square.setPosition(col * size, row * size);
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
