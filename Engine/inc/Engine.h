#pragma once
#include "emplacement.h"
#include "chessmanSide.h"
#include <vector>

namespace engine {

	class emplacementNode{

	public:
		emplacement *emplacementBase;
		std::vector<emplacementNode> emplacementLeafs;
	};
}