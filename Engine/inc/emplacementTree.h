#pragma once
#include "emplacement.h"
#include "emplacementNode.h"
#include <vector>

namespace engine {

	class emplacementTree{

	public:
		emplacementTree(emplacement startEmplacement) {};
		void startGenerateTree(emplacement newEmplacement) {};
		void setGenerationDepth(unsigned int depth) { generationDepth = depth; };
		
	private:
			emplacementNode *rootNode;
			unsigned int generationDepth;
	};
}