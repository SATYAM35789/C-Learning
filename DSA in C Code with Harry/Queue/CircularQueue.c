/*   
Drawback  of Queue using arrays
   Space is not used efficiently.

    Solution of the drawback
    f==r then Queue is empty { 
      front=rare-1;      Agar f last tak pahuch jayega toh, f ko uske pafle postion par la do
                        do hum iska intezar thodi karunga ki f last tak pahuche uske baad hum memory use karenge.
 
    }
    
    Concept to circular increment
    circular increement is done by using mode operator
    arr={1,2,3,4,5,6,7}
    size=6
    i= (i+1)%size

#2
We can insert element in the queue is only from the rare(pichhe se)
void enqueue(struct Queue *q){
   if((q->r+1)%q->size == q->f){   // Full queue condition
    print("Queue overflow")  
   }
   else{                     // inserting value in 
   q->r = (q->r+1)%q->size;
   q->arr[q->r]=val;
   }
}

int dequeue(struct Queue *q){
int  val ;
  if(q->r==q->f){       // Isempty condition
    printf("Empty queue")
    val= -1;
    return val;
  }
  else{
  q->f=(q->+1)%q->size;
  val = q-arr[q->f];
  }
  return val;
}

*/
#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
   int size;
   int f,r;
   int *arr;
};
int isEmpty(struct circularQueue *q){
  if(q->r==q->f){
    return 1;
  }
  return 0;
}
int isFull( struct circularQueue *q){
   if((q->r+1)%q->size == q->f){
      return 1;
   }
   return 0;
}

// Function to add the value in a queue
void enqueue(struct circularQueue *q, int val){
   if(isFull(q)){
      printf("This Circular queue is full");
   }
   else{
      print("Enqueue element: %d\n", val);
      q->r = (q->r+1)%q->size;
      q->arr[q->r]= val;
   }
}
// Function to remove the vlue from the queue
int dequeue(struct circularQueue *q){
   int a;
   if(isEmpty(q)){
      printf("There is no more element in the queue");
      return -1;
   }
   else{
      q->f = (q->f+1)%q->size;
      a = q->arr[q->f];
   }
   return a; 
}
// Queue follow the First in First out
int main(){
   struct circularQueue q;
   q.size = 2;
   q.f=q.r=0; // -1 not because Queue hamari full hogi he nahi 
   q.arr = (int *)malloc(q.size*sizeof(int));
   return 0;

   // Enqueue few elements
   enqueue(&q, 1);
   enqueue(&q, 12);
   printf("Dequeuing element %d\n", dequeue(&q));
   printf("Dequeuing element %d\n", dequeue(&q));
   if(isEmpty(&q)){
      print("circularQueue is empty");
   }
   if(isFull(&q)){
      printf("circularQueue is Full"); 
   }

}
/* In cicular queue we take f,r = 0 to avoid the overwrite.

*/