/* What is a Graph 
Array/Linked list and stacks->linear data structures
BST and AVL Trees-> Non linear Hierachical Data Structure
Graph is an example of Non linear Hierachical Data Structure
A Graph is a collection of nodes(vertices) connected through edges(line connected b/w two nodes)

Formal Definition of a Graph:-
A graph is a collection of vertices and edges connecting these vertices.
Used to modal paths in a city, social networks, website backlinks, internal employee network, etc.
A vertix or nodes is one fundamental unity/entity of which graphs are formed.
An edge is uniqely defined by its 2 endpoints.
Directed edge- One way connection.
Undirected edge- Two way connection. 
Directed Graph- all directed edges.
Undirected Graph- all undirected edges. 

Indegree and Outdegree of a node:-
Outdegree = No of edges going out of the node.
Indegree = No of edges coming out of the node.

Facebook - A Graph of users:-
Graphs are used to model relationships between nodes.(nodes=people)
We can apply algorithms to suggest friends to people, calculate no of mutual friends etc. 
Other examples of graph include result of a web crawl for a website or for the entire world wide web, city routes etc.

# Ways to represent a Graph:-
Adjacency List - Mark the nodes with the list of its neighbors.
Adjaceny matrix - Aij = 1 for an edge between i and j, O otherrows.
Edge set - Store the pair of nodes/vertices connected with an edge. 
Other implementations to reprsent a graph also. For e.g Compact list representation, cost adjacency list, cost
adajaceny matrix etc.

Adjacency List:
Mark the nodes with the list of its neighbours. 
kisi nodes se jitne bhi jitne jude huye nodes hai wo ek list ke form mai represent ho raha  hai.
Array->storing pointers->connected that with linked list head. 

Adjacency matrix:- 
Aij = 1 for an edge between i and j, O otherrows.(Line/connectivity b/w two nodes)
yaha par matrix ke form mai pata karte hai ki connectivity hai ki nahi 
jo bhi nodes hai , sare diye huye nodes ke pass jakar dekhenge ki wo nodes kis kis connect hai, connect toh 1, nahi toh 0.
(given nodes as write the value as row and column)

Cost Adjacency matrix
Aij = Cost for an edge between i and j,O otherwise.
If the cost can be O:
Aij = Cost for an edge between i and j,-1/0 otherwise.(cost mai be O in the Q) 
(Cost = Edge ka (value))/ connectivity line ka no. 

Edge Set:- Store the pair of nodes / vertices connected with an edge.. 
(jo bhi nodes connected hai unko hum, ek pair mai likhenge) ( not used most )

Cost adjenceny list - Cost is also stored along  with links.(in list pair is of Node-Cost)

Compact List reepresentaton:- The entire graph is stored in a 1d array. 

#3
Graph Traversal:- 
Graph traversal refers to the process of visiting (checking and/or updating) each vertex(node) in a graph. 
Sequence of steps known as Graph traversal algorithum can be used to traverse a graph. 
 Two Algorithms of Graph Traversal are
  1. Breadth First Search (BFS)(used Queue Data Structure)
  2. Depth First Search (BFS) (used stack Data structure)
 

What is Difference between the Exploring and Visiting a Node. 
In a typical Graph Traversal algorithm, we traverse through (or visit) all the nodes of a graph and add it to the 
collection of visisted nodes.
Exploring a vertix in a graph means visiting all the collected vertices.


*/