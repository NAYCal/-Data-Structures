// Binary tree showcasing.cpp - This program aims to improve the understanding of how a Binary tree works, through showing each step of forming, traversing and searching in the tree
#include <iostream>     // standard input/output stream objects
#include <stdlib.h>     // for random generator
#include <time.h>       // to get a random seed for random generator
#include <windows.h>        // to get cool console output

// structure for nodes
struct Node {
    int data;       // stores the data of that node
    Node *left, * right;        // basically allows the node to go left or right
};

void Color(int color);
void menu();
void generate_random(int size);
struct Node* insert(Node* head, int data);
void out_inorder(Node* head);
void out_preorder(Node* head);
void out_postorder(Node* head);
bool find(Node* head, int data);

Node* head;     // declaring a global variable to store everything

// main function
int main()
{
    srand(time(NULL));      // gets a random seed
    system("Color 0A");     // output go vrooom

    menu();
}

//COLORS LIST
//1: Blue
//2: Green
//3: Cyan
//4: Red
//5: Purple
//6: Yellow (Dark)
//7: Default white
//8: Gray/Grey
//9: Bright blue
//10: Brigth green
//11: Bright cyan
//12: Bright red
//13: Pink/Magenta
//14: Yellow
//15: Bright white
//Numbers after 15 include background colors
void Color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void menu() {
    std::cout << "Welcome! This program aims to better understanding on how binary trees work fundamentally.\n"
        << "Please pick one of the following options\n"
        << "1. Randomly generated tree\n"
        << "2. Make your own tree\n"
        << "3. Exit\n";

    int input;

    std::cin >> input;

    switch (input) {
    case 1: 
        int size;
        head = NULL;

        std::cout << "How much data would you like your B tree be?\n";

        std::cin >> size;
        generate_random(size);

        std::cout << "\n\nThe inorder would be ";
        out_inorder(head);

        std::cout << "\n\nThe preorder would be ";
        out_preorder(head);

        std::cout << "\n\nThe postorder would be ";
        out_postorder(head);
        std::cout << "\n\n";
        
        std::cout << find(head,3)<< std::endl;
        menu();
        break;
    case 2:
        std::cin.clear();
        std::cin.ignore(256, '\n');
        head = NULL;

        do {
            std::cout << "\nPlease enter an integer to be added to the tree, and anything else to exit.\n";
            std::cin >> input;

            head = insert(head, input);

        } while (std::cin);
        
        std::cout << "\n\nThe inorder would be ";
        out_inorder(head);

        std::cout << "\n\nThe preorder would be ";
        out_preorder(head);

        std::cout << "\n\nThe postorder would be ";
        out_postorder(head);
        std::cout << "\n\n";

        menu();
        break;
    case 3:
        break;
    default:
        std::cout << "Unknown input entered, please enter one of the numbers representing the options.\n";
    }

}

void generate_random(int size) {        // generates a random tree
    int data;       // data variable to be generated

    for (int i = 0; i < size; i++) {
        data = rand()%size + 1;      // data is a random number - had to limit the size
        std::cout << "\nThe #" << i + 1<< " data is " << data << "\n";
        head = insert(head, data);
    }
}

// recursive function to insert a data into the nodes
/*
How this works:
A head and a data is passed,
if the head is empty, the data is stored directly into the head
But if the head is not, and the data is larger than the current head
the function is called again as a loop to compare the left branch of the head to the data
This also works to data smaller than the head, but the process is towards the right branch instead
This will keep looping recursively until the data is stored where it belongs
*/
struct Node *insert(Node* head, int data) {
    Color(4);

    if (head == NULL) {         // this is if this branch is empty
        
        std::cout << "Since there is no data stored here, lets store our new data here.\n";
        Color(2);

        Node* temp = (Node*)malloc(sizeof(Node));       // creates a temporary tree
        (temp->data) = data;      // the data is stored
        temp->left = NULL;      // basically resets the tree
        temp->right = NULL;     // same as above
        head = temp;        // replace the head with the temp tree
        return head;
    }

    if (data > (head->data)) {      // if the data is larger than the head data
        std::cout << "Since the data is larger to the one in this position at the tree," << head->data << ", we will move to the left branch of the tree\n";

        head->left = insert(head->left, data);      // execute the function again so the data is compared to the left branch
    }
    else if (data < (head->data)) {     // basically what the above statement does except in the right direction
        std::cout << "Since the data is smaller than the one in this position at the tree," << head->data << ", we will move to the right branch of the tree\n";
        
        head->right = insert(head->right, data);
    }

    Color(2);
    return head;
}


// recursive function to traverse in order
/*
Basically outputs the data from largest to lowest
How it works:
By going through the most left branch first, we will reach the largest data
Then we will proceed by going to the right of that branch,
giving us the smaller data
*/
void out_inorder(Node* head) {

    if (head == NULL) {     // if it is empty, then there is nothing to output
        return;
    }

    out_inorder(head->left);

    Color(5);
    std::cout << head->data << " ";
    Color(2);

    out_inorder(head->right);

}


// recursive function to traverse preorder
void out_preorder(Node* head) {

    if (head == NULL) {     // if it is empty
        return;     // end it
    }

    Color(5);
    std::cout << head->data << " ";
    Color(2);

    out_preorder(head->left);
    out_inorder(head->right);

}


//recursive function to traverse postorder
void out_postorder(Node* head) {

    if (head == NULL) {     // if it is empty
        return;     // end it
    }

    out_postorder(head->left);
    out_postorder(head->right);

    Color(5);
    std::cout << head->data << " ";
    Color(2);
}


// function to confirm a data within B tree
bool find(Node* head, int data) {
    if (head == NULL) {     // if there is no data
        return false;       // return false
    }

    if ((head->data) == data) {     // data found
        return true;        // so return true
    }

// if the data is not found yet
    if (data > (head->data)) {      // and if the data is larger than the current head
        return find((head->left), data);        // recurse to go check left branch of head
    }

    if (data < (head->data)) {      // or if the data is smaller than the current head
        return find((head->right), data);       // recurse to go check right branch of head
    }

    return false;       // you have already looped through so it must not be in the tree
}