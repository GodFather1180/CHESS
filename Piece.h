#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>

class Piece {
public:
    // Integer values for piece types
    static const int None = 0;
    static const int KingType = 1;
    static const int PawnType = 2;
    static const int KnightType = 3;
    static const int BishopType = 4;
    static const int RookType = 5;
    static const int QueenType = 6;

    // Colors sorted by their bit size
    static const int White = 8;
    static const int Black = 16;

    static sf::Texture WK, WQ, WR, WB, WH, WP;
    static sf::Texture BK, BQ, BR, BB, BH, BP;

    static void loadTextures();
    static void isMoveLegal();  // Changed method names to avoid conflict
    static void king();
    static void queen();
    static void bishop();
    static void rook();
    static void knight();
    static void pawn();
    static void drawPiece(sf::RenderWindow& window, int pieceType, int color, float x, float y, float size);
};

#endif // PIECE_H
