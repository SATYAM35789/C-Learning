### Print all element in queue :- 
Approch :- Ham apne queue ke front element ko access kar sakete, so print karwate jaye aur pop karte jaye.
Approch :- We have a condition that we donot want to delete the element want to just print it aur hamara data queue mai pada rahe so iske liye ham ek array le sakte pahle element ko access karo -> array mai store karo aur print kardo, phir queue se pop kardo and so on until queue is empty. And phir array mai queue mai wapas load karwa do. 
Code Part :- 
1. ek vector bana lo, ans naam ka. 
2. Agar kyu hamara empty nahi tab tak,
  1. q ke front ko print karwate raho. 
  2. vactor ke ans mai q.front ko push_back kardo.
  3. q.pop() : aage se ek element delete kardo. 
3. Ek for loop chalo ans.size tak, tabtak
   1. queue mai ans[i] j=ko push karte rahe. 

Here we use extra space. We have to solve it in O(1). So how are we going to solve the it?
Approch:- Apne pahle element ko print karo, aur usko piche mai daal diya or push kar diya aur queue ka size ko decrese kar diya taki hamko pata chal jaye ki kab tak ye process karni hai. 
Code part :- 
1. n mai q.size daal diya taki hamko pata rahe ki itna element print karwana hai. 
2. ab jab tak n 0 ke barabar nahi hota tabtak,
   1. print the q.front element.
   2. queue mai push kardo, queue ke front ko
   3. queue ko pop kardo. 
Code Implementation:-
```
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    queue<int> q;
    q.push(5);
    q.push(25);
    q.push(45);
    q.push(75);
    q.push(56);

    int n = q.size();
    while(n--)
    {
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }

    // Checking that value is present in the queue or not
    q.size();
}
```

### Queue Reverse :- 
Approch :- Queue ke sare element ko , ek array mai store karo , phir us aaray ko pichhse traverse karte hue queue mai push kardo. 
Note:- Stack Automatically reverse the element. Agar koi array iske ander dalte hai, phir stack wapas nikalte hai, tab ab array hamko reverse order mai milegi. 
Code part:-
1. ek stack create karenge st naam ka
2. Ab jab tak queue khalo nahi ho jata, tabtak
   1. stack mai push kardo queue ke fron ko
   2. queue ke front ko pop kar do
3. Ab jab stack khali nahi ho jata tabtak,
  1. queue mai push kardo stack ke top ko
  2. stack ko pop kardo

Time and space complexity :- O(n)
Code Implementation:-
```
queue<int> rev(queue<int> q)
{
    stack<int> st;

    // Empty the queue
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    // stack ko khali karo, array ko reverse kardo
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    return q;
}
``` 

### Reverse the first k element in element :- 
Approch :- 
1. Push first k element of queue in stack.
2. Store the size of queue.
3. Push all elements of stack in queue.
4. push n element of queue at last. 

Code Part :- 
1. ek stack banalo, st naam ka
2. Ab jabtak k barabar nahi hota 0 tab tak,
   1. stack mai queue ke front ko push kardo
   2. queue ke first element ko pop kardo.
3. Store the size of the queue,
4. Ab jab tak stack empty nahi ho jata,
   1. queue mai push kardo stack ke top ko. 
   2. stack ko pop kardo
5. Ab jan n barabar nahi ho jata 0 ke tabtak,
   1. queue mai queue ka front daal 
   2. queue ke first element ko pop kardo. 

Code Implementation :- 
```
queue<int> moodifyQueue(queue<int> q, int k)
{
    stack <int> st;
    for(int i=0;i < k;i++)
    {
        st.push(q.front());
        q.pop();
    }

    int n =  q.size();
    // Ab stack ke element ko Queue mai daal do
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // Pahle ke element ko , phir se pichhe daalo do
    while(n--)
    {
        q.push(q.front());
        q.pop();
    }
     return q;
}
```

### Time needed to buy Tickets :- 
Ek baar mai ek he ticket kharid sakte hai, aur jab tak ticket mil nahi jata pichhe jakar lagta rahega. 
Approch :- 
1. push all the in the queue. 
2. Time = 0
3. Bahara nikalo ticket dede
   1. Time ko ek  se increse kardo
   2. ticket ek se decrement kardo
4. Time k a requirement nahi hai
    return time
5. Time ka requirement hai,
   stack ke pichhe daal do. 

Code part :- 
1. Ek queue bana lo q naam ka
2. ek for loop jo n tak chalege,
3. q.push kardo index ko daal do
4. Ab agar tickets ki value barabar nahi 0 ke tab
  1. Ticket mai queue ke front ko ek se decrement kardo
  2. Agar Ticket ka front exist karta hai
     1. queue mai push kardo queue ke front ko
  3. queue ko pop kardo aage se 
  4. time ko ek se increment kardo
5. retuen kardo time ko. 

Code Implementation:-
```
int timeRequiredToBuy(vector<int> &tickets, int k)
{
    queue<int> q;
    int n = tickets.size();

    for (int i = 0; i < n; i++)
        q.push(i);

    int Time = 0;

    while (tickets[k] != 0)
    {
        int idx = q.front();
        q.pop();

        tickets[idx]--;
        Time++;

        if (tickets[idx] > 0)
            q.push(idx);
    }

    return Time;
}
```

### Optimized Approch:- 
Agar jitne bhi elemrnt hai array mai sabki same no. of tickests chahiye, is case mai time complexity O(nsq)
tak chali jayegi, So we need Optimized our answer. 
K ke aage wale maxmum k tak chalenge aur k ke pichh jo honge wo maximum k-1 time he chalege.
For both this condition we have 
Time += min(ticket[k], ticket[i])  for k ke agge wale element
Time += min(ticket[k-1], ticket[n])  for the ke pichhe wale element.

Code Implementation :- 
```
int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int time = 0;

    for(int i = 0; i < tickets.size(); i++)
    {
        if(i <= k)
            time += min(tickets[i], tickets[k]);
        else
            time += min(tickets[i], tickets[k] - 1);
    }

    return time;
}
```

### Implement queue using Stack :- 
Queue ko implement karna hai stack ke help se with having push pop peek empty operation. 
So toh pahle ham queue ke element ko stack1 mai store kar lange phir stack1 se stack2 mai store kar lenge ab hamare pass same order mai value honge jis order mai que mai hai. Ab agar hamko pop operation karna hai
Queue mai se delete kardo , aur stack2 mai pop kar denge and push karne ke liye ham Queue ka use karenge. 

Note:- pop operation karne ke liye stack1 se stack2 mai data dalte rahna. 

Stack1 = push and stack2 = pop.
Empty Condition:- jab dono stack khali honge tab ham kah sakte hai Queue empty hai. 
Pop() :- Agar stack2 khali nahi hai toh ek element banao usme satch2 ka top daal do than pop kardo phir element ko return kar do, Agra stack1 khali na ho tab stack1 ke value stack2 mai dal do. 

Code Implementation :- 
```
class MyQueue
{
public:
    stack<int> s1; // Push
    stack<int> s2; // pop
    MyQueue()
    {
    }

    bool Empty()
    {
        return s1.empty() && s2.empty();
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (Empty())
            return 0;
        else if (!s2.empty())
        {
            int element = s2.top();
            s2.pop();
            return element;
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int element = s2.top();
            s2.pop();
            return element;
        }
    }

    int peek()
    {
        if (Empty())
            return 0;
        else if (!s2.empty())
            return s2.top();
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
};
```

### Implement stack using Queue :- 
Now implement stack using queue and  implement the following operations like empty , push, pop and  top.
Take two queue Queue1 and Queue2 :- 
Pop():- Pop karne ke liye un sabko dusre queue mai bhejna padega , jo barabar nahai stack ke top se or kya ye last element jai queue ka. aur jaha sare element present honge. 
Push():- Jaha element honge waha push karwa denge (queue2). Agar empty hai hai toh kisi bhi queue mai value dal sakte hai. Agar empty nahi hai , agar queue1 khali ha queue2 mai value daal do other wise vice versa. 

Code Implementation:- 
```

```

