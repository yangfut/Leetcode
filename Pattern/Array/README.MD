## Concept


### Backtrack

Two types of backtrack: Permutation and Subset.
Permutation is to create a constant length but unique sub array. Subset is to create unique but not constatn sub array.

(1). Backtrack in Permutation is to create multiple loops by visited table(dashboard) and recursion.
(2). Backtrack in Subset is to create take or not-take condition by include/exclude recursion and using idx for every recursive function.

### Binary Tree

One node with two leaves. Which node or leafs is visisted first leads three ways of order for a binary tree.

(1) Preorder Binary Tree: Root -> Left -> Right
(2) Inorder Binary Tree: Left -> Root -> Right
(3) Postorder Binary Tree: Left -> Right -> Root

How to construct a binary tree from preorder and inorder traversal(Leetcode#105)?
Definition terms:
(1) preStart: start index of preorder traversal
(2) preEnd: end index of preorder traversal
(3) inStart: start index of inorder traversal
(4) inEnd: end index of inorder traversal
(5) inRoot: the index of root in inorder traversal

* preStart must be the root of this subtree
* Find inRoot by looking the value of preStart
* Find number of left element(numLeft) by (inRoot - inStart)
* Left subtree listed in inorder traversal should be inStart : inRoot-1
* Right subtree listed in inorder traversal should be inRoot+1 : inEnd
* Left subtee listed in preorder traversal should be preStart+1 : preStart + numLeft
* Right subtree listed in preorder traversal should be preStar+numLeft+1 : preEnd
