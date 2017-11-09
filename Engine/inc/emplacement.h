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

	std::vector<chessMove> getPossibleMoves(chessmanSide side);
	std::bitset<64> getPosOf(chessmanType chessman);
	std::bitset<64> getPosOf(chessmanSide side);
	std::bitset<64> getEmptyFields();
	std::bitset<64> getOccupiedFields();
	std::bitset<64> getBlackOccupiedFields();
	std::bitset<64> getWhiteOccupiedFields();
	void setChessmanOnPosition(chessmanType chessman, int position);
	void removeChessmanOnPosition(chessmanType chessman, int position);
	void performMove(chessMove move);

	chessmanType getChessmanClassOnPostion(int position);

	emplacement(emplacement *originChessboard)  
			{ std::copy(std::begin(chessboard), std::end(chessboard), std::begin(originChessboard->chessboard)); };
	emplacement();
	emplacement(emplacement *originChessboard, chessMove move);
	~emplacement();

protected:
	
	std::array<std::bitset<64>, 12> chessboard;

private:

	bool areOnlyOneChessmanPerField(void);
};

}