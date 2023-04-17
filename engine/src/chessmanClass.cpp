#include "chessmanType.h"
#include "chessmanClass.h"
#include <bitset>
#include "chessMove.h"


namespace engine{
	
	std::vector<chessMove> chessmanPawn::getMoves(emplacement * board, chessmanSide side) {
		std::bitset<64> pawnPos;
		std::vector<chessMove> possibleMoves;
		chessmanType pawnType;
		if (side == chessmanSide::black) {
			pawnType = chessmanType::blackPawn;
		}
		else {
			pawnType = chessmanType::whitePawn;
		}

		pawnPos = board->getPosOf(pawnType);

		for (auto position = 0; position < (pawnPos.size() - 8); position++)	{
			if (pawnPos.test(position) == true) {
				/* Plan move 1 field forward */
				if (!board->getOccupiedFields(side).test(position+8)) {
					chessMove move(position, position + 8, pawnType);
					possibleMoves.push_back(move);

					if ((!board->getOccupiedFields(side).test(position + 16)) &&(position<16)) {
						chessMove move(position, position + 16, pawnType);
						possibleMoves.push_back(move);
					}
				}
			}
			
			//board->getEmptyFields();
			
			/*
			"Wenn cPos+8 == empty
			--> nPos = cPos + 8"					
			
			"Wenn ePos == cPos + 7 && cPos % 8 != 0

			"Wenn cPos>7 & cPos<16 &&
			cPos + 8 == empty &&
			cPos + 16 == empty
			--> nPos = cPos + 16"				
			--> nPos = cPos + 9"		

			"Wenn ePos == cPos + 9 && (cPos + 1) % 8 != 0

			*/

		}
		
		return possibleMoves;
	}




}