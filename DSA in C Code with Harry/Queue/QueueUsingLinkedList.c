/* Queue Using Linked Lists
Linked list is like a chain of nodes, in which eich node contain the data-next add. 
Void enqueue(struct node *f,struct node *r, int val){
  To enqueue we create new node
  Newnode *n = (struct node *)malloc(sizeof(struct node));
    if(n==Null)
      printf("Queue is full");
    else{
    n->data=val;
    n->next=NULL;
    if(f=R==NULL)Jab hamara queue ek dum khali hoga toh front=rare=NULL After this when made newNode then we
      {            point the F and R to the same node.  // SPECIAL CASE:-when F=R=NULL; emptty Queue Case
         F=R=n;
      }
      else{
        r->next=n;
        r=n;
      }
      
}
Condition for Queue Empty
  F==NULL
Condition  n==NULL; 

int Dequeue(N *f,N *r){
  int val = -1;
  N *ptr = f; (ptr points the F)
  // Check For Queue Empty
  in else
  f=f->next;
  val = ptr->data; 
  free(ptr);
  return val; 
}
*/
#include<stdio.h>
#include<stdlib.h>
struct Node *f = NULL;
struct Node *r = NULL;

struct Node{
    int data;
    struct Node * next;
};

void Linkelisttraversing(struct Node * ptr)
{ 
  printf("Printing the element of this linked list");
    while(ptr!=NULL)
    {
    printf(" Element:%d\n", ptr->data);
    ptr=ptr->next;
    }
}

// To add element in the queue 
void enqueue(int val){
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  if (n==NULL){
    printf(" Queue is Full");
  }
  else{
    n->data = val; 
    n->next = NULL;
    if(f==NULL){
      f=r=n;
    }
    else{
      r->next = n;
      r  = n;
    }
  }
}

// To delete the node from the queue (and returning the deleted node value)
int dequeue(){
  int val = -1; 
  struct Node *ptr ;
  if (f==NULL){
    printf(" Queue is Empty");
  }
  else{
    f= f->next;
    val = ptr->data;
    free(ptr);
  }
  return val;
}

int main(){
    //struct Node *f = NULL;   BY Intializing here the copies are passed and in the enqueue fun gets changed so 
   // struct Node *r = NULL;   make the global variable . When there is global vari then we do not need pass it(f,r) 
    Linkelisttraversing(f);
    //enqueue(f,r,3);
    Printf("Dequeueing element when there no node %d\n", dequeue());  // Return -1
    enqueue(3);
    enqueue(2);
    enqueue(1);
    dequeue();
    Linkelisttraversing(f);
    return 0;
}

