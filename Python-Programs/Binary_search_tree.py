
#a program used to demonstrate simple operations in a binary search tree

class Node:
    def __init__(self,node):
        self.left=None
        self.right=None
        self.node=node
    def insert(self,objnode):
        if self.node:
            if objnode<self.node:
                if self.left is None:
                    self.left=Node(objnode)
                else:
                    self.left.insert(objnode)
            elif objnode>self.node:
                if self.right is None:
                    self.right=Node(objnode)
                else:
                    self.right.insert(objnode)
            else:
                self.node=objnode
    def printBST(self):
        if self.left:
            self.left.printBST()
        print(self.node)
        if self.right:
            self.right.printBST()
            
n=int(input('Enter your Root node'))
root=Node(n)
while 1:
    a=int(input("enter the node you want to insert"))
    root.insert(a)
    ch=input("Do you want to continue Y or N")
    if ch=="Y"or ch=="y":
        continue
    else:
        break
print("Your final binary search tree is\n")
root.printBST()
