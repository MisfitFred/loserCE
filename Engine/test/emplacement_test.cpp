#include "gtest/gtest.h"
#include "emplacement.h"

class emplacementDerived : public emplacement {
public:
	array<bitset<64>, 12> getChessboard() { return chessboard; };
	//void setChessboard(array<bitset<64>, 12> board) { std::copy(std::begin(chessboard), std::end(chessboard), std::begin(board)); };
};

TEST(Emplacement_defaultConstructor, chessboardValues)
{
	emplacementDerived testEmplacement;

	array<bitset<64>, 12> ref; 

	for (auto i : ref) {
		i = 0;
	}
	array<bitset<64>, 12> result = testEmplacement.getChessboard();
	
	//ASSERT_EQ(result, ref);
}


TEST(Emplacement_defaultConstructor, chessboardValues)
{
	emplacementDerived testEmplacement;

	array<bitset<64>, 12> ref;

	for (auto i : ref) {
		i = 0;
	}
	array<bitset<64>, 12> result = testEmplacement.getChessboard();

	//ASSERT_EQ(result, ref);
}


