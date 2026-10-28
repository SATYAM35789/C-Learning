 /*  Stack Operarions in stack using Array
 Cannot push if full 
 Cannot pop if empty
 struct stack{
   int size;
   int top;
   int *arr;
 };
 Creating a stack
  struct stack *sp;
    sp->size = 8;
    sp->top=-1;
    sp->arr =(int *)malloc(sp->size*sizeof(int));

// PUSH operation or Entering the element in the stack. 
    if(isFull(sp))
      printf("Stack is full or stack is overflow");
    else
      sp->top++;
      sp->arr[sp->top] = val;

// POP Operation 
- Returning the value jo bhi value remove ho raha hai 
   if(isEmpty(sp))
      print("Stack is UnderFlow or No more element to pop")
      return -1
   else
      int val = sp->arr[sp->top];
      sp->top= sp->top-1;
      return val
*/

#include<stdio.h>
#include<stdlib.h>
struct stack {
   int size;
   int top;
   int *arr;   // To dynamically allocate the memory
};

int isEmpty(struct stack *ptr){
   if(ptr->top==-1){
     return 1;
   }
   else{
     return 0;
   }
}
int isFull(struct stack *ptr){
   if(ptr->top==ptr->size-1){
     return 1;
   }
  else{
     return 0;
   }   
}
void push( struct stack *ptr,int val ){
   if(isFull(ptr)){
    printf("Stack OverFlow");
   }
   else{
      ptr->top++;
      ptr->arr[ptr->top]= val;
   }
}

int pop( struct stack *ptr ){
   if(isEmpty(ptr)){
    printf("Stack underFlow! Cannot pop from the stack \n");
    return -1;
   }
   else{
      int val = ptr->arr[ptr->top];
      ptr->top--;
      return val;

   }
}

int main(){
  struct stack *sp = (struct stack *)malloc(sizeof(struct stack)); // And this creates the instance of our structure. 
  // storing the address of a structure where sp points that structure.(before defining the right side ) 
  // while instance is ready than we creates size top and arr of that instance.
  sp->size= 10;
  sp->top=-1;
  // Creating the arr dynamically (we have in define it in the structure)
  sp->arr = (int *)malloc(sp->size*sizeof(int));
  printf("Stack has been created the succesfully \n ");

  printf("Before pushing ,Full:%d\n", isFull(sp));
  printf("Before pushing , Empty%d\n", isEmpty(sp));
  push( sp,1);
  push( sp,2);
  push( sp,3);
  push( sp,4);
  push( sp,5);
  push( sp,6);
  push( sp,7);
  push( sp,8);
  push( sp,9);
  push( sp,10);  
  // Checking the isFull and isEmpty
  printf("After pushing ,Full:%d\n", isFull(sp));
  printf("after pushing , Empty%d\n", isEmpty(sp));

  printf(" Popped %d from the stack\n", pop(sp));

  return 0;
}