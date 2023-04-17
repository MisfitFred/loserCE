#include "chessMove.h"
namespace engine {

	unsigned char chessMove::Coordiante2Simple(unsigned char postionFrom[2])
	{
		if ((postionFrom[0] < 8) & (postionFrom[1] < 8))
		{
			return 8 * postionFrom[1] + postionFrom[0];
		}
		else
		{
			return 65; //error 
		}
	}
}
