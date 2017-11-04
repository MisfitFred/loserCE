#pragma once

#include "chessmanclass.h"

class chessMove
{
	 
public:
	const int oldPosition;
	const int newPosition;
	const chessmanClass chessman;
	
	chessMove(int from, int to, chessmanClass chessman) : oldPosition{ from }, newPosition{ to }, chessman{chessman} {};
	~chessMove() {};
	static unsigned char Coordiante2Simple(unsigned char postionFrom[2]);
};

