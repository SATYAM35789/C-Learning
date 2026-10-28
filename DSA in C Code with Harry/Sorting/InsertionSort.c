/* Insertion Sort :- Start Compairsion of two element from back side of the Array. Until found the leser element.
   Example 7,2,91,77,3
   Divide the array in sorted and Unsorted array. By leting the first element as sorted. (Element one element is always sorted)
   2. Unsorted array 1st element is compair with the sorted array element. AND Swap().
   Example 7,2,91,77,3  If small than stop and insert that element. 
           2,7,91,77,3   2  is compair with 7.
           2,7,91,77,3   91 is Compair with 7 and 2.
           2,7,77,91,3   77 is compair with 91,7 and 2.
           2,3,7,77,91   3  is compair wuth 91,77,7,3,2. 

Each line of above are the passes. Pass = n-1 passes. 
1+2+3+4+5....(n-1)= n(n-1)/2 = O(n Square)
Stable:- It is stable. 
Adaptive:- Yes it is adaptive (by nature)
Best case: When array is sorted O(n) 

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
void insertionSort(int *A, int n)
{ 
    int key,j;
    for(int i=0; i<=n-1;i++)  // Loop for each passes
    {
        key=A[i];  // Value which we have to compair with sorted array.
        j=i-1;   // It confirm from which index we have to compair the key element or key value.
        // Loop for each pass
        while(A[j]>key && j>=0)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }

}
int main()
{
    int A[]={12,54,65,7,23,9};
    int n = 6;
    printArray(A,n);
    insertionSort(A,n);
    printArray(A,n);
    return 0;

}