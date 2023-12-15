#include <gtest/gtest.h>
#include "squares_counter.h"

class SquaresCounterTest : public testing::Test {
protected:
	SquaresCounter *squaresCounterTestObj;
	void SetUp(){
		squaresCounterTestObj = new SquaresCounter();
	}

	void TearDown(){
		delete squaresCounterTestObj;
	}
};

TEST_F(SquaresCounterTest, Check_init_values) {
	ASSERT_EQ(squaresCounterTestObj->getSquareSize(), 0);
	ASSERT_EQ(squaresCounterTestObj->getTotalSquares(), 0);
}

TEST_F(SquaresCounterTest, Count_n_0) {
	squaresCounterTestObj->setSquareSize("0");
	ASSERT_EQ(squaresCounterTestObj->getTotalSquares(), 0);
}

TEST_F(SquaresCounterTest, Count_n_1) {
	squaresCounterTestObj->setSquareSize("1");
	ASSERT_EQ(squaresCounterTestObj->getTotalSquares(), 1);
}

TEST_F(SquaresCounterTest, Count_n_3) {
	squaresCounterTestObj->setSquareSize("3");
	ASSERT_EQ(squaresCounterTestObj->getTotalSquares(), 14);
}

TEST_F(SquaresCounterTest, Negative_number) {
	EXPECT_THROW(squaresCounterTestObj->setSquareSize(""), std::invalid_argument);
}

TEST_F(SquaresCounterTest, Empty_input) {
	EXPECT_THROW(squaresCounterTestObj->setSquareSize(""), std::invalid_argument);
}

TEST_F(SquaresCounterTest, NonNumeric_argument_exception) {
	// First pass a valid value and then try invalid value
	squaresCounterTestObj->setSquareSize("3");
	ASSERT_EQ(squaresCounterTestObj->getTotalSquares(), 14);

	EXPECT_THROW(squaresCounterTestObj->setSquareSize("a"), std::invalid_argument);
	
	// With an exception, the internal variables should change to default value.
	ASSERT_EQ(squaresCounterTestObj->getSquareSize(), 0);
	ASSERT_EQ(squaresCounterTestObj->getTotalSquares(), 0);
}

