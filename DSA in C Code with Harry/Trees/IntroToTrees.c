
// Trees 
// Terminology
// Root :- Ek aisa node jiske upper aur koi node nahi hata hai. (Topmost Node)
// Parent :- Node jisse koi node connect ho raha hai (Node which connect to the child)
// Child :-  Jisko koi dusra node connect kar raha hota hai (which is connected by another node is it's child)
// leafnode(external node) :- aisa node jo pita nahi ban saka or jisse aur koi node jode.(nodes with no children)
// Internal node :- Node atleat one child
// Depth of node :- no of edges from the  root to the node
// Height of node :- no of edges from node to the deepest leaf (koi node aur kitna niche utar sakta hai)
// Sibling : Node Belonging to the same Parent
// Ancenters :- purawaj 
// Decendents :-  bacha aur bache ka bacha

// What is Binary Tree. 
// Degree :- node kitne aur node jude hua hai.
// Binary tree is a tree which has at most 2 children for all the nodes. 
// OR a tree in which the every node of degree is two or lessthan 2. 

// Quick revision:- 1 Tree is made up of nodes and edges.
// 2. n nodes => n-1 edges    (nodes means total population, edges means root ke sabhi bache)
// 3. Degree = no of direct children 
// 4. Degree of a tree is the highest degree of a node among all the nodes present in the tree. 
// 5. Binary tree = Tree of degree 2 . Node can have 0,1,2 children. 
//  NOTE: Arrow = edges , circle = nodes

// Types of Binary Tree. 
// Tree is non-linear data structure. 
// Use for representing hierarchical data. 
// 1. Full or strict Binary Tree :- All the node have either 0,or 2  children .
// 2. Perfect Binary tree :- Internal nodes have 2 children + all leaf nodes are on the same level.
// 3.Complete Binary tree:- All levels are completely field except possibly the last level + last level must have
// its keys as left as possible.
// Degenerate Binary tree :- Every parent node has exactly one child.
// They are  of two types 
// 1. Left  Skewed Trees :- All the children of a left skewed trees are towords the left.
// 2. Right  Skewed Trees :- All the children of a right skewed trees are towords the right.

// Representation of a Binary Tree:- 
// 1. Array Representation :- Not use mostly as we have declare their size before reprsenting (fixed size)
// by indexing each and every node start with root =0. 
// Agar indexing karte samay aage element nahi hai toh us index value null store kar denge. (see the figure in phone)
// drawback of using array representation:- 
//In this deletion and insertion is compllicated.
// Size fixed :- if the array representation is full than we have to create another array representation 

// Linked Representation :- is efficient .
// we use doubly linked list (see the figur in phone)
// struct Node {
//     int data;             -> STRUCTURE OF NODE IN C LANGUAGE
//     struct Node*left;
//     struct Node *right
//  }