#pragma once
#include <vector>
#include "chessMove.h"
#include "chessmanSide.h"
#include "emplacement.h"
namespace engine{

class  chessmanClass {
public:
	const chessmanSide side;

	chessmanClass(chessmanSide cSide) : side{ cSide } {};
	virtual std::vector<chessMove> getMoves(emplacement *board, unsigned int position, chessmanSide side) = 0;
};


class chessmanPawn : public chessmanClass {
	public: 
		static std::vector<chessMove> getMoves(emplacement *board, chessmanSide side);
};
#if 0
class chessmanRook : public chessmanClass {

	static std::vector<chessMove> getMoves(emplacement *board, unsigned int position, chessmanSide side) { std::vector<chessMove> ret;  return ret; };
};

class chessmanKnight : public chessmanClass {

	static std::vector<chessMove> getMoves(emplacement *board, unsigned int position, chessmanSide side) { std::vector<chessMove> ret;  return ret; };
};

class chessmanQueen : public chessmanClass {

	static std::vector<chessMove> getMoves(emplacement *board, unsigned int position, chessmanSide side) { std::vector<chessMove> ret;  return ret; };
};

class chessmanKing : public chessmanClass {

	static std::vector<chessMove> getMoves(emplacement *board, unsigned int position, chessmanSide side) { std::vector<chessMove> ret;  return ret; };
};

#endif
}