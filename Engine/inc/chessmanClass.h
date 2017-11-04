#pragma once
enum class chessmanClass
{
	whitePawn = 0,
	whiteRook = 1,
	whiteKnight = 2,
	whiteBishop = 3,
	whiteQueen = 4,
	whiteKing = 5,
	blackPawn = 6,
	blackRook = 7,
	blackKnight = 8,
	blackBishop = 9,
	blackQueen = 10,
	blackKing = 11,
	black = 12,
	white = 13,
	none = 14
};


constexpr const unsigned int operator !=(chessmanClass a, unsigned int b) { return static_cast<unsigned int>(a) != b; };
constexpr unsigned int operator ==(chessmanClass a, unsigned int b) { return static_cast<unsigned int>(a) == b; };

