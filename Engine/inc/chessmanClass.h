#pragma once
#include <vector>
#include "chessMove.h"
#include "chessmanSide.h"
namespace engine{

 class  chessmanClass {
public:
	const chessmanSide side;

	chessmanClass(chessmanSide cSide) : side{ cSide } {};
	virtual std::vector<chessMove> getMoves(unsigned int position) { std::vector<chessMove> ret;  return ret; };
};

class chessmanPawn : public chessmanClass {

	static std::vector<chessMove> getMoves(unsigned int position) { std::vector<chessMove> ret;  return ret; };
};

class chessmanRook : public chessmanClass {

	static std::vector<chessMove> getMoves(unsigned int position) { std::vector<chessMove> ret;  return ret; };
};

class chessmanKnight : public chessmanClass {

	static std::vector<chessMove> getMoves(unsigned int position) { std::vector<chessMove> ret;  return ret; };
};

class chessmanQueen : public chessmanClass {

	static std::vector<chessMove> getMoves(unsigned int position) { std::vector<chessMove> ret;  return ret; };
};

class chessmanKing : public chessmanClass {

	static std::vector<chessMove> getMoves(unsigned int position) { std::vector<chessMove> ret;  return ret; };
};
}