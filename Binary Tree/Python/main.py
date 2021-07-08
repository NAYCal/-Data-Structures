# The is the main file for showcasing how a binary tree works
from BinTree import BinTree     # gets the class from the class file
import random       # importing random module


# greeting prompt to get what's up
def greetings():

    # this looks like a horrible idea, but it works
    try:
        # prompt
        print("Please pick one of the following options")
        print("1. Randomly generated tree")
        print("2. Make your own tree")
        return int(input("3. Exit\n"))      # return the value we got
    except ValueError:      # the user did an oopsie and entered a non-integer
        print("Unknown input entered, please enter one of the numbers representing the options.\n")
        return greetings()      # recursive loop to get the right values


# generates random data for the tree
def gen_random(head, size):
    for i in range(size):       # loops for how big the tree the user wants
        head.insert(random.randint(0, size))     # inserts from the range of values the user wants to enter
    return head     # returns the value back

def option1():
    try:
        size = int(input("How much data would you like your B tree be?\n"))
    except ValueError:
        print("Unknown input entered, please enter a number.\n")
        option1()

    head = BinTree(random.randint(0, size))
    gen_random(head, size)

    # prints out the traversal
    print("\n\nThe inorder would be ", end='')
    head.out_inorder()

    print("\n\nThe preorder would be ", end='')
    head.out_preorder()

    print("\n\nThe postorder would be ", end='')
    head.out_postorder()
    print("\n")

    return


# the function for option2 in the menu
def option2():

    # a try- except so we can initialize the tree without errors
    try:
        u_input = int(input("\nPlease enter an integer to be added to the tree, and anything else to exit.\n"))
    except ValueError:
        u_input = input("Are you sure you want to exit? Please enter 'Y' to confirm and anything else to continue\n")
        if u_input == 'Y':
            return
        else:
            option2()

    head = BinTree(u_input)     # tree is initialized

    # while loop so user can keep entering data
    while str(u_input).isdigit():
        u_input = input("\nPlease enter an integer to be added to the tree, and anything else to exit.\n")

        if not str(u_input).isdigit():       # allows the user to exit the loop
            u_input = input("Are you sure you want to exit? Please enter 'Y' to confirm and anything else to continue\n")
            if u_input == 'Y':
                break

        head.insert(u_input)

    # prints out the traversal
    print("\n\nThe inorder would be ", end='')
    head.out_inorder()

    print("\n\nThe preorder would be ", end='')
    head.out_preorder()

    print("\n\nThe postorder would be ", end='')
    head.out_postorder()
    print("\n")

    return


# Press the green button in the gutter to run the script.
if __name__ == '__main__':      # if we are calling for the main function
    print("Welcome! This program aims to better understanding on how binary trees work")
    u_input = greetings()

    # until the user wants to exit
    while u_input != 3:

        # while loop that made sure we get the right input
        while (u_input <= 0) or (u_input > 3):
            print("Unknown input entered, please enter one of the numbers representing the options.\n")
            u_input = greetings()  # recursive loop

        if u_input == 1:
            option1()
        elif u_input == 2:
            option2()

        u_input = greetings()
