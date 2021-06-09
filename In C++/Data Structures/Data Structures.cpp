// Data Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Circular_array.h"

void circular_arrays();
bool is_digit(std::string input);

int main()
{
	circular_arrays();
}

// checks if user input is a digit
bool is_digit(std::string input) {

	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {		// if this input is not a digit
			return false;
		}
	}

	return true;	// the only way to reach here is if everything is a digit

}

// function that summons circular arrays
void circular_arrays() {
	
	std::string u_input;
	int nums = 0;
	bool valid = false;

	// a do while loop to make sure we get the right data type for the size
	do {
		std::cout << "What size would you like for the circular array?\n";		// prompt

		std::cin >> u_input;		// get user input

		if (!is_digit(u_input)) {		// if we do not get the right data type
			valid = false;		// continue our loop
			std::cout << "Invalid input! Please enter an integer.\n";
		}
		else {
			valid = true;		// exit our loop
		}
		
	} while (!valid);

	C_array list(std::stoi(u_input));		// initialize our list

	// a do while loop to get all the data to our list
	do {
		std::cout << "Enter a number for the list, and anything else to exit.\n";		// prompt
		std::cin >> u_input;		// get input

		if (is_digit(u_input)) {
			list.push(std::stoi(u_input));		// data is pushed into the list

			std::cout << "\nThe list: ";
			list.out_order();
			std::cout << "\n";
		}
		else {
			valid = false;		// exit the loop
		}

	} while (valid);

}
