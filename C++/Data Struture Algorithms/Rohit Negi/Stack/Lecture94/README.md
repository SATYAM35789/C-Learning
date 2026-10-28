### Get minimum element from stack :- 
Ham ko ek stack banana hai jo push, pop, getMin function ko designkarna hai in O(1) time ka. 
Ek stack banayenge jisme Hum jab bhi element push karenge check kar lenge abhi tak ka min element kon sa hai usko ek aur stack banakar store kar lenge and aisa har baar karenge jab bhi pahle wale mai push karenge element ko. 
pop Operation:- karte samay dono element se pop kar denge. 
Code part:-
```
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    int minEle;
    stack<int> st1; // Original value rakhege
    stack<int> st2; // min value after compairing fom both the stack top

public:
    //  Get the min element from the stack
    int getMin()
    {
        if (st2.empty())
            return -1;

        else
            return st2.top();
    }
    // Return the pop element from the stack
    int pop()
    {
        if (st1.empty())
            return -1;

        int element = st1.top();
        st1.pop();
        st2.pop();
        return element;
    }

    // Push element x in the stack
    void push(int x)
    {
        if (st1.empty())
        {
            st1.push(x);
            st2.push(x);
        }

        else
        {
            st1.push(x);
            st2.push(min(st2.top(), x));
        }
    }
};
```
#### Optimized Version
In above , we have used the extra stack so the space complexity is increased we need to minimized the space complexity or we have to use only one stack. Agar aisa possible ho jata hai ki ek he position mai position aur minimum value store kar paye toh kaam ho jayega. 
Ek position par do different value store ho sakti hai ki nahi? 
So using modulas % and / operator we can be able to do so things. Ex 3 and 17 store karna hai 3*100 + 17 = 317 kar sakte hai. Agar alag karnaho toh 317/100 = 2 and 317%100 = 17. 
% :- karne se minimum value mil jayega.
/ :- karne se original value mil jayega. 
This approch is applicable when the range is limited, if not limited range than overflow ho jayega aur jab jis se divide kar rahe wo no, khojane jayenge toh hamko milega he nahi. 

Code Implemention :- 
```
class Solution
{
    int minEle;
    stack<int> st1; // Original value rakhege
    stack<int> st2; // min value after compairing fom both the stack top

public:
    //  Get the min element from the stack
    int getMin()
    {
        if (st1.empty())
            return -1;

        else
            return st1.top() % 101;
    }
    // Return the pop element from the stack
    int pop()
    {
        if (st1.empty())
            return -1;

        int element = st1.top() / 101;
        st1.pop();
        return element;
    }

    // Push element x in the stack
    void push(int x)
    {
        if (st1.empty())
            st1.push(x * 101 + x);

        else
            st1.push(x * 101 + min(st1.top() % 101, x));
    }
};
```

### Maximum of Minimum for every window size
Window size :- Window -> Group of , size:- number so window size means Group of particular element. 
Minimum of every Window Size :- Sare window size mai se jo bhi minimum value hai usko bahar nikalo
Maximum of Minimum for every window size :- Jo bhi minimum aaya hai , usme se Maximum wala he answer hai hamara. 
Problem :- Ek array given hai pahle window size ko select karo then window size ek ek kadam badate jao, jo bhi minimum ho window size ka, usko retuen karo usme se jo maximum ho wo ans hoga. 
Procedure :-   
1. Ek vector bana denge ans naam jisko 0 se initialize kar denge. Kyuki humko diya hai hai ki 0 ya 0 se badi value he store hogi so pahle he kar diye aur badi aayegi toh 0 ko replace kar degi.
2. Ek for loop i chalayenge jo hamko pura given array travere karne mai help karega. (kitne type ke window size honge) 
3. Ek for loop J jo window size kitne honge ek type ka. 
4. eK for loop k jo help karega ki ek window mai kitne element honge, unko access karne ke liye use karega.

Code Implementaion:-
```
// Function to find maximmum of minimum of every window size
vector<int> maxOfMin(int arr[], int n)
{
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int num = INT_MAX;
            for (int k = j; k < j + i + 1; k++)
            {
                num = min(num, arr[k]);
            }
            ans[i] = max(ans[i], num);
        }
    }
    return ans;
}
```

Time Complexity = O(ncube)

We need to optimized our approch becuse the requirement of the question is O(n).

### Optimized Approch :- 
Agar uppar wali approch ko hum col wise solve kare then iska O(nsq) mai ho sakta hai . 

Aur optimized karne ke liye. Agar mai element se puchhu ki tum kis size ke liye minimum ho aur wo hamko bata de , then hamara kaam ho sakta hai. 
Basic Approch :- 
1. Next right smallest
2. Next left smallest 
3. 1-2 karenge toh hamko pata chalega kitne window size tak wo element minimum hai. Agar bol diya ki 3 size tal minimum hai tin tak fill kar sakte hai, agar tino mai karte hai bad mai jo value ko update karna pad sakta hai jo O(nsq) mai chala jata hai, so ham jitne bhi window size ke liye mil raha hai hum us size ke last value mai apna value rakhenge. so on. 
Iske baad last se traversal karenge aur check karenge ki last do index jo bada hai usko update kar do us position par. 
Prodecdure:- 
1. ek vectoe lelo ans naam ka n size ka
2. ek stack lelo st naam ka
3. ek for loop lenge,
   1. Agar stack ke top se chhota element mil jata hai arr of i se aur stack empty hai toh
      1. ek integer index mai stack ke top ko dal do
      2. stack ko pop kardo
      3. Agar stack khai hai
           1. int range mai i daal do 
           2. ans of range-1 mai dal do max()
      4. range  mai i - stack ka top -1
      5. ans of range-1 mai max()
   2. Stack mai push kar agar uppar wlai condition fulfilled nahi hai
   3. Agar abhi bhi stack khali nahi hai toh,
     1. index mai stack ke top ko dal do
     2. stack ko pop kardo
     3. Agar stack empty hai toh
        1. range mai n daal do.
        2. ans of range-1 mai max  (ans of range-1 , arr of i) isme jo bada hai usko dal do
     4. range = n(next smallest right) - stack ka top(next smallest left)
     5. ans ko update kar do
4. Last mai traversing kar rahe hai 
    jo bada hai usko daal do ans of i mai

O(n) + O(n) + O(n) = O(n) Time Complexity. 
Code Implementation :- 
```
```
