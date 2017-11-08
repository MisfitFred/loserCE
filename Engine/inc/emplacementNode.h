#pragma once
#include "emplacement.h"
#include <vector>

namespace engine {

	class emplacementNode{

	public:
		unsigned int performance = 0;
		const emplacement *emplacementBase;
		const emplacementNode *parent;
		std::vector<emplacementNode> children;
		emplacementNode(emplacement *emplacementBase, emplacementNode *parent) : emplacementBase{ emplacementBase }, parent{ parent } {};
	};
}