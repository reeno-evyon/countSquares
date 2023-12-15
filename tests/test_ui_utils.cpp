#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include "ui_utils.h"

class UITest : public testing::Test {
protected:
	std::stringstream input_stream, output_stream, cerr_stream;
	std::streambuf *original_cin, *original_cout, *original_cerr;
	std::string expected_error = "Exception caught: Invalid input. This only accepts natural numbers (1, 2, 3, ...)\n";
	void SetUp(){
		// Redirect cin to input_stream
		original_cin = std::cin.rdbuf();
		std::cin.rdbuf(input_stream.rdbuf());

		// Redirect cout to output_stream
		original_cout = std::cout.rdbuf();
		std::cout.rdbuf(output_stream.rdbuf());	

		// Redirect cerr to error_stream
		original_cerr = std::cerr.rdbuf();
		std::cerr.rdbuf(cerr_stream.rdbuf());
	}

	void TeadDown(){
		// Restore original cin, cout and cerr
		std::cin.rdbuf(original_cin);
		std::cout.rdbuf(original_cout);
		std::cerr.rdbuf(original_cerr);
	}
};


TEST_F(UITest, Check_valid_input) {
	input_stream << "2\n"; // Simulating input "2\n" 

	getInputAndCalculate();

	// Verify output
	std::string expected_output = "total squares visible: 5";
	ASSERT_TRUE(output_stream.str().find(expected_output) != std::string::npos);
}

TEST_F(UITest, Check_large_input) {
	input_stream << "100000000000000\n"; // Simulating input "2\n" 

	getInputAndCalculate();

	// Verify output
	std::string expected_output = "total squares visible: 333333333333338333333333333350000000000000";
	ASSERT_TRUE(output_stream.str().find(expected_output) != std::string::npos);
}
TEST_F(UITest, Check_invalid_input) {
	input_stream << "a\n"; // Simulating invalid input from stdin" 

	getInputAndCalculate();

	// Verify error
	ASSERT_STREQ(cerr_stream.str().c_str(), expected_error.c_str());
}


TEST_F(UITest, Check_decimal_input) {
	// The current implementation doesn't support input with decimal
	input_stream << "3.0\n"; 

	getInputAndCalculate();

	// Verify error
	ASSERT_STREQ(cerr_stream.str().c_str(), expected_error.c_str());
}

TEST_F(UITest, Check_negative_input) {
	// The current implementation doesn't support input with decimal
	input_stream << "-1\n"; 

	getInputAndCalculate();

	// Verify error
	ASSERT_STREQ(cerr_stream.str().c_str(), expected_error.c_str());
}
