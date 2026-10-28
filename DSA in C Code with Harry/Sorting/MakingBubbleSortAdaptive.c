/* If already sorted than , geting the answer in One pass only */
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
       int isSorted = 0;
       for(int i=0;i<n-1;i++)  // For the number of passes. 
       {      
              printf("Working on pass number %d\n",i+1);
              isSorted = 1;  
              for(int j =0; j<n-1-i;j++)  // For Compairision for each pass. 
              {
                     if(A[j]>A[j+1])  // Swaping Function
                     {
                            temp = A[j];
                            A[j] = A[j+1];
                            A[j+1]= temp;
                            isSorted = 0; 
                     }

              }
              if(isSorted){
                return ;
              }
       }

}
int main()
{
    //    int A[]= {12 , 54 , 65 , 7 , 23 , 9 };
       int A[]= {1,2,6,4,5,7 };
       int n = 6;
       printArray(A,n); // Printing the array before sorting
       bubbleSort(A,n); // Function to sort the array. 
       printArray(A,n);  // Printing the array afater sorting. 
       return 0;

}