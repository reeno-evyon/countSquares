#ifndef SQUARES_COUNTER_H
#define SQUARES_COUNTER_H

#include <gmp.h>
#include <gmpxx.h>

class SquaresCounter {
private:
	mpz_class n;
	mpz_class totalSquares;

public:
	SquaresCounter();
	~SquaresCounter();

	void setSquareSize(const std::string& str);
	void calculateTotalSquares();

	mpz_class getSquareSize();
	mpz_class getTotalSquares();

private:
	bool isNumeric(const std::string& str) const;
};

#endif // SQUARES_COUNTER_H
