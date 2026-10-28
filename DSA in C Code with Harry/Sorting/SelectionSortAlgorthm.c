/* Selection Sort:- Finding the minimum value. aage bhej denge.  
   Sabse pahle pure array ko unsorted man lenge phir nich wale process 
   Ye unsorted part mai sabse chhota value khoj kar usko aage bhej dega. by unsorted array ke first elment chhota 
   maan lenge aur compair karenge ki koi aur element is se chhota hai ki nahi.and so on. 
   Example 8,0,7,1,3
   1st pass 0,8,7,1,3
   2nd      0,1,7,8,3
   3rd      0,1,3,8,7
   4th      0,1,3,7,8
   no of pass = n-1
   1+2+3+4+5...(n-1) = n(n-1)/2 = O(n square) 
   Max swap = n-1
   Stability:- NOT Stable
   Adaptive  :- Selection sort is not adaptive. 
   Advantages : Sorting in minimum no. of swaps. 

*/
#include<stdio.h>

void printArray(int *A, int n)
{
       for(int i=0; i<n;i++)
       {
              printf(" %d ",A[i]);
       }
       printf("\n");
}
void selectionSort(int *A , int n)
{
    printf("Running selection sort...\n");
    int indexOfmin ;
    for(int i=0;i<n-1;i++)
    {
        indexOfmin = i;
        for(int j = i+1;j<n;j++)   // Finding the the vaue to exchange   
        {
           if(A[j]<A[indexOfmin])
           {
             indexOfmin = j;
           }
           
        }
        // Swapping the digit ( A[i] and A[indexOfMin])
        int temp ;
        temp = A[i];
        A[i]=A[indexOfmin];
        A[indexOfmin]= temp;
    }
}
int main(){
   int A[] = {3,5,3,13,2};
   int n= 5;
   printArray(A,n);
   selectionSort(A , n);
   printArray(A,n);
   return 0;
}