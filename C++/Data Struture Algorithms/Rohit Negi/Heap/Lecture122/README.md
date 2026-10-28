### Height of a Heap :- 
Height = Longest path from root node to leaf Node. Jab hamko height nikalne ke liye bole tab hamko check karna hoga ki wo no of nodes ko count karne ke liye bol raha hai ki no of edges ko. So is question mai no of edges ko count kar rahe hai. 
Approch pahala :- Pahle hum array ke help se tree ko bana lo which take O(n) Time and height find larlo which take O(logn).
Approch :- Node and Height mai relation find karo, which is 2 power n where n is num from 0 to n. And we can also say that logbase2n is equal to Height which means ki 2 ki power kitni hamko N mil jaye. Or kitni baar no of nodes ko dive kar rahe hai ki value 0 or 1 aa jaye. 

Code Implementation :- 
```
#include <iostream>
using namespace std;

int heapHeight(int N, int arr[])
{
    if (N == 1)
        return 1;

    int height = 0;

    while (N > 1)
    {
        height++;
        N /= 2;
    }
    return height;
}

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Height of Heap: " << heapHeight(n, arr) << endl;

    return 0;
}
```

### Minimum Cost of Ropes :- 
Hamko array given hoga jo hamko batayega ki kitne nodes present hai hamare pass. Jitne value hai element wo represent karta hai length of the ropes. So isme kisi bhi do nodes connect karenge tab uska kuchh cost hoga then cost is equal to sum of two nodes or element. Then is cost ko wapas hum apne array mai store kar lenge aur aise he karte jayenge. So Hamko minimum summation of cost nikal kar dena hai. 

Greedy Approch :- Sabse Chhote element ko sabse pahle select karte hai apne cost ko nikalne ke liye. 
1. Two smallest rope ko select karna hai 
2. jab tak single rope n aa jaye. 

So agar do chhote ko nikalna hai toh hamko sort karna padega. Phir jo naya element aaya hai usko sort karna hoga using Binary or Linear sort. So hamko apne array ko sfift bhi karna padega. 

Time Complexity :-
1. For sorting : O(nlogn)
2. Shifting : O(nsq), shifting zaruri bhi aur ye hamari time complexity increse kar de raha hai. 

Solution:-
We can use min heap(priority queue.)
Time Complexity :- 
1. To build : O(nlogn) we use this because Insert and Delete Operation dono karna hai. 
 jab hamko ek array given usko bulid karne ke time complexity O(n)(step-down) agar ek eke karke dalte hai toh O(nlogn) ho jayengi. 
Note :- Deletion mai hamko O(nlogn) lagena wala he hai. 

Code Implementation :- 
```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long> , greater<long long> > p;
    for(long long i=0;i<n;i++)
    {
        p.push(arr[i]);
    }

    long long cost = 0;

    while(p.size()>1)
    {
        long long rope = p.top();
        p.pop();
        rope+= p.top();
        p.pop();
        cost+= rope;
        p.push(rope);
    }
    return cost ;
}

int main()
{
    long long arr[] = {10, 3, 8, 9, 5, 13, 2};
    long long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum cost of " << minCost(arr , n)  << endl;

    return 0;
}
```

### Magician and Chocolates :- 
Hamko ek array diya hoga jo show kar raha hai, no of element present in the array is showing  the bags and value present in the element is shing the no. of chcolate present in it.  A : Total time diya hai, aur hum kisi bhi bags se  kho khol kar 1 sec mai chocolate kha sakte hai. Maximum chocolate hamko uthana hai. Ek twist hai agar jis bhi bag ko hum choose kate hai, jitna bhi value hai bag mai wapas value ka 1/2 aa jayenga. Jab Total Time khatam nahi hota tab tak hum ye kaamkarte jayenge. 

Approch :- Same a we discuss in last question Create sorted array, and thain again have to do sort and select our biggest element. Time complexity : [ A*n + nlogn]
Hab hamko n time lag he raha hai toh sort karne ke koi fayada he nahi ham linear search laga sakte hai. 
Time Complexity : [ A*n ] A may be n , nsq, ncub, etc

Approch :- Using Max Heap. We need 2logn time on a particular node to insert and delete. 
Total Complexity: Alogn + nlogn(stl case) + n(array) = Alogn.

Note  Array : jab Deletion or Insertion , Heap : Jab Deletion and Insertion sath mai karna ho. 

Code Implementation :- 
```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int MagiAndChocolate(int A, vector<int> &B)
{
    // Max Heap
    priority_queue<int> p;
    for (int i = 0; i < B.size(); i++)
    {
        p.push(B[i]);
    }
    long long MaxChoc = 0;
    while (A && !p.empty())
    {
        MaxChoc += p.top();

        if (p.top() / 2)
            p.push(p.top() / 2);

        p.pop();
        A--;
    }
    return MaxChoc;
}

int main()
{
    vector<int> B2 = {2, 4, 6, 8, 10};
    int A2 = 5;
    cout << " Result: " << MagiAndChocolate(A2, B2) << endl;

    return 0;
}
```

### Last Stone Weight :- 
Ek array give hoga, no. of element present in it is a no. of stone. and value represent the weight of the each stone. Jo do sabse bhari hai un ko pakdo apas mai takdo, jo unka difference hoga wahi bachega aise karte jao at the end jo stone bacha hoga uska weight lakar de dedo. 

We are doing both insertion and deletion in this as removing two element and unke difference ko insert kar de rahe hai. Ek Complete process 3logn(2 deletion 1 Insertion)

Code Implementation :- 
```
int lastStoneWeight( vector<int> &stones)
{
    // Max Heap
    priority_queue<int> p;
    for (int i = 0; i < stones.size(); i++)
    {
        p.push(stones[i]);
    }
    while(p.size()>1)
    {
        int weight = p.top();
        p.pop();
        weight-=p.top();
        p.pop();

        if(weight)  // 0 push n ho
        p.push(weight);
    }

    return p.empty()? 0:p.top();
  
}
```

### Take gift from the richest pile

### Profit Maximization :- 
Array hamko diya hoga, index are showing the rows and values stored in the index are showing the left sit in that row. Hamko sirf B tickets bhejna hai, jitni site khali hai utna uska price hoga, so hamko maximum profit dena hai. Ham yaha max ko select kar rahe hai .
Insertion and deletion dono sath mai kar rahe hai so we use heap here. 

Code Implementation :-
```
int profitMaximization(int A, vector<int> &B)
{
    // Max Heap
    int sum = 0;
    priority_queue<int> p;
    for (int i = 0; i < B.size(); i++)
    {
        p.push(B[i]);
    }

    // Selling the ticket to A people
    while(A && p.empty())
    {
        sum+=p.top();

        if(p.top()-1)
        p.push(p.top()-1);

        p.pop();
        A--;
    }
    return sum;
}
```
