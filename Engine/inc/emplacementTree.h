#pragma once
#include "emplacement.h"
#include "emplacementNode.h"
#include <vector>
#include "chessMove.h"

namespace engine {
	class emplacementTree {

	public:
		emplacementTree(emplacement startEmplacement) {};
		void startGenerateTree(emplacement newEmplacement) {};
		void startGenerateTree() {};
		void setGenerationDepth(unsigned int depth) { generationDepth = depth; };
		chessMove getBestMove(void) {chessMove move(0,1,chessmanType::blackBishop); return  move;}
	private:
			emplacementNode *rootNode;
			unsigned int generationDepth;
	};
}