#include "gtest/gtest.h"
#include "chessmanClass.h"

using namespace std;
using namespace engine;

//! Using the google test framework, check all elements of two containers
#define EXPECT_ITERABLE_BASE( PREDICATE, REFTYPE, TARTYPE, ref, target) \
    { \
    const REFTYPE& ref_(ref); \
    const TARTYPE& target_(target); \
    REFTYPE::const_iterator refIter = ref_.begin(); \
    TARTYPE::const_iterator tarIter = target_.begin(); \
    unsigned int i = 0; \
    while(refIter != ref_.end()) { \
        if ( tarIter == target_.end() ) { \
            ADD_FAILURE() << #target " has a smaller length than " #ref ; \
            break; \
        } \
        PREDICATE(* refIter, * tarIter) \
            << "Containers " #ref  " (refIter) and " #target " (tarIter)" \
               " differ at index " << i; \
        ++refIter; ++tarIter; ++i; \
    } \
    EXPECT_TRUE( tarIter == target_.end() ) \
        << #ref " has a smaller length than " #target ; \
    }

//! Check that all elements of two same-type containers are equal
#define EXPECT_ITERABLE_EQ( TYPE, ref, target) \
    EXPECT_ITERABLE_BASE( EXPECT_EQ, TYPE, TYPE, ref, target )

//! Check that all elements of two different-type containers are equal
#define EXPECT_ITERABLE_EQ2( REFTYPE, TARTYPE, ref, target) \
    EXPECT_ITERABLE_BASE( EXPECT_EQ, REFTYPE, TARTYPE, ref, target )

//! Check that all elements of two same-type containers of doubles are equal
#define EXPECT_ITERABLE_DOUBLE_EQ( TYPE, ref, target) \
    EXPECT_ITERABLE_BASE( EXPECT_DOUBLE_EQ, TYPE, TYPE, ref, target )
 


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
