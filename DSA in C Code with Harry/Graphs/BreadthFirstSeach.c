/* Breadth First Search
In BFS, we start with a node and start exploring its connected nodes. The same process is repeated with all the 
connecting nodes until all the nodes are visited. 

BFS Spanning tree:-
Method:1
To see graph (see the lecture 86 at 2:02)
Consider the graph shown at the right.
We can start with any source node.
Lets start with 0 
Try to construct a tree with 0 as the root.
Mark all the siadeways or duplicates edges (above a node) as dashed. 
This constructed tree is called as BFS Spanning Tree. 
Level Order Traversing of a BFS spanning tree is a valid BFS traversal of a graph. 

Method:2
Consider the graph shown at the righgt.
We can start with any source node.
Lets start with 0 and insert it in queue.
Visit all the connected vertices and enqueue them for exploration.
Visited:0,1,3,2  (list)  jis bhi node ko explore karna hai us connected node. Agar pahle visited hoga toh use let go kardenge.
Exploration Queue: 0,1,3,2 (list)   is se conected sare visited hai ki nahi. 

BFS Traversal - Exploring 0
Consider the graph shown at right
We can start with any source node.
Lets start with 0 and insert it in the queue.
Visit all the connected verticec and enqueue them for exploration (in any order ).
0 is now explored Let's go to the next node (1).
Repeat the same for other elements in the queue.
visited:0,1,2,3
exploration queue: 0(done),1,3,2

BfS Traversal - Exploring 1
alraeady explored as the connected node with node 1 is already visited. 

Important points
We can start wiith any vertex.
There can be multiple BFS results for a given graph
The order of visiting the vertices can be anything. 

*/
#include<stdio.h>
#include<stdlib.h>
struct queue{
   int size;
   int f,r;
   int *arr;
};
int isFull(struct queue *q){
   if(q->r==q->size-1){
      return 1;
   }
   return 0;
}
int isEmpty(struct queue *q){
   if( q->r==q->f ){
      return 1;
   }
   return 0;
}
// Function to add the value in a queue
void enqueue(struct queue *q, int val){
   if(isFull(q)){
      printf("This queue is full");
   }
   else{
      q->r++;
      q->arr[q->r]= val;
   }
}
// Function to remove the vlue from the queue
int dequeue(struct queue *q){
   int a;
   if(isEmpty(q)){
      printf("There is no more element in the queue");
      return -1;
   }
   else{
      q->f++;
      a = q->arr[q->f];
   }
   return a; 
}
// Queue follow the First in First out
int main(){
   struct queue q;
   q.size = 400;
   q.f=q.r=-1;
   q.arr = (int *)malloc(q.size*sizeof(int));

   // BFS Implementation:-
   int node ; 
   int i = 0 ; 
   int visited[7] = {0,0,0,0,0,0,0};  // Seven zero because we are working here with seven nodes. 
   int a [7][7] = {     // Adjacency matrix creating   by seeing the grph in the video. 
       {0,1,1,1,0,0,0},
       {1,0,1,0,0,0,0},
       {1,1,0,1,1,0,0},
       {1,0,1,0,1,0,0},
       {0,0,1,1,0,1,1},
       {0,0,0,0,1,0,0},
       {0,0,0,0,1,0,0}
   };
   // Jis bhi nodes start kar rahe hai
   printf("%d", i);
   visited[i]=1;
   enqueue(&q,i); // Enqueue i for exploration
   while(!isEmpty(&q))
   {
      int node =dequeue(&q); // Jo sabse aage hai queue wo hame mil jayega
      for( int j=0; j<7;j++)
      {
         if(a[node][j]==1 && visited[j]==0){  //a[node][j]==1 yani node connected ho.   visited[j]==0  Yani visited n ho
            printf("%d",j);  // jo bhi connected hoga node wale se aur visited nahi hai
            visited[j] = 1;  // Marking the node as the visited.
            enqueue(&q,j);     // Enqueue the node for exploring
         }     
      } 
   }
   return 0;
}

