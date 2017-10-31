#pragma once
#include "Types.h"
#include "chessmanClass.h"
#include "chessMove.h"
#include <array>
#include <bitset>

using namespace std; 
class emplacement
{

public: 
	bitset<64> getGetPosOf(chessmanClass chessman);
	bitset<64> getGetPosOf_whitePawn();
	bitset<64> getGetPosOf_whiteRook();
	bitset<64> getGetPosOf_whiteKnight();
	bitset<64> getGetPosOf_whiteBishop();
	bitset<64> getGetPosOf_whiteQueen();
	bitset<64> getGetPosOf_whiteKing();
	bitset<64> getGetPosOf_blackPawn();
	bitset<64> getGetPosOf_blackRook();
	bitset<64> getGetPosOf_blackKnight();
	bitset<64> getGetPosOf_blackBishop();
	bitset<64> getGetPosOf_blackQueen();
	bitset<64> getGetPosOf_blackKing();
	bitset<64> getEmptyFields();
	bitset<64> getOccupiedFields();
	bitset<64> getBlackOccupiedFields();
	bitset<64> getWhiteOccupiedFields();

	chessmanClass getChessmanClassOnPostion(int position);

	emplacement(emplacement *originChessboard) : chessboard{ originChessboard->chessboard } {};
	emplacement();
	emplacement(emplacement *originChessboard, chessMove move);
	~emplacement();

protected:
	//const posOfChessmanClass chessboard[12];
	//std::array<float, 4> a = { 0,1,2,3 };

	std::array<bitset<64>, 12> chessboard;

};

