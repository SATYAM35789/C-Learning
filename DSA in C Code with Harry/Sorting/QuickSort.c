/* Quick Sort:-  jo bhi no add hoga , uske left side usse chhote aur right side usse bade hone chahiye. 
 Taking as refernce (Zero index value/lavina)
 i= Find the bigger element than the reference(lavina)
 j= Find the smaller elment than the reference(lavina)/ barabar nhi chalega. 
Condition if there is smaller element than the reference(lavina)
:- When j and i cross each other than interchange the lavina with j. (While acheving this we got right position of lavina)
This process of known as partial sorting the array. (Divide and conqur)

 Partionting Procedure:- 
 J and i are the index value 
 low= lowest index value
 high= Highest index value
 1. i=low
 2. j=high
 3. pivat=low
 4. i++ until element less than pivat is found
 5. j-- until element greater or equal pivat is found
 6. Swap A[i] & A[j] and Repeat 4 and 5 until j=<i
 7. swap pivat and A[j]

 Analysis of Quick sort Algorithm 
-> Already sorted element 
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

int partition(int A[], int low, int high)
{

    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;
    do{

        while(A[i]<=pivot) // Find the the bigger element than pivot
        {
           i++;
        }
        while(A[j]>pivot) // Find the the smaller element than pivot
        {
            j++;
        }
        
        if(i<j)
        {
          temp = A[i];
          A[i]= A[j];
          A[j]= temp;
        }
     } 
     while(i<j);
     // Swap A[low] and A[j]
     temp = A[low];
     A[low]= A[j];
     A[j]= temp;
 
 return j;
}
void quickSort(int A[], int low , int high){
    int partitionIndex ;
    if(low<high){  // Low<high means there no left element in  the array. 
      // Index of pivot after 1st partition  
      partitionIndex = partition(A,low, high);
      printf(A,9);  // show each partition.
      quickSort(A,low,partitionIndex-1); // Pivotindex ke left side wale part par run karne ke liye.(left subarray)
      quickSort(A, partitionIndex,high);  // PivotIndex ke rightside wale part par run  karne ke liye.(right subarray)
    }
}

int main(){
   int A[] = {3,5,3,13,2,78, 78 , 98 ,4,99};
   int n= 10;
   printArray(A,n);
   quickSort(A ,0,n-1);
   printArray(A,n);
   return 0;
}