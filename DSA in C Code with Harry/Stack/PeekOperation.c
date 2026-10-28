/* Peek Operation in Stack Using Array:
int peek( struct satck *sp, int i){   // i= position i=1 here from the top of the stack
   if(sp->top-i+1<0){
     printf("not a valid position");
     return -1;
   }
   else{
     return sp->arr[sp->top-i+1];
   }
   
}
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
int peek( struct stack * sp, int i){
    int arrayInd = sp->top-i+1;
    if(arrayInd <0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}

int main(){
  struct stack *sp = (struct stack *)malloc(sizeof(struct stack)); // And this creates the instance of our structure.
  sp->size= 10;
  sp->top=-1;
  sp->arr = (int *)malloc(sp->size*sizeof(int));
  printf("Stack has been created the succesfully \n ");

  printf("Before pushing ,Full:%d\n", isFull(sp));
  printf("Before pushing , Empty%d\n", isEmpty(sp));
  push( sp,1);
  push( sp,2);
  push( sp,3);
  push( sp,4);
    
  // Checking the isFull and isEmpty
  printf("After pushing ,Full:%d\n", isFull(sp));
  printf("after pushing , Empty%d\n", isEmpty(sp));

  printf(" Popped %d from the stack\n", pop(sp));

// For printing the value in the stack
  for( int j=0; j<sp->top+1; j++){
    printf("The value at position %d is %d\n", j,peek(sp,j));
  }

  return 0;
}