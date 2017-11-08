#include "stdafx.h"
#include "emplacement.h"
#include "string.h"
#include <exception>

namespace engine{

	using namespace std;
	/*some ugly type casts due to performance increase */
	static_assert(chessmanType::whitePawn == 0u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static_assert(chessmanType::whiteRook == 1u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static_assert(chessmanType::whiteKnight == 2u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static_assert(chessmanType::whiteBishop == 3u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static_assert(chessmanType::whiteQueen == 4u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static_assert(chessmanType::whiteKing == 5u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static_assert(chessmanType::blackPawn == 6u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static_assert(chessmanType::blackRook == 7u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static_assert(chessmanType::blackKnight == 8u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static_assert(chessmanType::blackBishop == 9u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static_assert(chessmanType::blackQueen == 10u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static_assert(chessmanType::blackKing == 11u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	//static_assert(chessmanType::black == 12u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	//static_assert(chessmanType::white == 13u, "Assumend enumeration of chesmmanClass does not fit to the implementation of emplacement class");
	static constexpr int whitePawn = static_cast<int>(chessmanType::whitePawn);
	static constexpr int whiteRook = static_cast<int>(chessmanType::whiteRook);
	static constexpr int whiteKnight = static_cast<int>(chessmanType::whiteKnight);
	static constexpr int whiteBishop = static_cast<int>(chessmanType::whiteBishop);
	static constexpr int whiteQueen = static_cast<int>(chessmanType::whiteQueen);
	static constexpr int whiteKing = static_cast<int>(chessmanType::whiteKing);
	static constexpr int blackPawn = static_cast<int>(chessmanType::blackPawn);
	static constexpr int blackRook = static_cast<int>(chessmanType::blackRook);
	static constexpr int blackKnight = static_cast<int>(chessmanType::blackKnight);
	static constexpr int blackBishop = static_cast<int>(chessmanType::blackBishop);
	static constexpr int blackQueen = static_cast<int>(chessmanType::blackQueen);
	static constexpr int blackKing = static_cast<int>(chessmanType::blackKing);
	//static constexpr int black = static_cast<int>(chessmanType::black);
	//static constexpr int white = static_cast<int>(chessmanType::white);


	emplacement::emplacement()
	{/*
		for ( auto i: chessboard) {
			i = 0;
		}*/
	}

	/*
	emplacement::emplacement(emplacement *originChessboard)
	{
		//todo better use c++ mechanisms, perhaps a reference can be fit much better
		//std::copy(std::begin(chessboard), std::end(chessboard), std::begin(originChessboard->chessboard));
		//memcpy((void*)chessboard, originChessboard->chessboard, sizeof(chessboard));
	}*/

	emplacement::emplacement( emplacement * originChessboard, chessMove move)
	{
		std::copy(std::begin(chessboard), std::end(chessboard), std::begin(originChessboard->chessboard));
		performMove(move);
	}

	emplacement::~emplacement()
	{
		//delete chessboard; 
	}



	bitset<64> emplacement::getPosOf(chessmanType chessman)
	{
	
		bitset<64> ret;
		switch (chessman) {
			case chessmanType::whitePawn:
				this->chessboard[whitePawn];
			break;
			case chessmanType::whiteRook:
				this->chessboard[whiteRook];
			break;
			case chessmanType::whiteKnight:
				this->chessboard[whiteKnight];
			break;
			case chessmanType::whiteBishop:
				this->chessboard[whiteBishop];
			break;
			case chessmanType::whiteQueen:
				this->chessboard[whiteQueen];
			break;
			case chessmanType::whiteKing:
				this->chessboard[whiteKing];
			break;
			case chessmanType::blackPawn:
				this->chessboard[blackPawn];
			break;
			case chessmanType::blackRook:
				this->chessboard[blackRook];
			break;
			case chessmanType::blackKnight:
				this->chessboard[blackKnight];
			break;
			case chessmanType::blackBishop:
				this->chessboard[blackBishop];
			break;
			case chessmanType::blackQueen:
				this->chessboard[blackQueen];
			break;
			case chessmanType::blackKing:
				this->chessboard[blackKing];
			break;
			case chessmanType::none:
				ret = getEmptyFields();
			break;
		};

		return ret;
	}

	


	std::bitset<64> emplacement::getPosOf(chessmanSide side) {
		bitset<64> ret;
		switch (side) {
			case chessmanSide::black:
				ret = getWhiteOccupiedFields();
				break;
			case chessmanSide::white:
				ret = getBlackOccupiedFields();
				break;
		};
		return ret;
	}

	bitset<64> emplacement::getEmptyFields()
	{
		bitset<64> emptyFileds = 0;
		for (unsigned int i = 0; i < chessboard.size(); i++)
		{
			emptyFileds = chessboard[i] | emptyFileds;
		}
		return ~emptyFileds;
	
	}

	bitset<64> emplacement::getOccupiedFields()
	{
		bitset<64> occupiedFields = 0;
		for (unsigned int i = 0; i < chessboard.size(); i++)
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

	void emplacement::removeChessmanOnPosition(chessmanType chessman, int position)
	{
	}

	void emplacement::performMove(chessMove move)
	{
		int move_chessman_int = static_cast<int>(move.chessman);
		const chessmanType chessmanClassOnNewPosition = getChessmanClassOnPostion(move.newPosition);

		//check if such a chessmanType is on old position, if yes perform the move
		if (chessboard[move_chessman_int].test(move.oldPosition))
		{

			chessboard[move_chessman_int].reset(move.oldPosition);

			//check if a chessman is already on the new position, if yes remove it. 
			if (chessmanClassOnNewPosition == chessmanType::none)
			{
				chessboard[static_cast<int>(chessmanClassOnNewPosition)].reset(move.newPosition);
			}

			chessboard[move_chessman_int].set(move.newPosition);
		}
		else
		{

		}
	}
	chessmanType emplacement::getChessmanClassOnPostion(int position)
	{

		return chessmanType();
	}

	void emplacement::setChessmanOnPosition(chessmanType chessman, int position)
	{

	}

	bool emplacement::areOnlyOneChessmanPerField(void) {

	
		return true;
	}

}