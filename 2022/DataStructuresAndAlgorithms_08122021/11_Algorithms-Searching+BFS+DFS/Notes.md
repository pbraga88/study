
# Breadth First Search and Depth First Search
**Time Complexity**  
    BFS O(n)  
    DFS O(n)  
**Space Complexity**  
    BFS O(n)  
    DFS O(h), where h is the maximal depth of the tree, for a recursive search

## If you know a solution is not far from the root of the tree:
BFS

## If the tree is very deep and solutions are rare, 
BFS (DFS will take long time. )

## If the tree is very wide:
DFS (BFS will need too much memory, since it keeps track of every node in the same level)

## If solutions are frequent but located deep in the tree
DFS

## Determining whether a path exists between two nodes
DFS

## Finding the shortest path
BFS