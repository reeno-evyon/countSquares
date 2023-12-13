#include "ui_utils.h"

int main() {
	// Continue executing the loop until the function completes successfully.
	while (getInputAndCalculate()) {
		// Add a new line for invalid input
		std::cout << std::endl;
	}
    	return 0;
}
