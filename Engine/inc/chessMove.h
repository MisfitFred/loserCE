#pragma once

#include "chessmanType.h"
namespace engine {
	class chessMove
	{

	public:
		const int oldPosition;
		const int newPosition;
		const chessmanType chessman;

		chessMove(int from, int to, chessmanType chessman) : oldPosition{ from }, newPosition{ to }, chessman{ chessman } {};
		~chessMove() {};
		static unsigned char Coordiante2Simple(unsigned char postionFrom[2]);
	};
}

