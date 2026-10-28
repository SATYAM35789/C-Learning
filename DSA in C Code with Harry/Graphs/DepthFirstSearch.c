/*
Depth First Search:- This is th way to traverse 
1.Graph traversal refers to the process of visiting (checking or updating)each vertex(node) in a graph.
2.In DFS, we start with a node and start exploring its connected nodes keeping on suspending the exploration of 
  previous node. 

DFS Procedure :- 
1.Start by putting any one of the graph's vertices on the top of a stack.
2.Take the top item of the stack and add it to the visited list. 
3.Create a list of that vertex's adajacent nodes. Add the ones which aren't in the visited list to the top of the
  stack.
4.Keep repeating step 2 and 3 until the stack is empty. 
DFS mai stack already mil jati hai. 
*/
#include<stdio.h>
#include<conio.h>


int visited[7] = {0,0,0,0,0,0,0};  // Seven zero because we are working here with seven nodes. 
    int A [7][7] = {     // Adjacency matrix creating   by seeing the grph in the video. 
       {0,1,1,1,0,0,0},
       {1,0,1,0,0,0,0},
       {1,1,0,1,1,0,0},
       {1,0,1,0,1,0,0},
       {0,0,1,1,0,1,1},
       {0,0,0,0,1,0,0},
       {0,0,0,0,1,0,0}
   };
// Function which take parameter as integer, which node we want to visit.
void DFS(int i)
{
    int j;
    printf("%d",i); // printing the node we visit
    visited[i]=1;   // Jo need visit ho gaya hai usko 1 mark  kar lunga. 
    for(int j=0; j<7;j++)
    {
       if(A[i][j]==1 && !visited[j] )
       {
         DFS(j);
       }
    }
}
int main()
{
   DFS(4);  // jaha se start karna chahte ho
   return 0; 
}