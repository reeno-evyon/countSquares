#include "ui_utils.h"
#include "squares_counter.h"

int getInputAndCalculate(){
	std::string userInput;
	SquaresCounter squaresCounterObj;

	std::cout << "Enter the square size(n): ";
	std::cin >> userInput;

	try{
		squaresCounterObj.setSquareSize(userInput);

		std::cout << "For n = " << userInput << ", total squares visible: " 
			<< squaresCounterObj.getTotalSquares() << std::endl;
	} catch(const std::exception& e) {
		// Catching an exception and handling it
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

