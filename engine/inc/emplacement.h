#pragma once
#include "Types.h"
#include "chessmanType.h"
#include "chessMove.h"
#include <array>
#include <bitset>
#include "chessmanSide.h"
#include <vector>

namespace engine{
class emplacement
{

public: 
	/**/
	std::bitset<64> getPosOf(chessmanType chessman);
	std::bitset<64> getEmptyFields();
	std::bitset<64> getOccupiedFields();
	std::bitset<64> getOccupiedFields(chessmanSide side);
	void setChessmanOnPosition(chessmanType chessman, int position);
	void removeChessmanOnPosition(chessmanType chessman, int position);
	void performMove(chessMove move);

	chessmanType getChessmanClassOnPostion(int position);
	emplacement();
	emplacement(emplacement *originChessboard);
	emplacement(emplacement *originChessboard, chessMove move);
	void startEmplacement();
	~emplacement();

protected:
	std::array<std::bitset<64>, 12> chessboard;
	bool longCastlingWhite;
	bool shortCastlingWhite;
	bool longCastlingBlack;
	bool shortCastlingBlack;
	short int numberOfChessMoves;
	short int numberOfChessMovesTillLastPawnMove;
	short int EnPassant;

private:
	bool areOnlyOneChessmanPerField(void);
};

}