# This file contains the Binary Tree class
# A notable difference between this code is that you have to call the initiator to ensure the nodes can branch out

# defining the binary tree object
class BinTree:

    # initiation that adds in the data
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

    # the function that inserts data into the tree
    def insert(self, data):

        if self.data:       # Check if there is data already
            if self.data > data:       # now check if our data is larger
                if self.left is None:       # now check if the left is empty
                    self.left = BinTree(data)      # since it is empty, add it in!
                else:       # if there is data in this node
                    self.left.insert(data)      # recursive loop!
            elif self.data < data:      # if the data in the node is larger than the data
                if self.right is None:      # checks if there is data in the node
                    self.right = BinTree(data)     # Adds the data right in
                else:       # there is no data in the node
                    self.right.insert(data)     # recursive loop
        else:       # if there are no data
            self.data = data        # add it right in since it is the head

    # function that outputs the tree inorder
    def out_inorder(self):
        if self.data:       # If there is data
            if self.left:
                self.left.out_inorder()  # recursive to the left

            print(self.data, end=" ")        # print data

            if self.right:
                self.right.out_inorder()        # recursive to the right

    # function that outputs the tree in preorder
    def out_preorder(self):
        if self.data:       # if there is data
            print(self.data, end=" ")        # print out the data

            if self.left:
                self.left.out_preorder()        # recursive to the left
            if self.right:
                self.right.out_preorder()       # recursive to the right

    # function that outputs the tree in postorder
    def out_postorder(self):
        if self.data:       # if there is data
            if self.left:
                self.left.out_postorder()
            if self.right:
                self.right.out_postorder()
            print(self.data, end=" ")

# function that confirms the existence of UFOs, I mean the data values in the tree
    def find(self, data):
        if not self.data:       # if there is no data
            return False        # then we cannot find the data
        if self.data == data:       # if the data matches
            return True     # then we found the data

        # basically the insertion process but for searching
        if self.data > data:
            return self.left.find(data)     # recursive loop  to the left
        elif self.data < data:
            return self.right.find(data)        # recursive loop to the right

        return False        # if we reached here, we could not find the data

# in case we need something like this
    def no_head(self):
        self.left = None
        self.right = None
        self.data = None