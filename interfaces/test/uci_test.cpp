#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <thread>
#include "uci.h"
#include "stdInOut.h"
//#include <sstream>
using ::testing::AtLeast;
using namespace std;
using namespace chessInterface;


//define a virtual class for for stdInOut as generic interface 

class Mock_inOutInterface : public inOutInterface {
public:
	MOCK_METHOD1(output, void(const string output));	
	MOCK_METHOD0(start, void());
	MOCK_METHOD0(stop, void());
};


class derivedUciTest : public ::testing::Test {
protected:
	virtual void SetUp() {

		uciTestObject = new uci( &Mock_inOutObject);
	}

	virtual void TearDown() {
		delete uciTestObject;
	}
	Mock_inOutInterface Mock_inOutObject;
	uci *uciTestObject;
	
};

/*****************************************************************//**
* \brief Process the UCI "uci" command
* Requirement from UCI specification:
*	Tell engine to use the uci(universal chess interface), this will be
*  sent once as a first command after program boot to tell the engine
*  to switch to uci mode. After receiving the uci command the engine
*  must identify itself with the "id" command and send the "option"
*  commands to tell the GUI which engine settings the engine supports
*  if any. After that the engine should send "uciok" to acknowledge
*  the uci mode. If no uciok is sent within a certain time period, the
*  engine task will be killed by the GUI.
*********************************************************************/
TEST_F(derivedUciTest, processCommand_uci_lowerCase) {
	string testCommand = "uci";
	bool testOK = true;
	EXPECT_CALL(Mock_inOutObject, output("id name loserCE 0.0a")).Times(AtLeast(1));
	EXPECT_CALL(Mock_inOutObject, output("id author Matthias N.")).Times(AtLeast(1));
	EXPECT_CALL(Mock_inOutObject, output("uciok")).Times(AtLeast(1));
	uciTestObject->processCommand(testCommand);
}

#if 0
testOK = uciTestObject->getConsoleOnput(output);
ASSERT_EQ(output, "id name loserCE 0.0a");
ASSERT_TRUE(testOK);

testOK = uciTestObject->getConsoleOnput(output);
ASSERT_EQ(output, "id author Matthias N.");
ASSERT_TRUE(testOK);
#endif 


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