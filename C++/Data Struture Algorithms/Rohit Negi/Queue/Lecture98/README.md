### Print all in every window of size k :- 
K no of element of ko pahle print kar do , phir ek se increment karna hai k ko. 
Approch:- 
1. Sabse pahle k-1 element push karwa denge. Phir kth wale start karenge, print kardo sabko , phir pop kardo (aage wala element chala jayega) , isi procedure ko last tak karte raho. 

Code part:-
1. Ek queue bana lenge q naam ka
2. phir ek for loop k-1 tak ka , jiske q.push kardo element jab tak for loop exist karta hai.
3. Ek aur for loop ji k-1 se start hoga aur n tak chalega. 
   1. q.push kardo arr of i ki value ko.
   2. display(q) , puri queue ko print kardo. 
   3. q.pop() kardo. 

display() :- parameter queue<int>q;
1. jabtak queue khali nahi ho jata tab tak
   1. queue ke front ko print kardo
   2. pop()

Code implementation :-
```
#include<iostream>
#include<queue>
using namespace std;

void display(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
    cout<<endl;  

}

int main()
{
    int arr[] = {2,3,2,4,5,65,6,6};
    int n = 8;
    int k = 3;

    queue<int> q;
    // k-1 elements ko print kardo queue ke ander
    for(int i=0;i<k-1;i++)
    q.push(arr[i]);

    for(int i=k-1;i<n;i++)
    {
        q.push(arr[i]);
        display(q);
        q.pop();
    }
    return 0 ;
}
```
### First -ve integer in every window of size
First -ve no. ko print karwana hai, if not -ve no then print 0 on place of  that value. 
Code part :- 
1. ek  queue le lo int type ka
2. pahle k-1 tak element ko push karwa do , for loop ke help se. 
3. ek aur for loop , jo k-1 se start hoga aur n tak jayega. 
   1. queue mai arr of i ki value daal do. (Given array)
   2. display kardo first negative value ko. aur is ans ko ham ans naam ke vector mai dal denge. 
4. return the ans. 

disple(): parameter vector<int> q;
1. agar queue khai nahi hai
   1. agar q ka front, chhota hai 0 se print kardo q.front ko
   2. queue ko pop kardo .
2. return 0; ye positive ke case mai 0 return kar dega. 

Time complexity :- O(nk)
Space complexity :- O(k) space use kar rahe isko solve karne ke, ans ko ignore kardo. 

Code Implemntation :- 
```
long long display(queue<long long> q)
{
    // First -ve int
    while (!q.empty())
    {
        if (q.front() < 0)
            return q.front();

        q.pop();
    }
    return 0;
}

vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int k)
{
    vector<long long> ans;
    queue<long long> q;

    // K-1 element ko push kardo
    for (long long int i = 0; i < k - 1; k++)
        q.push(arr[i]);

    for (long long int i = k - 1; i < N; i++)
    {
        q.push(arr[i]);
        ans.push_back(display(q));
        q.pop();
    }
    return ans;
}
```

Optimized Appproch :- 
Dekho hamko pata hai ki positive number kabhi ans nahi ho skakte to hamko +ve no ko daalne ki koi zarurat bhi nahi hai. Jaise he front wala -ve number hamare windo se bahar hota hai, ham usko pop karwa denge, kaise?. Dekho agara ham sirf -ve number he kyu daal rahe hai ham pahle window ke -ve print karwa denge , lakin ham ye pata karne mai muskil hogi ki jo -ve number usko bahar nikalna hai ki nahi , -ve no, usi window ka part hai. Ham queue ke ander sirf -ve index wala  dalenge. Agar ham present index - size of ke karde toh hamko pata chal jayega (result aur usse chhota wala nahi reahega). Jo part nahi hoga window size ka usko pop kar denge. 

Code Part :- 
1. ek queue banalo q naam ka
2. ek for loop cahalayenge k-1 tak, queue mai push karwa denge. 
3. Agar array of i chhota hai 0 se, toh queue mai index ko daal denge. 
4. Ek vector bana lo ans naam ka
5. Ek for loop chaayenge k-1 se n tak,
6. Agar arr of i chhota hai 0 se tab , queue mai pusj kar do index ko. 
7. Agar queue empty hai, ans vactor mai 0 push kar denge. 
8. else mai
   1. Agar q1front() chhota hai i-k se (window size), usko queue mai pop kardo
   2. Agar queue empty hai tab, ans mao 0 daal do.
   else mai , ans mai A of qfront() ke velue daal do. 
9. return ans ko

Time Complexity :- O(n)

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int k)
{
    vector<long long> ans;
    queue<long long int> q;

    // k-1 elements ko push kar do, only -ve element ko
    for (long long int i = 0; i < k - 1; i++)
    {
        if (arr[i] < 0)
            q.push(i);
    }
    for (long long int i = k - 1; i < N; i++)
    {
        // push the negeative only
        if (arr[i] < 0)
            q.push(i);

        // Apne ans mai pahle window size ke first -ve ko push karwa rahe hai
        // Queue Empty
        if (q.empty())
            ans.push_back(0);
        // Queue mai koi value present hai
        else
        {
            // Check if first index of queue lies inside the window
            if (q.front() <= i - k)
                q.pop();

            if (q.empty())
                ans.push_back(0);
            else
                ans.push_back(arr[q.front()]);
        }
    }
    return ans;
}
```

### First non repeating char in a stream of characters 
Given character of string ek new character of string mai change karo, with condition 1. String ko traverse kar rahe hai is samay agar character first non repeating hai toh usko ans mai daal denge. 2. Agar sa repeating hai while traversing then return # . 
Approch :- 
Ek array lete hai 26 size ka jo a-z char ko show karega aur isko 0 se initialize kar denge. Ab traverse karenge jo character aata hai usko ek se increment  kar denge.Agar ek se zada bar aa raha hai usko queue se remove kardo if ek than push it in the queue. 

Same Approch with modification:-
Sab same sirf ab push karte samay ham ye check kar lenge ki kya repeated hai ki nahi. 

Code Part :-
1. Ek empty string B naam ka, inialize 
2. ek vector banayenge int type ka repeated naam ko jo 26 size aur 0 se initialize hoga. 
3. ek queue char tpe ka jiska naam 
4. ek for loop jo given string ke A.size() tak chalega. 
   1. Agar (A[i] - a )>= 1 hai toh daalne ki zarurat nahi hai ex A[i]=C hai c-1 = 2 then 2 index ko check karenge kya ye greater than 1 hai ki nahi.
   2. A[i]-'a' ko increse kar do ek se. 
   3.Agra queue empty nahi hai aue Agar repeated mai (q.front()-a) > 1 than ye repeated hai than isko pop kar do. 
     1. Agar queue empty hua, B string mai # ko daal do
     2. else :- B String mai queue ka front wala daal do. 
   else :-   Agar repeated nahi hua hai
   1. repeated ko ek se increse kar do
   2. A of i ko queue mai push kardo
   3. Agar repeated mai (q.front()-a) > 1 than ye repeated hai than isko pop kar do. 
   4. B String mai queue ka front wala daal do. 
5. Return kardo B ko. 

Time Complexity : O(n)

Code Implementaion :- 
```
string firstNonRepeatingChar(string A)
{
    string B = "";
    vector<int> repeated(26, 0);
    queue<char> q;

    for (int i = 0; i < A.size(); i++)
    {
        // Agar charater repeated hai, queue ke ander push nahi karna hai
        if (repeated[A[i] - 'a'] >= 1)
        {
            repeated[A[i] - 'a']++;
            // Repeated nahi hai so, queue mai jo front hai usko add kar do B mai
            while (!q.empty() && repeated[q.front() - 'a'] > 1)
                q.pop();

            if (q.empty())
                B += '#';
            else
                B += q.front();
        }
        // Agr character non repeated hai , toh queue ke ander push karna hai
        else
        {
            repeated[A[i] - 'a']++;
            q.push(A[i]);
            while (repeated[q.front() - 'a'] > 1)
                q.pop();

            B += q.front();
        }
    }
    return B;
}
```

