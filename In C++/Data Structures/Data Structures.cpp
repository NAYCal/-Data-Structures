// Data Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Circular_array.h"

void circular_arrays();

int main()
{
	circular_arrays();
}


// function that summons circular arrays
void circular_arrays() {
	
	int u_input = 0, nums = 0, sizes = 0;
	bool valid = false;

	// a do while loop to make sure we get the right input data type
	do {
		std::cout << "What number would you like to add to the Binary Tree?\n";

		std::cin >> u_input;
		if (!std::cin >> u_input) {
			std::cin.clear();
			std::cin.ignore(254, '\n');
			valid = false;
		}
		else {
	
			valid = true;
			nums++;
		}

	} while ((!valid) && (nums < sizes));


}