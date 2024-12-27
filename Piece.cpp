#include "Piece.h"
#include <SFML/Graphics.hpp>

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