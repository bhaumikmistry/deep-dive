[<- Back](../README.md)

# Trees

## Binary trees
- At most two children
- Element with no children are called trees.
- Application
    - store info that naturally forms a hierarchy.
    - sorted tree provide moderate access search quicker that linked list and slower than arrays.
    - Moderate insertion and deletion quicker than array and slower than unsorted linked list.
    - No upper limit for number of nodes.
    - Easy to search
    - Manipulate sorted list.
    - Form of multistage decision making.

## Binary Trees
- Strict Binary tree
    - Only 2 or 0 child
- Complete Binary tree
    - All levels except last are completely filled and all the nodes are as left as possible.
- Perfect Binary tree
    - Maximum no of nodes in a binary tree with height h
        - ```n = 2^(h+1)-1```
        - ```h = log base 2 of (n+1) -1```
    - Height of complete binary tree is ```floor of L log base 2 of n```
- Balanced tree
    - Difference between height of left and right subtree for every node is not more k(mostly 1)
    - Height -> no of edges in longest part from root to a leaf.
    - Height of empty tree is -1
    - Height of three with 1 root and 1 node attached ``` diff = |hLeft - hRight|```
- BFS DFS
    - Use ```queue``` dequeue for BFS
    - Use ```stack``` and ```array``` for DFS
- Traverse
    - Inorder ```left root right```
    - Preorder ```root left right```
    - Postorder ```left right root```

- Inorder Successor
    - From any given node in the tree, find the next node that will be executed, or printed.
        - First find the node with given data
        - Check if the node is null
        - Check if right child node is non null
            if right node is valid return min value node as Inorder successor.
        - Else 
            - run while loop and check the ancestor node which is larger than current node

