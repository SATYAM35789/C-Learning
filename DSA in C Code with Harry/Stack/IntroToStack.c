/*  What is need of the stsck type of data structure?
    The operation perform in stack is in LIFO manner. 
    Application of stack:- 
     - Used in function calls
     - Infix to Postfix conversions(and other similar conventions)
     - Parenthesis makking and more.

Stack Adt (stack ADT means that stack contains some methods(operations) and properties):-
   In order to create a stack we need a pointer to the topmostelement along with other elements which are 
   stored inside the stack. 
   methods like:
   push() , pop(), peek(index)- value at given index, isEmpty()/isFull()

Definntion:- A stack is a collection of elements with certains operation following LIFO discipline.
  A stack can be implemented using an array or a linked list. 


#2
Stack using An Array:
top = -1 maens that there is no more element in stack.
Step-1: Fixed size array creation.
Step-2: Top element

Struct stack{
  int size;
  int top;
  int *arr;
}

struct stack S; 
S.size=80;
S.top= -1;
S.arr = (int *)malloc(sizeof(int));   
*/
#include<stdio.h>
#include<stdlib.h>

struct stack{
  int size;
  int top;
  int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
      printf("Stack is Empty");
      return 1;
    }
    else{

      return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
      printf("Stack is Full");
      return 1;
    }
    else{
      
      return 0;
    }
}

int main(){
  // struct stack s;
  // s.size= 80;
  // s.top = -1;
  // s.arr = (int *)malloc(s.size*sizeof(int));  

// Doing this because passing the value to another fun is easy. 
  struct stack *s;
  s->size= 80;
  s->top = -1;
  s->arr = (int *)malloc(s->size*sizeof(int));
  
  // Pushing the element mannually
  s->arr[0]=4;
  s->top++;
  // Check if the stack is Empty
  if(isEmpty(s)){
    ptintf("The stack is empty");
  }
  else{
    printf(" The stack is not empty");
  }


  return 0;
}