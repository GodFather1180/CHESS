#include "Piece.h"

// Define each texture individually
sf::Texture Piece::WK;
sf::Texture Piece::WQ;
sf::Texture Piece::WR;
sf::Texture Piece::WB;
sf::Texture Piece::WH;
sf::Texture Piece::WP;

sf::Texture Piece::BK;
sf::Texture Piece::BQ;
sf::Texture Piece::BR;
sf::Texture Piece::BB;
sf::Texture Piece::BH;
sf::Texture Piece::BP;

void Piece::loadTextures() {
    // Load white  textures
    WK.loadFromFile("pieces/white-king.png");
    WQ.loadFromFile("pieces/white-queen.png");
    WR.loadFromFile("pieces/white-rook.png");
    WB.loadFromFile("pieces/white-bishop.png");
    WH.loadFromFile("pieces/white-knight.png");
    WP.loadFromFile("pieces/white-pawn.png");

    // Load black  textures
    BK.loadFromFile("pieces/black-king.png");
    BQ.loadFromFile("pieces/black-queen.png");
    BR.loadFromFile("pieces/black-rook.png");
    BB.loadFromFile("pieces/black-bishop.png");
    BH.loadFromFile("pieces/black-knight.png");
    BP.loadFromFile("pieces/black-pawn.png");
}

void Piece::drawPiece(sf::RenderWindow& window, int pieceType, int color, float x, float y, float size) {
    sf::Sprite sprite;

    // Select the texture based on the piece type and color
    if (color == White) {
        switch (pieceType) {
            case King: sprite.setTexture(WK); break;
            case Queen: sprite.setTexture(WQ); break;
            case Rook: sprite.setTexture(WR); break;
            case Bishop: sprite.setTexture(WB); break;
            case Knight: sprite.setTexture(WH); break;
            case Pawn: sprite.setTexture(WP); break;
            default: return; // No valid piece type; do not draw anything
        }
    } else if (color == Black) {
        switch (pieceType) {
            case King: sprite.setTexture(BK); break;
            case Queen: sprite.setTexture(BQ); break;
            case Rook: sprite.setTexture(BR); break;
            case Bishop: sprite.setTexture(BB); break;
            case Knight: sprite.setTexture(BH); break;
            case Pawn: sprite.setTexture(BP); break;
            default: return; // No valid piece type; do not draw anything
        }
    } else {
        return; // Invalid color
    }

    // Set position and scale for the piece
    sprite.setPosition(x, y);
    sprite.setScale(
        size / sprite.getTexture()->getSize().x,  // Scale to fit square size
        size / sprite.getTexture()->getSize().y
    );

    // Draw the piece sprite on the window
    window.draw(sprite);
}
