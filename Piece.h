#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include "move.h"

class Piece {
public:
    static const int None = 0;
    static const int KingType = 1;
    static const int PawnType = 2;
    static const int KnightType = 3;
    static const int BishopType = 4;
    static const int RookType = 5;
    static const int QueenType = 6;

    static const int White = 8;
    static const int Black = 16;

    static sf::Texture WK, WQ, WR, WB, WH, WP;
    static sf::Texture BK, BQ, BR, BB, BH, BP;

    static void loadTextures();
    static void drawPiece(sf::RenderWindow& window, int pieceType, int color, float x, float y, float size);
    static bool isMoveLegal(int pieceType, int color, int startRow, int startCol, int endRow, int endCol, int board[8][8], const Move& lastMove);
};

#endif // PIECE_H
