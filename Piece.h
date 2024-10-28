// Piece.h
#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>

class Piece {
public:
    static const int None = 0;
    static const int King = 1;
    static const int Pawn = 2;
    static const int Knight = 3;
    static const int Bishop = 4;
    static const int Rook = 5;
    static const int Queen = 6;

    static const int White = 8;
    static const int Black = 16;

    static sf::Texture WK, WQ, WR, WB, WH, WP;
    static sf::Texture BK, BQ, BR, BB, BH,BP;

    static void loadTextures();
    static void drawPiece(sf::RenderWindow& window, int pieceType, int color, float x, float y, float size);
};

#endif // PIECE_H
