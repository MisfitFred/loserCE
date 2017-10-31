#pragma once
#include "Types.h"
#include "chessmanClass.h"

using namespace std; 
class emplacement
{

public: 
	posOfChessmanClass getGetPosOf(chessmanClass chessman);
	posOfChessmanClass getGetPosOf_whitePawn();
	posOfChessmanClass getGetPosOf_whiteRook();
	posOfChessmanClass getGetPosOf_whiteKnight();
	posOfChessmanClass getGetPosOf_whiteBishop();
	posOfChessmanClass getGetPosOf_whiteQueen();
	posOfChessmanClass getGetPosOf_whiteKing();
	posOfChessmanClass getGetPosOf_blackPawn();
	posOfChessmanClass getGetPosOf_blackRook();
	posOfChessmanClass getGetPosOf_blackKnight();
	posOfChessmanClass getGetPosOf_blackBishop();
	posOfChessmanClass getGetPosOf_blackQueen();
	posOfChessmanClass getGetPosOf_blackKing();
	posOfChessmanClass getEmptyFields();
	posOfChessmanClass getOccupiedFields();
	posOfChessmanClass getBlackOccupiedFields();
	posOfChessmanClass getWhiteOccupiedFields();

	emplacement(emplacement *originChessboard);
	~emplacement();

protected:
	const posOfChessmanClass *chessboard;
};

