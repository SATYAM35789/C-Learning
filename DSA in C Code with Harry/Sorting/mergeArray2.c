#include<stdio.h>
#include<conio.h>

void printArray(int *A, int n)
{
       for(int i=0; i<n;i++)
       {
              printf(" %d ",A[i]);
       }
       printf("\n");
}
void merge(int A[], int mid, int low, int high){

}
int main()
{
  int A[] = {9,14,4,8,7,5,6};
   int n= 7;
   printArray(A,n);
   MergeSort();
   printArray(A,n);
   return 0;  
}