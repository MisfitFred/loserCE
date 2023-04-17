#include "emplacement.h"
#include "string.h"
#include <exception>

namespace engine{

	using namespace std;

	constexpr const unsigned int operator !=(chessmanType a, unsigned int b) { return static_cast<unsigned int>(a) != b; };
	constexpr unsigned int operator ==(chessmanType a, unsigned int b) { return static_cast<unsigned int>(a) == b; };
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
	{
		
	}

	emplacement::emplacement( emplacement * originChessboard, chessMove move)
	{
		std::copy(std::begin(chessboard), std::end(chessboard), std::begin(originChessboard->chessboard));
		performMove(move);
	}

	void emplacement::startEmplacement()
	{
		setChessmanOnPosition(chessmanType::whiteRook, 0);
		setChessmanOnPosition(chessmanType::whiteKnight, 1);
		setChessmanOnPosition(chessmanType::whiteBishop, 2);
		setChessmanOnPosition(chessmanType::whiteQueen, 3);
		setChessmanOnPosition(chessmanType::whiteKing, 4);
		setChessmanOnPosition(chessmanType::whiteBishop, 5);
		setChessmanOnPosition(chessmanType::whiteKnight, 6);
		setChessmanOnPosition(chessmanType::whiteRook, 7);
		setChessmanOnPosition(chessmanType::whitePawn, 8);
		setChessmanOnPosition(chessmanType::whitePawn, 9);
		setChessmanOnPosition(chessmanType::whitePawn, 10);
		setChessmanOnPosition(chessmanType::whitePawn, 11);
		setChessmanOnPosition(chessmanType::whitePawn, 12);
		setChessmanOnPosition(chessmanType::whitePawn, 13);
		setChessmanOnPosition(chessmanType::whitePawn, 14);
		setChessmanOnPosition(chessmanType::whitePawn, 15);

		setChessmanOnPosition(chessmanType::blackPawn, 48);
		setChessmanOnPosition(chessmanType::blackPawn, 49);
		setChessmanOnPosition(chessmanType::blackPawn, 50);
		setChessmanOnPosition(chessmanType::blackPawn, 51);
		setChessmanOnPosition(chessmanType::blackPawn, 52);
		setChessmanOnPosition(chessmanType::blackPawn, 53);
		setChessmanOnPosition(chessmanType::blackPawn, 54);
		setChessmanOnPosition(chessmanType::blackPawn, 55);
		setChessmanOnPosition(chessmanType::blackRook, 56);
		setChessmanOnPosition(chessmanType::blackKnight, 57);
		setChessmanOnPosition(chessmanType::blackBishop, 58);
		setChessmanOnPosition(chessmanType::blackQueen, 59);
		setChessmanOnPosition(chessmanType::blackKing, 60);
		setChessmanOnPosition(chessmanType::blackBishop, 61);
		setChessmanOnPosition(chessmanType::blackKnight, 62);
		setChessmanOnPosition(chessmanType::blackRook, 63);
	}

	emplacement::emplacement(emplacement *originChessboard)
	{
		std::copy(std::begin(chessboard), std::end(chessboard), std::begin(originChessboard->chessboard));
	};

	emplacement::~emplacement()
	{

	}

	bitset<64> emplacement::getPosOf(chessmanType chessman)
	{
	
		bitset<64> ret;
		switch (chessman) {
			case chessmanType::whitePawn:
				ret = this->chessboard[whitePawn];
			break;
			case chessmanType::whiteRook:
				ret = this->chessboard[whiteRook];
			break;
			case chessmanType::whiteKnight:
				ret = this->chessboard[whiteKnight];
			break;
			case chessmanType::whiteBishop:
				ret = this->chessboard[whiteBishop];
			break;
			case chessmanType::whiteQueen:
				ret = this->chessboard[whiteQueen];
			break;
			case chessmanType::whiteKing:
				ret = this->chessboard[whiteKing];
			break;
			case chessmanType::blackPawn:
				ret = this->chessboard[blackPawn];
			break;
			case chessmanType::blackRook:
				ret = this->chessboard[blackRook];
			break;
			case chessmanType::blackKnight:
				ret = this->chessboard[blackKnight];
			break;
			case chessmanType::blackBishop:
				ret = this->chessboard[blackBishop];
			break;
			case chessmanType::blackQueen:
				ret = this->chessboard[blackQueen];
			break;
			case chessmanType::blackKing:
				ret = this->chessboard[blackKing];
			break;
			case chessmanType::none:
				ret = getEmptyFields();
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

	bitset<64> emplacement::getOccupiedFields(chessmanSide side)
	{
		bitset<64> ret;
		if (side == chessmanSide::black) {
			ret= chessboard[blackPawn] | chessboard[blackBishop] | chessboard[blackKing]
				| chessboard[blackKnight] | chessboard[blackQueen] | chessboard[blackRook];
		}
		else if (side == chessmanSide::white) {
			ret = chessboard[whitePawn] | chessboard[whiteBishop] | chessboard[whiteKing]
				| chessboard[whiteKnight] | chessboard[whiteQueen] | chessboard[whiteRook];
		}

		return ret;
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

		chessmanType ret;
		if (position < 64)
		{
			if (this->chessboard[whitePawn].test(position))
			{
				ret = chessmanType::whitePawn;
			}
			if (this->chessboard[whiteRook].test(position))
			{
				ret = chessmanType::whiteRook;
			}
			if (this->chessboard[whiteKnight].test(position))
			{
				ret = chessmanType::whiteKnight;
			}
			if (this->chessboard[whiteBishop].test(position))
			{
				ret = chessmanType::whiteBishop;
			}
			if (this->chessboard[whiteQueen].test(position))
			{
				ret = chessmanType::whiteQueen;
			}
			if (this->chessboard[whiteKing].test(position))
			{
				ret = chessmanType::whiteKing;
			}
			if (this->chessboard[blackPawn].test(position))
			{
				ret = chessmanType::blackPawn;
			}
			if (this->chessboard[blackRook].test(position))
			{
				ret = chessmanType::blackRook;
			}
			if (this->chessboard[blackKnight].test(position))
			{
				ret = chessmanType::blackKnight;
			}
			if (this->chessboard[blackBishop].test(position))
			{
				ret = chessmanType::blackBishop;
			}
			if (this->chessboard[blackQueen].test(position))
			{
				ret = chessmanType::blackQueen;
			}
			if (this->chessboard[blackKing].test(position))
			{
				ret = chessmanType::blackKing;
			}
		}
		else
		{
			ret = chessmanType::none;
		}
		return ret;
	}

	void emplacement::setChessmanOnPosition(chessmanType chessman, int position)
	{
		switch (chessman) {
		case chessmanType::whitePawn:
			this->chessboard[whitePawn].set(position);
			break;
		case chessmanType::whiteRook:
			this->chessboard[whiteRook].set(position);
			break;
		case chessmanType::whiteKnight:
			this->chessboard[whiteKnight].set(position);
			break;
		case chessmanType::whiteBishop:
			this->chessboard[whiteBishop].set(position);
			break;
		case chessmanType::whiteQueen:
			this->chessboard[whiteQueen].set(position);
			break;
		case chessmanType::whiteKing:
			this->chessboard[whiteKing].set(position);
			break;
		case chessmanType::blackPawn:
			this->chessboard[blackPawn].set(position);
			break;
		case chessmanType::blackRook:
			this->chessboard[blackRook].set(position);
			break;
		case chessmanType::blackKnight:
			this->chessboard[blackKnight].set(position);
			break;
		case chessmanType::blackBishop:
			this->chessboard[blackBishop].set(position);
			break;
		case chessmanType::blackQueen:
			this->chessboard[blackQueen].set(position);
			break;
		case chessmanType::blackKing:
			this->chessboard[blackKing].set(position);
			break;
		case chessmanType::none:
			getEmptyFields();
			break;
		};
	}

	bool emplacement::areOnlyOneChessmanPerField(void) {

	
		return true;
	}

}