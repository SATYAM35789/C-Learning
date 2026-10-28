### Josephus Problem || Predict the winner 
So is question mai hamko n aur k ki value diya gaya hoga. Condtion ye hai ki kth element har round mai eleminate hota rahega. Like if n=5 (person) and k =3 then isme kahi ek start hoga aur k yani 3rd person eleminate hota rahega, iska baad count kth ke baad wale se start hogi. 
- So yaha 5 person hai jo ek circle ke form mai hai, kisi bhi ek se counting start hogi, jab counting k ke barabar ho jayegi then ham jaha honge usko eliminate kar denge , and next wale phir se counting start karenge. 

-So hamne abhi tak toh koi bhi aisa structure nahi pada hai jo circle ke form mai ho so we use array. 
- So n-1 size ka array and index represent the person, Array bool type ka hai so isme initially 0 hai which means ki abhi eleminated nahi hai. 
- So array ke 1st element, which represent 1st person, se counting start karenge aur kth element ko eleminate  karenge. 
- eleminate person ke just baad wala jo eleminate nahi hua hai waha se next counting karenge.
- and so on karte jao jab  tak ek person bache, and declare that element as winner. 

Array ko circular banane ke liye : index = (index+1)%n (increment)

Code Part:-
- vector bool type ka person of n size
- person_left : batayega ki kitne person bache hue hai. 

winner() :
ek int type ka winner fun, parameter : 1d vector person, int n , int index, int person_left, int k
- Base Case :- 
  -if(person_left==1)
  - Trverse using for loop and check if the element is == 0 then that index(person) is winner.
- int kill = (k-1)%left_person
    If k is bigger than n then like if n=6 and k= 10 then kth element = (k-1)%left_person
- while(kill--)
  - index ko wk se increse kardo i,e index = (index+1)%n;
  - agar index ko ek badane ke baad, agar us index ki value 1 hai then kill ko ghatana nahi index ko aage badte jana hai kyuki wo pahle se he eliminate hai. 
    - while(person[index]==1)
       - index = (index+1)%n;
- Ab index usko he point kar raha hoga, jisko kill karna hai e,g person[ index] = 1 kardo
- Find the person ab jaha se counting phir se start hogi
  -  while(person[ index]==1)
      - ek se aage badte jao e,g index = (index+1)%n;
- Ab phir se function call kare next round ke liye game ki, return winner(person,n,index,person_left-1,k)

Time Complexity : O(nsq)
Space Complexity : O(n)

Code Implementation :- 
```cpp
#include <iostream>
#include <vector> 
using namespace std; 

int winner( vector<bool> &person,int n, int index, int personLeft, int k)
{
    if(personLeft==1)
    for(int i=0;i<n;i++)
    if(person[i]==0)
    return i; 

    // Find the position of kill
    int kill = (k-1)%personLeft ;

    while(kill--)
    {
        index = (index+1)%n;
        // If found the Already killed person, then unse aage chalo
        while(person[index]==1)
        index = (index+1)%n;
    }
    
    // Found the kth position
    person[index] = 1;

    // find, Next alive person
    while(person[index]==1)
    index = (index+1)%n;

    return winner(person,n,index,personLeft-1,k);

}

int findTheWinner(int n, int k)
{
    vector<bool> person(n,0);
    return winner(person, n, 0,n,k) +1;
}

```

Variation :- Solve the problem in O(n) and not use the extra information array.
->So hamko pata hai ki jab n==1 ho jayega tabhi hamko answer mil raha hai. So pettern is ki har ek call mai n ki value ek se kam ho ja rahi hai. 
-> So we need to keep the track as jo eliminate ho ja rahe hai, hamko next round mai kaise pata chalega ko we eliminate hai. So ham bina track rakhe kaise solve kar sakte as if jab ham track rakh rahe hai tab hamko ek array ki zarurat pad rahi hai. 
-> Example
when n =5 and k=3 
Different Iteration :- 
0,1,2,3,4 (n=5) -> 3,4,0,1 (n=4) -> 1,3,4 (n-3)-> 1,3 (n=2) ->3 (n=1)

What if when n=4 the we can call 0,1,2,3 instead of 3,4,0,1 we just need to create pattern between the :- 
0 - 3  -> 1 - 4  -> 2 - 0  -> 3 - 1 
So if ab answer 0 aa raha hai iska matlab actual mai toh 3 winner hai. So yaha kuchh hua nahi bas +k add ho gaya hai. 
- Dekho hamko pata hai 2 - 0 -> 2+k -> 2+3  -> 5 ,lakin 5 toh exist he nahi karta hai then we need modeulas of n. 

Code Part :- 
```cpp
int winner(int n, int k)
{
  if(n==1)
  return 0;

  return (winner(n-1, k) +k)%n ;
}
```
winner(n,k) = winner(n-1,k) + Relationships
winner(n,k) = (winner(n-1,k) + k)%n

Time Complexuty : O(n)
Space Complexity : O(n)

Code Implementation :- 
```cpp
#include <iostream>
using namespace std;

int winner(int n, int k)
{
    if(n==1)
    return 0; 

    return (winner(n-1,k)+k)%n;
}

int findTheWinner(int n, int k)
{
   return winner(n , k)+1;
}
```