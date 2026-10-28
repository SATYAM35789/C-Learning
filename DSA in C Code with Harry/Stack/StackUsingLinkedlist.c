/*
Stack using linked list:-
Having the example of simple linked list. 
We haiving two option to make linked list 1. Start side(from head) 2. End Sidein. 
We take 1 Option because the opertaion perform on front side is in O(1).

 struct node 
 {
    int data;
    struct node *next;
 } 
 Points to keep in mind while creating a stack using linked list:-
1. Side 1 will be used for push and pop operations.
2. Head is now -> Top
3. Stack Empty Condition -> (top==Null)
4. Stack is full when:- Heap memory is exhausted (we come to know dynamically allocated ptr == NULL)
5.You can always set a custom size.(means you can fixed the size of stack)


Implementing pop(), push(), peek(), Isempty(), Isfull() using linked list. (
1.IsEmpty():            2. IsFull
  int isEmpty:            struct Node *n = (struct Node*)malloc(sizeof(struct Node));
     if(top==NULL){             if(n==NULL)
        return 1;                   return 1;
     }                          else
   else                            return 0;
     return 0;

   3. Push Operation
      push(x); // Inserting at index 0
      struct Node *n = (struct Node *)malloc(sizeof(struct Node));
      if(n==NULL)
         printf("Stack Overflow")
      else
        n->data = x; // X is the element which we want to push.
        n->next = top;
        top=n; // This help in stack to top pointer to be in the top.

   4. Pop Operation ( This will also perform from the index 0)
      if(isEmpty)
         printf("Stack UnderFlow")
      else
        struct Node *n = top; // Naye node ko top ke barbar kardiya. 
        top = top->next;
        int x = n->data;
        free(n);
        return x;
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void Linkelisttraversing(struct Node * ptr)
{
    while(ptr!=NULL)
    {
    printf(" Element:%d\n", ptr->data);
    ptr=ptr->next;
    }
}
int isEmpty(struct Node *top)
{
   if(top==NULL)
   {
      return 1;
   } 
}
int isFull(struct Node *top)
{
   struct Node *p = (struct Node*)malloc(sizeof(struct Node));
   if(p==NULL)
   {
      return 1;
   }
}
struct Node* push(struct Node *top,int x)
{
    if(isFull(top))
    {
      printf("Stack is Overflow\n");
    }
    else
    {
      struct Node *n = (struct Node *)malloc(sizeof(struct Node));
      n->data = x;
      n->next=top;
      top = n;

      return top;
    }  
}

int pop(struct Node **top)
{
    if(isEmpty(*top))
    {
      printf("Stack is Underflow\n");
    }
    else
    {
      struct Node *n = *top;
      top=(*top)->next;
      int x = n->data;
      free(n);
      return x;
    }  
}

int main()
{
   struct Node *top = NULL; // Means at starting our stack is empty
   push(top, 78);
   push(top, 8);
   push(top, 8);
   int element = pop(&top);
   printf("Poped element is %d\n",element);
   Linkelisttraversing(top);
   return 0;
}

/* In pop() if we want that top value is updated after the deletion of an element from the linked list than we 
 have to pass the address of top(pass by refernce). 

*/