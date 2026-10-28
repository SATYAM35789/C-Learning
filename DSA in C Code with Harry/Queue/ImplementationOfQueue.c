/* Queue Implementation : Array Implementation of Queue
1. When having only one pointer  
Intilizing backind while every insert of an element we backind++.
Insertion (Enqueue) Logic:-
  Increment backind
  Insert at bacjind  O(1)

Removal (Dequeue):
   Remove the ele,ent at Index 0
   shift all element  O(n)

2. When having only two index pointer
    1. Frontend->f      2. BackEnd->b

    Insert
       Increment b and insert at b. 
    Remove:-
       Remove element at F and Increment f. 
          First element= frontend+1
          Rear  element = Backend

        queue empty condition -> frontend = Backend(f==b)
        Queue full-> b=size-1

#2
Struct Queue{
int size;
int f;
int *arr;
}
int main(){
Struct Queue q (we dynamically allocate the memory)
q.size= 10;
q.f=q.r=-1;
q.arr= (int *)malloc(q.size(sizeof(int))); (array has been created)
}
Two Operation 
Enqueue
void enqueue(struct Queue *q, int value){
  if(isFull(q)){
    print(" Queue overflow")
  }
  else{
    q->r=q->+1;   now r=at 0 index   (r= rare)
    q->arr[q->r]= val;  (for ex value)
  }
}

int dequeue(Queue *q){
  int 1=-1; (indicate that we are unable to dequeue)
  if(q->f==q->r){                    isEmpty  condition
   print(" No element to dequeue")
  }
  else{
  q->f++;
  a=q->arr[q->f];
  }
  return a;
}
isFull()
  if(q->r==q->size-1){
  return 1;
  }          
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
   q.size = 4;
   q.f=q.r=-1;
   q.arr = (int *)malloc(q.size*sizeof(int));
   return 0;

   // Enqueue few elements
   enqueue(&q, 9);
   enqueue(&q, 45);
   enqueue(&q, 12);
   enqueue(&q, 34);
   printf("Dequeuing element %d\n", dequeue(&q));
   if(isEmpty(&q)){
      print("Queue is empty");
   }
   if(isFull(&q)){
      printf("Queue id=s Full"); 
   }
}

