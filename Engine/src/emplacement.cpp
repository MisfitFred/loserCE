#include "stdafx.h"
#include "emplacement.h"
#include "string.h"
#include <exception>

/*some ugly type casts due to performance increase */
static_assert(chessmanClass::whitePawn == 0u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::whiteRook == 1u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::whiteKnight == 2u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::whiteBishop == 3u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::whiteQueen == 4u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::whiteKing == 5u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::blackPawn == 6u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::blackRook == 7u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::blackKnight == 8u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::blackBishop == 9u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::blackQueen == 10u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::blackKing == 11u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::black == 12u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static_assert(chessmanClass::white == 13u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
static constexpr int whitePawn = static_cast<int>(chessmanClass::whitePawn);
static constexpr int whiteRook = static_cast<int>(chessmanClass::whiteRook);
static constexpr int whiteKnight = static_cast<int>(chessmanClass::whiteKnight);
static constexpr int whiteBishop = static_cast<int>(chessmanClass::whiteBishop);
static constexpr int whiteQueen = static_cast<int>(chessmanClass::whiteQueen);
static constexpr int whiteKing = static_cast<int>(chessmanClass::whiteKing);
static constexpr int blackPawn = static_cast<int>(chessmanClass::blackPawn);
static constexpr int blackRook = static_cast<int>(chessmanClass::blackRook);
static constexpr int blackKnight = static_cast<int>(chessmanClass::blackKnight);
static constexpr int blackBishop = static_cast<int>(chessmanClass::blackBishop);
static constexpr int blackQueen = static_cast<int>(chessmanClass::blackQueen);
static constexpr int blackKing = static_cast<int>(chessmanClass::blackKing);
static constexpr int black = static_cast<int>(chessmanClass::black);
static constexpr int white = static_cast<int>(chessmanClass::white);


emplacement::emplacement()
{
	for ( auto i: chessboard) {
		i = 0;
	}
}

/*
emplacement::emplacement(emplacement *originChessboard)
{
	//todo better use c++ mechanisms, perhaps a reference can be fit much better
	//std::copy(std::begin(chessboard), std::end(chessboard), std::begin(originChessboard->chessboard));
	//memcpy((void*)chessboard, originChessboard->chessboard, sizeof(chessboard));
}*/

emplacement::emplacement(emplacement * originChessboard, chessMove move)
{
	std::copy(std::begin(chessboard), std::end(chessboard), std::begin(originChessboard->chessboard));
	int chessmanType = static_cast<int>(move.chessman);
	const chessmanClass chessmanClassOnNewPosition = getChessmanClassOnPostion(move.oldPosition);

	if (chessboard[chessmanType].test(move.oldPosition))
	{
		chessboard[chessmanType].reset(move.oldPosition);

		//check if a chessman is already on the new position, if yes remove it. 
		if (chessmanClassOnNewPosition == chessmanClass::none)
		{
			chessboard[static_cast<int>(chessmanClassOnNewPosition)].reset(move.newPosition);
		}

		chessboard[chessmanType].set(move.newPosition);
	}
	else
	{

	}


}

emplacement::~emplacement()
{
	//delete chessboard; 
}



bitset<64> emplacement::getPosOf(chessmanClass chessman)
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
		case chessmanClass::blackPawn:
	
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

bitset<64> emplacement::getPosOf_whitePawn()
{
	return this->chessboard[whitePawn];
}

bitset<64> emplacement::getPosOf_whiteRook()
{
	return this->chessboard[whiteRook];
}

bitset<64> emplacement::getPosOf_whiteKnight()
{
	return this->chessboard[whiteKnight];
}

bitset<64> emplacement::getPosOf_whiteBishop()
{
	return this->chessboard[whiteBishop];
}

bitset<64> emplacement::getPosOf_whiteQueen()
{
	return this->chessboard[whiteQueen];
}

bitset<64> emplacement::getPosOf_whiteKing()
{
	return this->chessboard[whiteKing];
}

bitset<64> emplacement::getPosOf_blackPawn()
{
	return this->chessboard[blackPawn];
}

bitset<64> emplacement::getPosOf_blackRook()
{
	return this->chessboard[blackRook];
}

bitset<64> emplacement::getPosOf_blackKnight()
{
	return this->chessboard[blackKnight];
}

bitset<64> emplacement::getPosOf_blackBishop()
{
	return this->chessboard[blackBishop];
}

bitset<64> emplacement::getPosOf_blackQueen()
{
	return this->chessboard[blackQueen];
}

bitset<64> emplacement::getPosOf_blackKing()
{
	return this->chessboard[blackKing];
}

bitset<64> emplacement::getEmptyFields()
{
	bitset<64> emptyFileds = 0;
	for (int i = 0; i < sizeof(chessboard); i++)
	{
		emptyFileds = chessboard[i] | emptyFileds;
	}
	return ~emptyFileds;
}

bitset<64> emplacement::getOccupiedFields()
{
	bitset<64> occupiedFields = 0;
	for (int i = 0; i < sizeof(chessboard); i++)
	{
		occupiedFields = chessboard[i] | occupiedFields;
	}
	return occupiedFields;
}

bitset<64> emplacement::getBlackOccupiedFields()
{
	return chessboard[blackPawn] | chessboard[blackBishop] | chessboard[blackKing] 
		| chessboard[blackKnight] | chessboard[blackQueen] | chessboard[blackRook];
}

bitset<64> emplacement::getWhiteOccupiedFields()
{
	return chessboard[whitePawn] | chessboard[whiteBishop] | chessboard[whiteKing] 
		| chessboard[whiteKnight] | chessboard[whiteQueen] | chessboard[whiteRook];
}

chessmanClass emplacement::getChessmanClassOnPostion(int position)
{



	return chessmanClass();
}

void setChessmanOnPosition(chessmanClass chessman, int position)
{

}