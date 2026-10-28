/* Bubble Sort :- Ek EK karke bade element ko end mai bhej do. 
   Compair the element in pair of two. If sorted than left and move to farward element. 

    7 11 9 2 17 4
   1st Pass:- step1. 7 11 9 2 17 4   at index 0 and 1(compairing this index)
                     7 9  11 2 17 4  at index 1 and 2
                     7 9  2 11 17 4  at index 2 and 3
                     7 9  2 11 17 4  at index 3 and 4
                     7 9  2 11 4 17  at index 4 and 5

By Having 1st pass we have Largest element at end. 

       7 9 2 11 4 17
2nd Pass step1: 7 9 2 11 4 17  at index 0 and 1
                7 2 9 11 4 17  at index 1 and 2
                7 2 9 11 4 17  at index 2 and 3
                7 2 9 4 11 17  at index 3 and 2

 By Completed 2nd pass we have 2nd largest element at end. 

7 2 9 2 4 11 17
3rd Pass  step1: 2 7 9 4 11 17 at index 0 and 1
                 2 7 9 4 11 17 at index 1 and 2
                 2 7 4 9 11 17 at index 2 and 3  

By  complited 3rd pass we have 3rd last element in the last. 

At 5th pass we have our sorted array 2 4 7 9 11 17  
NOTE:
Pass = size of array - 1. 

1.Total (No. of Compairsion:- 1+2+3+4+5 ....+(n-1)= n(n-1)/2 = O(n square)
2. Stable Algorithm :- Order is same as the order in input array.
3. Not a recursive Algorithm because we not use it. 
4. Not adaptive:- Because we need to pass the passes if array is sorted or not. (But we can make it adaptive.)

Why name is Bubble? 
Bhari element ek ek kareke end ke taraf pheko. Lighter elment move towords the starting and havier Object move 
towords the end. 
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
void bubbleSort(int *A,int n)
{
       int temp;
       for(int i=0;i<n-1;i++)  // For the number of passes. 
       {  
              for(int j =0; j<n-1-i;j++)  // For Compairision for each pass. 
              {
                     if(A[j]>A[j+1])  // Swaping Function
                     {
                            temp = A[j];
                            A[j] = A[j+1];
                            A[j+1]= temp;
                     }

              }

       }

}
int main()
{
       int A[]= {12 , 54 , 65 , 7 , 23 , 9 };
       int n = 6;
       printArray(A,n); // Printing the array before sorting
       bubbleSort(A,n); // Function to sort the array. 
       printArray(A,n);  // Printing the array afater sorting. 
       return 0;

}