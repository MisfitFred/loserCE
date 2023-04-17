#include "gtest/gtest.h"
#include "emplacement.h"

using namespace std;
using namespace engine;


class emplacementDerived : public emplacement  {
public:
	array<bitset<64>, 12> getChessboard() { return chessboard; };

	//void setChessboard(array<bitset<64>, 12> board) { std::copy(std::begin(chessboard), std::end(chessboard), std::begin(board)); };
};

TEST(Emplacement, defaultConstructor_chessboardValues)
{
	emplacementDerived testEmplacement;

	array<bitset<64>, 12> ref; 

	for (auto i : ref) {
		i = 0;
	}
	array<bitset<64>, 12> result = testEmplacement.getChessboard();
	
	ASSERT_EQ(result, ref);
}

TEST(Emplacement, startEmplacement_getEmptyFields)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getEmptyFields();
	bitset<64> ref("0000000000000000111111111111111111111111111111110000000000000000");
 
	ASSERT_EQ(result, ref);
}

TEST(Emplacement, startEmplacement_getOccupiedFields)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getOccupiedFields();
	bitset<64> ref("1111111111111111000000000000000000000000000000001111111111111111");
	ASSERT_EQ(result, ref);
}

TEST(Emplacement, startEmplacement_getOccupiedFields_side_white)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getOccupiedFields(chessmanSide::white);
	bitset<64> ref("0000000000000000000000000000000000000000000000001111111111111111");
	ASSERT_EQ(result, ref);
}

TEST(Emplacement, startEmplacement_getOccupiedFields_side_black)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getOccupiedFields(chessmanSide::black);
	bitset<64> ref("1111111111111111000000000000000000000000000000000000000000000000");
	ASSERT_EQ(result, ref);
}

TEST(Emplacement, startEmplacement_getPosOf_whitePawn)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::whitePawn);
	bitset<64> ref("0000000000000000000000000000000000000000000000001111111100000000");
	ASSERT_EQ(result, ref);
}

TEST(Emplacement, startEmplacement_getPosOf_whiteRook)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::whiteRook);
	bitset<64> ref("0000000000000000000000000000000000000000000000000000000010000001");
	ASSERT_EQ(result, ref);
}

TEST(Emplacement, startEmplacement_getPosOf_whiteKnight)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::whiteKnight);
	bitset<64> ref("0000000000000000000000000000000000000000000000000000000001000010");
	ASSERT_EQ(result, ref);
}
TEST(Emplacement, startEmplacement_getPosOf_whiteBishop)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::whiteBishop);
	bitset<64> ref("0000000000000000000000000000000000000000000000000000000000100100");
	ASSERT_EQ(result, ref);
}
TEST(Emplacement, startEmplacement_getPosOf_whiteQueen)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::whiteQueen);
	bitset<64> ref("0000000000000000000000000000000000000000000000000000000000001000");
	ASSERT_EQ(result, ref);
}
TEST(Emplacement, startEmplacement_getPosOf_whiteKing)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::whiteKing);
	bitset<64> ref("0000000000000000000000000000000000000000000000000000000000010000");
	ASSERT_EQ(result, ref);
}
TEST(Emplacement, startEmplacement_getPosOf_blackPawn)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::blackPawn);
	bitset<64> ref("0000000011111111000000000000000000000000000000000000000000000000");
	ASSERT_EQ(result, ref);
}
TEST(Emplacement, startEmplacement_getPosOf_blackRook)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::blackRook);
	bitset<64> ref("1000000100000000000000000000000000000000000000000000000000000000");
	ASSERT_EQ(result, ref);
}
TEST(Emplacement, startEmplacement_getPosOf_blackKnight)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::blackKnight);
	bitset<64> ref("0100001000000000000000000000000000000000000000000000000000000000");
	ASSERT_EQ(result, ref);
}
TEST(Emplacement, startEmplacement_getPosOf_blackBishop)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::blackBishop);
	bitset<64> ref("0010010000000000000000000000000000000000000000000000000000000000");
	ASSERT_EQ(result, ref);
}
TEST(Emplacement, startEmplacement_getPosOf_blackQueen)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::blackQueen);
	bitset<64> ref("0000100000000000000000000000000000000000000000000000000000000000");
	ASSERT_EQ(result, ref);
}
TEST(Emplacement, startEmplacement_getPosOf_blackKing)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::blackKing);
	bitset<64> ref("0001000000000000000000000000000000000000000000000000000000000000");
	ASSERT_EQ(result, ref);
}
TEST(Emplacement, startEmplacement_getPosOf_none)
{
	emplacementDerived testEmplacement;

	testEmplacement.startEmplacement();

	bitset<64>  result = testEmplacement.getPosOf(chessmanType::none);
	bitset<64> ref("0000000000000000111111111111111111111111111111110000000000000000");
	ASSERT_EQ(result, ref);
}