### Largest BST :-  
Ek hamko Binary tree given hoga, Jisme agar BST exist karta hai then usko wapas kardo. Agar aise bahut sare sare exist karte then hamko sabse bada wala return kardo. 
Brute Force Approch :- Hum sabhi nodes ko check kar sakte hai kya wo binary search tree hai if hai then uska size store karlo aur use bhi dekhlo aise agar exist kare toh uska size size note down karlo and so on, jo isme sabse bada hoga usko hum return kar denge. Size means ki us tree mai kitne nodes present hai. Agar bada size ka mil gaya hai toh chhote ko add nahi karenge. 
Time complexity :- IsBst() O(n) + for all nodes O(n) = O(nsq).

Approch second :- Dekho last approch mai sabhi nodes par jakar check kar rahe the kya ye BST hai ki nahi if ues then uske left aur right ko bhi check kar rahe the, ki bst hai ki nahi. So hab hamko BST mil gaya toh uske left right toh bst honge so hamko check karne ki zarurat he nahi . Ab yahi karenge.

O(n) :- Ye Basic info hona chahiye on the particular node.  
1. Left BST hai ki nahi
2. Right BST hai ki nahi
3. Left side ka max element chhota hona chahiye root ke data se.
4. Right side ka min element bada hona  chahiye root ke data se.
5. Size = LeftSize + RightSize +1. 

Note In sari info ko hum ek clsaa ke ander store kar lete hai. 

Code Part :- 
1. Box naam ek class ban lo, public mai bool type ka BST le lo, int type ka size, main aur max lelo.
2. Box constructor call karlo, parameter: int type ka data (for single node)
   1. BST mai 1 daal do
   2. size mai bhi 1 daal do
   3. min aur max mai data ko daal do. 

largestBST()
1. largestBST() int type ka, Parameter: Node type ka root pointer
2. int type ka TotalSize jisme 0 daal do
3. find() call kardo, parameter: root, TotalSize
4. TotalSize ko return kardo. 

find() : We need to discuss these four cases 
1. leaf Node
2. only Left side exist
3. only right side exist
4. Dono side exist karta hai

1. find() Box type ka, parameter: Node type ka root pointer, int type ka TotalSize(as reference)
2. Leaf Node :- Agar root ka left aur root ka right exist nahi karta then,
   1. return kardo new Box(root->data).
3. only right side exist :- Agar root ka left exist nahi karta aur root ka right  exist karta hai then
   1. Box type ka head pointer mai find call kardo for right side find(root->right, TotalSize)
   2. Agar head ka BST exist karta hai aur head ka min bada hai root ke data se then
      1. head ke size ko ++ kardo
      2. head ke min mai root ka data daal do
      3. max(TotalSize, head->size)
      4. return head apne upper wale ko apni info bhej do. 
   3. Agar aisa nahi hota then, head ke BST ko 0 kardo means ki BST exist nahi karta aur return kardo head ko.
4. Only left side exist :- Agar root ka left exist karta hai aur root ka right exist nahi karta then
    1. Box type ka head pointer mai find call kardo for left side find(root->right, TotalSize)  
    2. Agar head ka BST exist karta hai aur head ka max bada hai root ke data se then
        1. Head ke size ko ++ kardo
        2. head ke max mai root ka data daal do
        3. TotalSize mai max(TotalSize,head->size)
        4. return kardo head ko
     3. Agar aisa nahi hota then, head ke BST ko 0 kardo means ki BST exist nahi karta aur return kardo head ko. 
5. Agar left aur right dono exist karte hai, 
    1. Box type ka lefthead pointer mai find call kardo for right side find(root->right, TotalSize)
    2. Box type ka righthead pointer mai find call kardo for left side find(root->right, TotalSize) 
    3. Agar lefthead aur righthead ka BST exist karta hai aur lefthead ka max chhota hai root ka data se aur righthead ka min bada hai root ke data se then
       1. Box type ka head pointer bana lo jisme new Box(root->data)
       2. head ka size mai lefthead ka size + righthead ka size + 1
       3. head ke min mai daal do lefthead ke min ko
       3. head ke max mai daal do righthead ke max ko
       5. TotalSize mai daal do max(TotalSize,head->size)
       6. Return kardo head ko.
   else
     1. lefthead ka BST ko 0 kardo and return kardo leafthead ko.

Code Implementation :- 
Method 1:-
```

``` 

Method 2:-
```

```

### Maximum Sum BST in Binary Tree :- 