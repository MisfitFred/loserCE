#include "stdafx.h"
#include "emplacement.h"
#include "string.h"

static const auto whitePawn = 0;
static const auto whiteRook = 1;
static const auto whiteKnight = 2;
static const auto whiteBishop = 3;
static const auto whiteQueen = 4;
static const auto whiteKing = 5;
static const auto blackPawn = 6;
static const auto blackRook = 7;
static const auto blackKnight = 8;
static const auto blackBishop = 9;
static const auto blackQueen = 10;
static const auto blackKing = 11;

emplacement::emplacement(emplacement *originChessboard)
{
	//toDo MemoryPool can optimize speed for memory allocation
	chessboard = new posOfChessmanClass[12];
	//todo better use c++ mechanisms, perhaps a reference can be fir much better
	memcpy((void*)chessboard, originChessboard->chessboard, sizeof(chessboard));
}

emplacement::~emplacement()
{
	delete chessboard; 
}

posOfChessmanClass emplacement::getGetPosOf(chessmanClass chessman)
{
	switch (chessman) {
		case chessmanClass::whitePawn:
	
		break;
		case chessmanClass::whiteRook:
	
		break;
		case chessmanClass::whiteKnight:
	
		break;
		case chessmanClass::whiteBishop:
	
		break;
		case chessmanClass::whiteQueen:
	
		break;
		case chessmanClass::whiteKing:
	
		break;
		case chessmanClass::blackpawn:
	
		break;
		case chessmanClass::blackRook:
	
		break;
		case chessmanClass::blackKnight:
	
		break;
		case chessmanClass::blackBishop:
	
		break;
		case chessmanClass::blackQueen:
	
		break;
		case chessmanClass::blackKing:

		break;
		case chessmanClass::black:
		
		break;
		case chessmanClass::white:
		
		break;
	};

	return this->chessboard[0];
}

posOfChessmanClass emplacement::getGetPosOf_whitePawn()
{
	return this->chessboard[whitePawn];
}

posOfChessmanClass emplacement::getGetPosOf_whiteRook()
{
	return this->chessboard[whiteRook];
}

posOfChessmanClass emplacement::getGetPosOf_whiteKnight()
{
	return this->chessboard[whiteKnight];
}

posOfChessmanClass emplacement::getGetPosOf_whiteBishop()
{
	return this->chessboard[whiteBishop];
}

posOfChessmanClass emplacement::getGetPosOf_whiteQueen()
{
	return this->chessboard[whiteQueen];
}

posOfChessmanClass emplacement::getGetPosOf_whiteKing()
{
	return this->chessboard[whiteKing];
}

posOfChessmanClass emplacement::getGetPosOf_blackPawn()
{
	return this->chessboard[blackPawn];
}

posOfChessmanClass emplacement::getGetPosOf_blackRook()
{
	return this->chessboard[blackRook];
}

posOfChessmanClass emplacement::getGetPosOf_blackKnight()
{
	return this->chessboard[blackKnight];
}

posOfChessmanClass emplacement::getGetPosOf_blackBishop()
{
	return this->chessboard[blackBishop];
}

posOfChessmanClass emplacement::getGetPosOf_blackQueen()
{
	return this->chessboard[blackQueen];
}

posOfChessmanClass emplacement::getGetPosOf_blackKing()
{
	return this->chessboard[blackKing];
}

posOfChessmanClass emplacement::getEmptyFields()
{
	posOfChessmanClass emptyFileds = 0;
	for (int i = 0; i < sizeof(chessboard); i++)
	{
		emptyFileds = chessboard[i] | emptyFileds;
	}
	return ~emptyFileds;
}

posOfChessmanClass emplacement::getOccupiedFields()
{
	posOfChessmanClass occupiedFields = 0;
	for (int i = 0; i < sizeof(chessboard); i++)
	{
		occupiedFields = chessboard[i] | occupiedFields;
	}
	return occupiedFields;
}

posOfChessmanClass emplacement::getBlackOccupiedFields()
{
	return chessboard[blackPawn] | chessboard[blackBishop] | chessboard[blackKing] | chessboard[blackKnight] | chessboard[blackQueen] | chessboard[blackRook];
}

posOfChessmanClass emplacement::getWhiteOccupiedFields()
{
	return chessboard[whitePawn] | chessboard[whiteBishop] | chessboard[whiteKing] | chessboard[whiteKnight] | chessboard[whiteQueen] | chessboard[whiteRook];
}
