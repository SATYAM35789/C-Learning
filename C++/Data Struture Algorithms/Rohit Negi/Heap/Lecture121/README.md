### Build Heap :- 
1. Step-Up:-
Yaha jab hum heap bana rahe honge then hum apna compairsion start karenge 2nd level se because kyuki 1st level or root ka toh koi parenet hai he nahi sa usse compair karne ka koi matlab he nahi hai. Inseerting ke liye :-
Last level ko left - right ke direction mai fill karenge. aur then apne insert kiye gaye element ko compair karlo apne parents ki max heap ki condition follow hai ki nahi. 
Time Complexity :- O(nlogn)
1. Jab naya element aayega tab worst case uske puri tree ki height ko cover karna padega for example bada ko cover to reach the root. So it is CBT so it takes logn time. 
2. level size : n +n/2 + n4... and need steps to reach the at root on each level logn + logn-1 + logn-2..
By multipying them we got our ans.  Apne last wale session mai Complexity ko update kar dena .

Note :- In Case of step-up we have time complexity nlogn.

2. Step-down:- 
Comparison done b/w parent to child. Parents se child nikalne ka tarike 2*i+1. 
How can we come to know that from which element we need to compair or Konse element ki children exist karte hai ye kaise pata chalega. :- used (n/2 -1) where n is the total no element present in the heap. 
Time Complexity :- O(n)

Code Implementation :- 
```
#include <iostream>
using namespace std;

// process of compairing parent with child, to bild max or min heap
void maxHeapify(int arr[], int index, int n)
{
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left<n&& arr[left]>arr[largest]);
    largest = left;
    if(right<n&& arr[right]>arr[largest])
    largest = right;

    if(largest!=index)
    {
        swap(arr[largest],arr[index]);
        maxHeapify(arr, largest,n);
    }
}

void minHeapify(int arr[], int index, int n)
{
    int smaller = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left<n&& arr[left]<arr[smaller]);
    smaller = left;
    if(right<n&& arr[right]<arr[smaller])
    smaller = right;

    if(smaller!=index)
    {
        swap(arr[smaller],arr[index]);
        minHeapify(arr, smaller,n);
    }
}

void BuildHeap(int arr[], int n)
{
    // Step down
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr,i,n);
        minHeapify(arr, i,n);
    }
}

void printHeap(int arr[], int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
}

int main()
{
    int arr[] = {10, 3, 8, 6, 4, 13, 15, 12, 56, 43};
    BuildHeap(arr, 10);
    printHeap(arr,10);

}

```

Here we use the Heapify process where we use recursive calling which mau take logn space complexity we can use while to decrese the space complexity. 

### Heap Sort :- 
Descending order:- 
1. Max ko bahar nikalo(store karlo arr mai) then heapify lagao and so until all element are not acessed. Agar isika reverse order karle toh ascending order mai mil jaynega ans. 
Dekho hum jo extra space use kar rahe hai element ko store karne mai usko hata sakte hai, jab apne heap se max ko bahar nikal rahe hai jo ek array hai toh ek space khali ho ja rahe hai pichhe se, so ab apne max nikal kar is space ka use karenge. 
Jab hum ye processed karenge toh hamko ascending order mai ans mil jeyenga direct. Kyuki hum sabse bade element ko last mai rakh rahe hai, second bade element ko 2nd last mai rakh rahe hai and so on. 
Approch step :-  Time Complexity O(nlogn)
1. Replace the first with last element 
2. Decrese size by 1
3. Apply heapfy

Code Implementation :- 
```
void SortArray(int arr[], int n)
{
    for(int i=n-1;i>0;i--)
    {
        swap(arr[i],arr[0]);
        Heapify(arr,0,i);  // i = n-1
    }
}
```

Agar Heapify ko hum iterative or using while solve karte hai tab O(1) space Complexity mai ho jayenga. 

### Priority Queue :- Implement through max and min Heap
Yaha hum koi bhi kaam priority based par karwate hai, like Vip Entry at temple, hospitals, at bank, etc.
For example we have 2,8,10 and we have decided that jo sabse bada hoga usko service pahle milengi means Wo queue mai sabse aage aa jayenga. Dekho ye actually hamara max/min heap he toh hai jisme sabse bada element service milegi. 
Use Case :- 
1. Computer Network :- 
   Ek network jaha bahut sare log connected hone, and bahu sare router bhi honge, lakho log us network ko use kar rahe honge means differnt request kar rahe honge like video streaming, calling, youtube, web browsing and so on. Router use karta hai priority queue, how the router decide  ki pahle kiske reqest ko pahle de, agar aisa kare ki jo pahle aayi hai pahle usko serve jaro, then toh video call nahi kar pate kyuki yaha hamko chize jaldi jaldi chahiye, or real-time talk khatam ho jayenga. 
   So packet ke form aata hai, so video call hai toh iski priority sabse jada hogi vhaye ye pichhe kyu na ho. Just like Agar email  or message sending agar 3 4 sec late hoga tab bhi koi fark nahi padega. 

2. Operating System :- Different process ko schduling like webBrowing, Music Open karo, and some critical task were there jinko execute karana zaruri hota hai. like kernal ke processes jinki high priority hoti hai. 

Code Implementation :- 
```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> p; // Max heap wali
    p.push(10);
    p.push(50);
    p.push(13);
    p.push(180);

    cout << " Printing top of element\n";
    cout << p.top() << " ";

    // Deleting the element
    p.pop();
    cout << p.top() << " ";

    // Size
    cout << p.size() << " ";

    // Traversing
    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
}
```
