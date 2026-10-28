/* Peek Operation: Finding the element at given position. 
   Peek(int pos)
     struct Node *ptr = top; // Making ehich go to the index to be access.
     for(i=0;i<pos-1 && ptr!=NULL;i++)
         ptr->ptr->next;
    if(ptr!=NULL)
       return ptr->data;  // Agar ptr null nahi hai toh kisi n kisi position par pahuch gaya hoga uska data return kardo
    else
       return-1;

    2. Stack Top Operation       3. StackBottom Operation
       int stackTop()
          return top->data; 

*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *top =  NULL; // Means at starting our stack is empty
void Linkelisttraversing(struct Node * ptr)
{
    while(ptr!=NULL)
    {
    printf(" Element:%d\n", ptr->data);
    ptr=ptr->next;
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

int peek(int pos)
{
    struct Node *ptr = top;
    for(int i=0; i<pos-1 && ptr!=NULL;i++)
    {
       ptr=ptr->next;   
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else
    {
       return -1;
    }
}

int main()
{
    push(top,4);
    push(top,54);
    push(top,34);
    push(top,48);
    Linkelisttraversing(top);
    for(int i=1; i<=4;i++)
    {
        printf(" Value at position %d is :%d\n",i,peek);
    }
    return 0;   
}