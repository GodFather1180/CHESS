#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "Piece.h"

class Board {
public:
    Board();

    int board[8][8] = {
        {Piece::RookType | Piece::Black, Piece::KnightType | Piece::Black, Piece::BishopType | Piece::Black, Piece::QueenType | Piece::Black,
         Piece::KingType | Piece::Black, Piece::BishopType | Piece::Black, Piece::KnightType | Piece::Black, Piece::RookType | Piece::Black},
        {Piece::PawnType | Piece::Black, Piece::PawnType | Piece::Black, Piece::PawnType | Piece::Black, Piece::PawnType | Piece::Black,
         Piece::PawnType | Piece::Black, Piece::PawnType | Piece::Black, Piece::PawnType | Piece::Black, Piece::PawnType | Piece::Black},
        {Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None},
        {Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None},
        {Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None},
        {Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None},
        {Piece::PawnType | Piece::White, Piece::PawnType | Piece::White, Piece::PawnType | Piece::White, Piece::PawnType | Piece::White,
         Piece::PawnType | Piece::White, Piece::PawnType | Piece::White, Piece::PawnType | Piece::White, Piece::PawnType | Piece::White},
        {Piece::RookType | Piece::White, Piece::KnightType | Piece::White, Piece::BishopType | Piece::White, Piece::QueenType | Piece::White,
         Piece::KingType | Piece::White, Piece::BishopType | Piece::White, Piece::KnightType | Piece::White, Piece::RookType | Piece::White}
    };

    void Draw_chessboard(sf::RenderWindow& window, int size);
};

#endif // BOARD_H
