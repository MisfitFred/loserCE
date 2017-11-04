

#include "gtest/gtest.h"
#include "emplacement.h"

TEST(Emplacement_defaultConstructor, getPosOf_whitePawn)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_whitePawn().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_whiteRook)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_whiteRook().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_whiteKnight)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_whiteKnight().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_whiteBishop)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_whiteBishop().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_whiteQueen)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_whiteQueen().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_whiteKing)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_whiteKing().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_blackPawn)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_blackPawn().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_blackRook)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_blackRook().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_blackKnight)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_blackKnight().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_blackBishop)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_blackBishop().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_blackQueen)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_blackQueen().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_blackKing)
{
	emplacement testEmplacement;
	int result = testEmplacement.getPosOf_blackKing().count();
	ASSERT_EQ(0x0, result);
}

TEST(Emplacement_defaultConstructor, getEmptyFields)
{
	emplacement testEmplacement;
	int result = testEmplacement.getEmptyFields().count();
	ASSERT_EQ(64, result);
}

TEST(Emplacement_defaultConstructor, getOccupiedFields)
{
	emplacement testEmplacement;
	int result = testEmplacement.getOccupiedFields().count();
	ASSERT_EQ(0, result);
}

TEST(Emplacement_defaultConstructor, getBlackOccupiedFields)
{
	emplacement testEmplacement;
	int result = testEmplacement.getBlackOccupiedFields().count();
	ASSERT_EQ(0, result);
}

TEST(Emplacement_defaultConstructor, getWhiteOccupiedFields)
{
	emplacement testEmplacement;
	int result = testEmplacement.getWhiteOccupiedFields().count();
	ASSERT_EQ(0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_Param_whitePawn)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::whitePawn).count();
	ASSERT_EQ(0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_Param_whiteRook)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::whiteRook).count();
	ASSERT_EQ(0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_Param_whiteKnight)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::whiteKnight).count();
	ASSERT_EQ(0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_Param_whiteBishop)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::whiteBishop).count();
	ASSERT_EQ(0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_Param_whiteQueen)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::whiteQueen).count();
	ASSERT_EQ(0, result);
}
TEST(Emplacement_defaultConstructor, getPosOf_Param_whiteKing)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::whiteKing).count();
	ASSERT_EQ(0, result);
}
TEST(Emplacement_defaultConstructor, getPosOf_Param_blackPawn)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::blackPawn).count();
	ASSERT_EQ(0, result);
}
TEST(Emplacement_defaultConstructor, getPosOf_Param_blackRook)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::blackRook).count();
	ASSERT_EQ(0, result);
}
TEST(Emplacement_defaultConstructor, getPosOf_Param_blackKnight)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::blackKnight).count();
	ASSERT_EQ(0, result);
}
TEST(Emplacement_defaultConstructor, getPosOf_Param_blackBishop)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::blackBishop).count();
	ASSERT_EQ(0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_Param_blackQueen)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::blackQueen).count();
	ASSERT_EQ(0, result);
}
TEST(Emplacement_defaultConstructor, getPosOf_Param_blackKing)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::blackKing).count();
	ASSERT_EQ(0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_Param_black)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::black).count();
	ASSERT_EQ(0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_Param_white)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::white).count();
	ASSERT_EQ(0, result);
}

TEST(Emplacement_defaultConstructor, getPosOf_Param_none)
{
	emplacement testEmplacement;
	int result;

	result = testEmplacement.getPosOf(chessmanClass::none).count();
	ASSERT_EQ(64, result);
}

