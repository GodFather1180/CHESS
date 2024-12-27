#include "Piece.h"
#include "move.h"
#include <SFML/Graphics.hpp>
#include <cmath>

sf::Texture Piece::WK, Piece::WQ, Piece::WR, Piece::WB, Piece::WH, Piece::WP;
sf::Texture Piece::BK, Piece::BQ, Piece::BR, Piece::BB, Piece::BH, Piece::BP;

void Piece::loadTextures() {
    if (!WK.loadFromFile("pieces/white-king.png")) {
        throw std::runtime_error("Failed to load white king texture");
    }
    if (!WQ.loadFromFile("pieces/white-queen.png")) {
        throw std::runtime_error("Failed to load white queen texture");
    }
    if (!WR.loadFromFile("pieces/white-rook.png")) {
        throw std::runtime_error("Failed to load white rook texture");
    }
    if (!WB.loadFromFile("pieces/white-bishop.png")) {
        throw std::runtime_error("Failed to load white bishop texture");
    }
    if (!WH.loadFromFile("pieces/white-knight.png")) {
        throw std::runtime_error("Failed to load white knight texture");
    }
    if (!WP.loadFromFile("pieces/white-pawn.png")) {
        throw std::runtime_error("Failed to load white pawn texture");
    }

    if (!BK.loadFromFile("pieces/black-king.png")) {
        throw std::runtime_error("Failed to load black king texture");
    }
    if (!BQ.loadFromFile("pieces/black-queen.png")) {
        throw std::runtime_error("Failed to load black queen texture");
    }
    if (!BR.loadFromFile("pieces/black-rook.png")) {
        throw std::runtime_error("Failed to load black rook texture");
    }
    if (!BB.loadFromFile("pieces/black-bishop.png")) {
        throw std::runtime_error("Failed to load black bishop texture");
    }
    if (!BH.loadFromFile("pieces/black-knight.png")) {
        throw std::runtime_error("Failed to load black knight texture");
    }
    if (!BP.loadFromFile("pieces/black-pawn.png")) {
        throw std::runtime_error("Failed to load black pawn texture");
    }
}

void Piece::drawPiece(sf::RenderWindow& window, int pieceType, int color, float x, float y, float size) {
    sf::Sprite sprite;

    if (color == White) {
        switch (pieceType) {
            case KingType: sprite.setTexture(WK); break;
            case QueenType: sprite.setTexture(WQ); break;
            case RookType: sprite.setTexture(WR); break;
            case BishopType: sprite.setTexture(WB); break;
            case KnightType: sprite.setTexture(WH); break;
            case PawnType: sprite.setTexture(WP); break;
            default: return;
        }
    } else if (color == Black) {
        switch (pieceType) {
            case KingType: sprite.setTexture(BK); break;
            case QueenType: sprite.setTexture(BQ); break;
            case RookType: sprite.setTexture(BR); break;
            case BishopType: sprite.setTexture(BB); break;
            case KnightType: sprite.setTexture(BH); break;
            case PawnType: sprite.setTexture(BP); break;
            default: return;
        }
    } else {
        return;
    }

    sprite.setPosition(x, y);
    sprite.setScale(size / sprite.getTexture()->getSize().x, size / sprite.getTexture()->getSize().y);
    window.draw(sprite);
}

bool Piece::isMoveLegal(int pieceType, int color, int startRow, int startCol, int endRow, int endCol, int board[8][8], const Move& lastMove) {
    int targetPiece = board[endRow][endCol];
    int targetColor = targetPiece & 0x18;

    if (color == targetColor) return false; // Cannot move to a square occupied by the same color

    int dRow = endRow - startRow;
    int dCol = endCol - startCol;

    switch (pieceType) {
        case PawnType:
            if (color == White) {
                if (dRow == -1 && dCol == 0 && targetPiece == None) return true;
                if (dRow == -1 && std::abs(dCol) == 1 && targetPiece != None) return true;
                if (startRow == 6 && dRow == -2 && dCol == 0 && board[startRow - 1][startCol] == None && targetPiece == None) return true;
                // En passant
                if (dRow == -1 && std::abs(dCol) == 1 && targetPiece == None &&
                    lastMove.endRow == startRow && lastMove.endCol == endCol &&
                    board[lastMove.endRow][lastMove.endCol] == (PawnType | Black)) {
                    return true;
                }
            } else { // Black pawn
                if (dRow == 1 && dCol == 0 && targetPiece == None) return true;
                if (dRow == 1 && std::abs(dCol) == 1 && targetPiece != None) return true;
                if (startRow == 1 && dRow == 2 && dCol == 0 && board[startRow + 1][startCol] == None && targetPiece == None) return true;
                // En passant
                if (dRow == 1 && std::abs(dCol) == 1 && targetPiece == None &&
                    lastMove.endRow == startRow && lastMove.endCol == endCol &&
                    board[lastMove.endRow][lastMove.endCol] == (PawnType | White)) {
                    return true;
                }
            }
            break;
        case RookType:
            if (dRow == 0 || dCol == 0) {
                for (int i = 1; i < std::max(std::abs(dRow), std::abs(dCol)); i++) {
                    if (board[startRow + i * (dRow != 0)][startCol + i * (dCol != 0)] != None) return false; // Blocked
                }
                return true;
            }
            break;
        case KnightType:
            if ((std::abs(dRow) == 2 && std::abs(dCol) == 1) || (std::abs(dRow) == 1 && std::abs(dCol) == 2)) return true;
            break;
        case BishopType:
            if (std::abs(dRow) == std::abs(dCol)) {
                for (int i = 1; i < std::abs(dRow); i++) {
                    if (board[startRow + i * (dRow / std::abs(dRow))][startCol + i * (dCol / std::abs(dCol))] != None) return false; // Blocked
                }
                return true;
            }
            break;
        case QueenType:
            if (std::abs(dRow) == std::abs(dCol) || dRow == 0 || dCol == 0) {
                for (int i = 1; i < std::max(std::abs(dRow), std::abs(dCol)); i++) {
                    if (board[startRow + i * (dRow != 0 ? dRow / std::abs(dRow) : 0)][startCol + i * (dCol != 0 ? dCol / std::abs(dCol) : 0)] != None) return false; // Blocked
                }
                return true;
            }
            break;
        case KingType:
            if (std::abs(dRow) <= 1 && std::abs(dCol) <= 1) return true; // Single-step move
            // Castling
            if (std::abs(dCol) == 2 && dRow == 0) {
                if (color == White && startRow == 7) {
                    if ((endCol == 6 && board[startRow][5] == None && board[startRow][6] == None) ||
                        (endCol == 2 && board[startRow][3] == None && board[startRow][2] == None && board[startRow][1] == None)) {
                        return true;
                    }
                } else if (color == Black && startRow == 0) {
                    if ((endCol == 6 && board[startRow][5] == None && board[startRow][6] == None) ||
                        (endCol == 2 && board[startRow][3] == None && board[startRow][2] == None && board[startRow][1] == None)) {
                        return true;
                    }
                }
            }
            break;
    }

    return false;
}