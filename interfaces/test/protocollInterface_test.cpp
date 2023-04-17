#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <thread>
#include "stdInOut.h"
//#include <sstream>

using namespace std;
using namespace chessInterface;

/*
TEST_F(derivedUciTest, worker_receiveCommand_uci) {
	string output;
	bool testOK = true;
	uciTestObject->consoleInputBufferStream << "uci" << endl;
	uciTestObject->waitForTerminate();

	//uciTestObject->callWorker();
	
	testOK = uciTestObject->getConsoleOnput(output);
	ASSERT_EQ(output, "id name loserCE 0.0a");
	ASSERT_TRUE(testOK);

	testOK = uciTestObject->getConsoleOnput(output);
	ASSERT_EQ(output, "id author Matthias N.");
	ASSERT_TRUE(testOK);
}

*/


#if 0
TEST(chessmanPawn, GroundLine_Border_a_emptyFieldsAhead)
{

	emplacement *testEmplacement = new emplacement();
	testEmplacement->setChessmanOnPosition(chessmanType::whitePawn, 8);

	std::vector<chessMove> result = chessmanPawn::getMoves(testEmplacement,chessmanSide::white);
	std::vector<chessMove> ref;

	chessMove* refMove01 = new chessMove(8,16,chessmanType::whitePawn);
	chessMove* refMove02 = new chessMove(8,24,chessmanType::whitePawn);
	
	ref.push_back(*refMove01);
	ref.push_back(*refMove02);


	ASSERT_EQ(result.size(), ref.size());
	std::vector<chessMove>::const_iterator refIterator = ref.begin();
	
	std::vector<chessMove>::const_iterator res;

	for (std::vector<chessMove>::const_iterator refIterator = ref.begin(); refIterator!= ref.end(); refIterator++){
		bool found = false;
		std::vector<chessMove>::const_iterator resIterator = result.begin();
		for (std::vector<chessMove>::const_iterator resIterator = result.begin(); resIterator != result.end(); resIterator++)
		{
			if (resIterator->newPosition == refIterator->newPosition &&   resIterator->oldPosition == refIterator->oldPosition)
			{
				found = true;
				res = resIterator;
			}
		}
		ASSERT_TRUE(found);
		//ASSERT_EQ(*refIterator, *resIterator);
	}

}
#endif