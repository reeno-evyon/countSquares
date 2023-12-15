#include "squares_counter.h"

// Default constructor definition
SquaresCounter::SquaresCounter(): n(0), totalSquares(0) {}

SquaresCounter::~SquaresCounter() {}

void SquaresCounter::setSquareSize(const std::string& str){
	if(isNumeric(str)){
		n = str.c_str();
		// Automatically calculate total number of squares once the value is set.
		calculateTotalSquares();
	} else{
		// Change the parameters to default values
		n = 0;
		totalSquares = 0;
		throw std::invalid_argument("Invalid input. This only accepts natural numbers (1, 2, 3, ...)");
	}
}

void SquaresCounter::calculateTotalSquares(){
    	// Logic to count the number of squares
	// Total squares = 1^2 + 2^2 + 3^2 + ....+ n^2
    	// Formula for Sum of squares of first n natural numbers: [n(n+1)(2n+1)] / 6.
	totalSquares = (n*(n+1)*((2*n)+1))/6;
}

mpz_class SquaresCounter::getSquareSize(){ return n; }
mpz_class SquaresCounter::getTotalSquares(){ return totalSquares; }

bool SquaresCounter::isNumeric(const std::string& str) const {
	for (char c : str) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
	return true;
}
