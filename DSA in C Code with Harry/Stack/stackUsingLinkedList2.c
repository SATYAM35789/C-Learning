#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *top = NULL; // Means at starting our stack is empty
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

int pop(struct Node *tp)
{
    if(isEmpty(tp))
    {
      printf("Stack is Underflow\n");
    }
    else
    {
      struct Node *n = tp;
      top=tp->next;
      int x = n->data;
      free(n);
      return x;
    }  
}

int main()
{
   push(top, 78);
   push(top, 8);
   push(top, 8);
   int element = pop(top);
   printf("Poped element is %d\n",element);
   Linkelisttraversing(top);
   return 0;
}

