/* Merge Sorted:- 
Merging procedure:Taking two sorted array. Merging this sort is the result of the sorted array of both sorted array.
Merging Procedure Code:-
size of two sorted array:- m,n (A[],B[])
merge sorted array size : m+n 
void Merge(A[],B[],C[],m,n)
{
   int i,j,k;
   i=j=k=0;
   while(i<m && j<n ) // Loop ends when one of the sortd array is come to end. 
   {
     if(A[i]<B[j])
     {
       C[k]=A[i];
       i++;
       k++;
     }
     else
     {
       C[k]=B[j]
       j++;
       k++;
     }
   }
   while(i<m)   // Coping all element from A TO C
   {
      C[k]=A[i];
      k++;
      i++;
   }
   while(j<n)    // Coping all element from B to C
   {
     C[k]=B[j]
     k++;
     j++;
   }
 
}

# Merging in Single array. 
  Auxalary sorted Array :B[]
  i = low;
  j = mid+1;
  k = low; 
  while(i<mid && j<high) // Loop ends when one of the sortd array is come to end. 
   {

     if(A[i]<A[j])
     {
       B[k]=A[i];
       i++;
       k++;
     }
     else
     {
       B[k]=A[j]
       j++;
       k++;
     }
   }
   while(i<mid)   // Coping all element from A TO C
   {
      B[k]=A[i];
      k++;
      i++;
   }
   while(j<high)    // Coping all element from B to C
   {
     B[k]=A[j]
     k++;
     j++;
   }
   // For Loop coping element from axuary Array to A[]. 
*/
