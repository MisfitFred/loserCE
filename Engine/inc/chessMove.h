#pragma once

#include "chessmanclass.h"

class chessMove
{
	 
public:
	const int oldPosition;
	const int newPosition;
	const chessmanClass chessman;
	
	chessMove(int from, int to, chessmanClass chessman) : oldPosition{ from }, newPosition{ to }, chessman{chessman} {};
	chessMove(unsigned char postionFrom[2], unsigned char postionTo[2], chessmanClass chessman) : 
		chessman{ chessman }, 
		oldPosition{ chessMove::Coordiante2Simple(postionFrom)},
		newPosition{ chessMove::Coordiante2Simple(postionTo)} {};
	~chessMove() {};
	static unsigned char Coordiante2Simple(unsigned char postionFrom[2]);
};

