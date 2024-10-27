// Piece.h
#ifndef PIECE_H
#define PIECE_H

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
};

#endif // PIECE_H
