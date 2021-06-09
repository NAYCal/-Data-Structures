// This file contains the class structure for a circular array list
// Note that the data used in this is for simplicity and can be switched out to be different variable types
// This list is a first in, first out queue so data entered first will be taken out first
#include <iostream>

class C_array		// class definition
{
private:
	int *list;		// what data is stored?
	int size;		// the size of the array
	int start, end, num;		// stores the beginning of the array, end and the number of data within it

public:

	C_array(int u_size) {		// constructor to get the fixed size of the array and reset the start num
		size = u_size;
		list = new int[size];
		start = 0;
		end = 0;
		num = 0;
	}		
	void out_all();		// prints out all elements
	void push(int data);		// pushes elements into the list, replaces the first element if the list is full
	void out_order();		// prints out elements based on start and end
	int pop();		// takes out the 'first' data
};


// prints out all the elements in the list
void C_array::out_all() {

	for (int i = 0; i < num; i++) {
		std::cout << list[i] << " ";
	}
}


// pushes the element into the list
// replaces the first element if the list is full
void C_array::push(int data) {

	if (num == 0) {		// checks if there is no data	
		list[start] = data;		// since it is empty, just add it to the start
		num++;		// increase our num size
		return;		// there is no need to proceed beyond this point
	}

	if (num == size) {		// checks if we have reached our end yet
		list[start] = data;		// replaces the start with the new data
		end = start;		// our new data is our end, so we have to change it to our start

		if (start != (size - 1)) {		// make sure we do not overflow
			start++;		// move our new start to the next in the circle
		}
		else {		// if the start is at the end of the size limit
			start = 0;		// the next in line of the circle has to be in the index 0
		}

		return; // there is no need to proceed after this
	}

	// if the list is neither 'new' or 'full', there must be plenty of space
	num++;		// we increase our number size
	end++;		// we increase our end position
	list[end] = data;		// we add our data

	return;
}

// prints out the array in the order from 'start' to 'end'
void C_array::out_order() {

	for (int i = 0; i < num; i++) {		// loop to print out all items

		std::cout << list[i % num] << " ";
	}
}

// takes out the first element, moving the 'first' element to the next index
int C_array::pop() {

	int item = list[start];		// store what we need to return here

	list[start] = NULL;		// replace this location with NULL
	num--;		// reduce the number size

	// ensures we do not overflow
	if (start == (size - 1)) {		// if the start num is the same 
		start = 0;		// the next index in a circle must be the beginning of the list
	}
	else {
		start++;		// it would not overflow so we can safely increment this
	}

	return item;
}
