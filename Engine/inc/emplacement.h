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
	bitset<64> getPosOf(chessmanClass chessman);
	bitset<64> getPosOf_whitePawn();
	bitset<64> getPosOf_whiteRook();
	bitset<64> getPosOf_whiteKnight();
	bitset<64> getPosOf_whiteBishop();
	bitset<64> getPosOf_whiteQueen();
	bitset<64> getPosOf_whiteKing();
	bitset<64> getPosOf_blackPawn();
	bitset<64> getPosOf_blackRook();
	bitset<64> getPosOf_blackKnight();
	bitset<64> getPosOf_blackBishop();
	bitset<64> getPosOf_blackQueen();
	bitset<64> getPosOf_blackKing();
	bitset<64> getEmptyFields();
	bitset<64> getOccupiedFields();
	bitset<64> getBlackOccupiedFields();
	bitset<64> getWhiteOccupiedFields();
	void setChessmanOnPosition(chessmanClass chessman, int position);

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

