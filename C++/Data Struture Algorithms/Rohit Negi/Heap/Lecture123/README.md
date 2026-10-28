### Kth Smallest Element :- 
Hamko ek array given hoga aur hamko puchhega ki isme kth smallest elemt konsa honga, If the element are duplicate then usme se ek ko 1st element maan lo 2nd wale ko 2nd smallest maan lo. 

Approch 1st :- Pahle aary ko sort karo then k times traverse karne ke baad value ko find karlo.
Time Complexity :- nlogn+1 = nlogn. Space Complexity : If Use Heap Sort O(1) and Merge sort O(n).

Approch 2nd :- Using Min Heap. Min heap kth times apne min heap se value ka bahar nikalenge and then usko Heapify means usko phir se sahi order mai kar denge. 
Time Complexity :- n + klogn
Build Heap : 1. Direct step down technique (n)(pure array ko ek sath used karte hai tab)  2. If used priority queue nlogn (ek ek karke element dalte hai tab).
Deletion : For single we need logn but for kth node it is klogn.
Space Complexity : O(1)

Approch :- If K=4. Dekho randomly pahle ham Array ke 4 element ko lenge then unme se jo sabse chhota hai wp hamara 4th smallest element hoga, ab jo naya element isme ham lenge if wo in sab mai se kisi ek se chhota hoga then usko id group mai enter kar lenge. Us group ke sabse bade element se apne nexy element ka compairsion kar lo is chhota then entry milegi if bada then no entery. Group = Max Heap. 
Note :- Smallest Element ke liye = Max Heap and Largest Element Ke liye = Min Heap. 
Time Complexity :-  K + (n-1)*logk  = nlogk
Build Heap : 1. Direct step down technique (k)  2. If used priority queue klogk.
Deletion : For deletion bigger element O(logk)  and inserting smaller O(logk), for single node. Overall is (n-k)*2logk.

Code Implementation :- 
```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// arr : given array
// l : starting index of the array i.e 0
// r : Ending index of the array i.e size -1
// k : Find the kth element 
int kthSmallest(int arr[], int l , int r, int k)
{
    // Max Heap
    priority_queue<int> p;
    // Heap mai k element ko push karwa liya
    for(int i=k;i<k;i++)
    p.push(arr[i]);

    // ab k ke baad wale element ko traverse kar rahe
    for(int i=k;i<=r;i++)
    {
        if(arr[i]<p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }

    // apne kth element ko wapas kar rahe jo sabse max mai sabse uppar hai
    return p.top();
}

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout<<"Enter the value of k";
    cin>>k;

    cout << "Finding the Kth smallest element :
    return 0;
}
```

### Kth Largest Element :- 
All the approches we discuss above applied to the question too. 
Agar next element agar kisi bhi ek se bada aata hai then it is the part of the group. Smallest of the group se compair karenge. Agar us se bada hai toh group ka part ban jayega. 
Time Complexity : nlogk and Space Complexity :- O(k).

Code Implementation :- 
```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findKthLargest( vector<int> &nums , int k)
{
    // Max Heap
    priority_queue<int, vector<int> , greater<int>> p;
    // Inserting k element i the min heap
    for(int i=0;i<k;i++)
    p.push(nums[i]);

    // left element of the arr ko compaire karte hai
    for(int i=k;i<nums.size();i++)
    {
        if(nums[i]>p.top())
        {
            p.pop();
            p.push(nums[i]);
        }
    }
   
    return p.top();
  
}

int main()
{
    vector<int> nums = {2, 4, 6, 8, 10};
    int k;
    cout<<"Enter the value of k";
    cin>>k;
    
    cout << " Last Stone Weight "<< findKthLargest(nums,k) << endl;

    return 0;
}
```

NoteEk aur approch hota hai, quick select, quick sort ke jaisa hai. Worst Case: O(nsq) But Average Case is n.  

### Kth Largest Element in a Stream :- 
Hamko array of stream diya hoga, hamko kth largest value batana hai. Jaise ki 1 element choose kiye tab toh hum nahi bata sakte ki kth largest kon sa kyuki hamare pass kth element he nahi, so ja kth element ho jayega usme sabse bade ko return kardo phir aage usme jo sabse bada hai usko return kardo.   

### Sum of element between k1 and k2 smallest element :- 
If k1 =3 and k2 = 6 so ab k1 smallest se k2 ke smallest element tak ka sum dena hai. 
Approch 1 : Array ko sort karo k1 smallest index par jao and k2 smallest par jao then k1 se k2 element ko sum karte jao aur ans return kardo. 

Approch 2 :-  k1 element ko max heap mai store karolo, phir k2 ko max element ko store karlo, k2 heap - k1 heap kardo and, k2 ke sabse bade element ko remove kardo ans se because jo ke starting mai top element tha wo hamara k1 aur k2 ka sabse bada element tha.

Code Implementation :-
```

```