/*
#1.
Application of stack:
((3*2)-1(8-2))   Balanced Parenthesis
a=1-3)*4(-8      Unbalanced by 1 parenthesis
(1*(8-3(7)  by 2
let the parenthisis problrm be a character array
check 
1. Opening parenthesis  if yes find the opening parenthesis push it to the stack.  
2. Closing parenthesis  if yes finding the closing parenthis push it to the stack. 

condition for balanced expression:-
1. While poping stack should not underflow=> if yes than unbalnced equation. 
At end of the expression , the stack must be empty=> than unbalnced equation.
int parenthesisMatch( char * exp)
{
   struct stacl *sp;
   // Create the stack
   for(i=0; exp[i]!='\0';i++)
   {
      if(exp[i]=='(')
      {
        puch(sp,exp[i]);
      }
      else(exo[i]==')' )
      {
        if(isEmpty(sp)){
           return 0;
        }
        else
        pop(sp);
      }
   }
   if(isEmpty(sp)) return 0;
   else return 0;
}
*/
#include<stdio.h>
#include<stdlib.h>

struct stack{
  int size;
  int top;
  char *arr;
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
void push( struct stack *ptr,char val ){
   if(isFull(ptr)){
    printf("Stack OverFlow");
   }
   else{
      ptr->top++;
      ptr->arr[ptr->top]= val;
   }
}

char pop( struct stack *ptr ){
   if(isEmpty(ptr)){
    printf("Stack underFlow! Cannot pop from the stack \n");
    return -1;
   }
   else{
      char val = ptr->arr[ptr->top];
      ptr->top--;
      return val;

   }
}

int parenthesisMatch(char * exp)
{
    // Create and intialize the stack
    struct stack *sp;
    sp->size =100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));
    for(int i=0; exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
           push(sp, '(');
        }
        else if(exp[i]==')')
        {
           if(isEmpty(sp)) {
             printf("Not a valid parenthis");
             return 0; 
           }
           else{
            pop(sp);
           }  
        }  
       
    }
    if(isEmpty(sp))
       {
           return 1;
       }
       else{
        return 0; 
       }
}
int main(){
  char *exp = " 8*(9-2)";
  if(parenthesisMatch(exp)){
    printf(" The parenthesis is matching");
  }
  else{
    printf("The parenthesis is not matching");
  }
  return 0;
}
