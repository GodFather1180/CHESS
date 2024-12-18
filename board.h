// board.h
#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "Piece.h"

class Board {
public:
    Board();  // Constructor

    // The chess board array representing the layout
    int board[8][8] = {
        {Piece::Rook | Piece::Black, Piece::Knight | Piece::Black, Piece::Bishop | Piece::Black, Piece::Queen | Piece::Black,
        Piece::King | Piece::Black, Piece::Bishop | Piece::Black, Piece::Knight | Piece::Black, Piece::Rook | Piece::Black},
        {Piece::Pawn | Piece::Black, Piece::Pawn | Piece::Black, Piece::Pawn | Piece::Black, Piece::Pawn | Piece::Black,
        Piece::Pawn | Piece::Black, Piece::Pawn | Piece::Black, Piece::Pawn | Piece::Black, Piece::Pawn | Piece::Black},
        {Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None},
        {Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None},
        {Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None},
        {Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None},
        {Piece::Pawn | Piece::White, Piece::Pawn | Piece::White, Piece::Pawn | Piece::White, Piece::Pawn | Piece::White,
        Piece::Pawn | Piece::White, Piece::Pawn | Piece::White, Piece::Pawn | Piece::White, Piece::Pawn | Piece::White},
        {Piece::Rook | Piece::White, Piece::Knight | Piece::White, Piece::Bishop | Piece::White, Piece::Queen | Piece::White,
        Piece::King | Piece::White, Piece::Bishop | Piece::White, Piece::Knight | Piece::White, Piece::Rook | Piece::White}
    };

    void Draw_chessboard(sf::RenderWindow& window, int size);
};

#endif // BOARD_H
