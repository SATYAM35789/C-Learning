### Introduction to Heap 
Computer network mai packets ke liye and OS mai process scheduling ke liye bhi use kar sakte hai. 
Definition:- It is a complete Binary Tree(CBT). 
Complete:-
1.  All the levels are completely filled except the last level. 
2. Last Levels nodes should be filed by from the left side. 

There two types of heap :- 
1. Max Heap :- 
   1. CBT
   2. Parent node should be greater than or equal to child mode.
Note:  This property should be satisfied by all the nodes.  
Property:
1. Max element will be present at the root.

2. Min Heap
   1. CBT
   2. Parent node should be lessthan or equal to child mode.
Note:  This property should be satisfied by all the nodes. 
Property:
1. Min element will be present at the root.

Creating Max Heap :- 
So max heap create waqt iski definition ko dhyan rakhna hoga, if small element aata hai then generally uski next position jo ki CBT ko maintain karti waha attach kardo, if the element is bigger then its parent then change the parent with the coming node and again check Max heap is possible if not then again do the same change the parent with coming nodes and so on. 

Implementation of Heap:- 
1. Linked List :- Dekho linked list ke through isko implement karna is not efficient way beacuse
  1. Insert karne ke liye hamko postion khojna hoga O(n)
  2. Phir Check karna hoga parents se ki, ye max heap hai ki nahi, swapping ko bhi dekhna hoga
  So if it is singly Linked list then it becomes more complex and complex. 

2. Array :- Efficient way to build a Heap. 
   1. Heap value ko array ke form mai stored kar lenge in L to R order level wise. 
   Inserting : Agar bade element ko insert karna hai then, we need the find the parent position so to swap and so comparision.
   1. If Parent index is i, then 
      left = 2*i+1  
      right = 2*i+2
   2. If child index is given and we have to find the parent then use (i+1)/2.

   Time Complexity :- Insert karne ke liye kya karte hai, hum normally compair karte apne parents jab parent bada milta hai waha ruk jayenge aur waha insert kar lenge Complexity = log(n).
    

Insertion Implementation Code :-
```
     // Insert in the heap
    void insert(int value)
    {
        // Checking ki insert kar sakte hai ki nahi
        if (size == total_size)
        {
            cout << "Heap is overflow\n";
            return;
        }
        // Agar size bacha toh insert kar denge.
        else
        {
            arr[size] = value;
            int index = size; // Ki particular index par insertion hua hai.
            size++;

            // Correct position khjna: compair with itsparent
            while (index > 0 && arr[(index - 1) / 2] < arr[index])
            {
                swap(arr[index], arr[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
            cout << arr[index] << " is inserted into the heap \n";
        }
    }
```
The process of inserting in the known as the step-up as in every step we go up and compair with parent. 

#### Deletion in the Max heap :- 
Deletion ham hamesha top wale element ko he karte hai.
So ham direct apne root ko delete nahi kar sakte ham apne last node ko apne root ke element se replace karna hoga.  so ke ye apni property CBT ko hold kar sake. Phir uske hamari second proprty ki parent max hona chahiye apne child is property ko hold karwa lenge agar nahi karta toh apne child se swap karenge agar koi bada milta hai us se swap karwa denge and so on until uske dono child us particular nodes se chhota n ho jaye. 
Parent se child node nikalne ke liye :-
  1. If Parent index is i, then 
      left = 2*i+1  
      right = 2*i+2
Heapify :- Apnr node lo pakdo aur usko correct position pad chale jao by compairing with its child , is process ko heapify kahta hai. Also known as the step down process (while deleting in the heap).
Time Complexity = logn. 

Code Implementation :- 
```
    void Heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Largest store index of element which is greater b/w parent, right and left.
        if (left < size && arr[left] > arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right; // Iske baad parent,left aur right mai jo bada hai wo largest ke ander aa jayenga.

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }
    }

    // Delete in the heap
    void Delete()
    {
        if (size == 0)
        {
            cout << " Heap Underflow \n";
            return;
        }

        cout << arr[0] << " Deleted from the heap ";
        arr[0] = arr[size - 1]; // Last element ko 1st position par laa rahe hai
        size--;
        if (size == 0)
            return;

        Heapify(0);
    }
```

