#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class MyStack
{
    queue<int> q1;
    queue<int> q2;
    MyStack() {}

    bool Empty()
    {
        return q1.empty() && q2.empty();
    }
    void push(int x)
    {
        if (Empty())
            q1.push(x);
        // Jis queue mai element hoga usme  push hoga
        else if (q1.empty())
            q2.push(x);
        else
            q1.push(x);
    }

    int pop()
    {
        if (Empty())
            return 0;
        else if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int element = q2.front();
            q2.pop();
            return element;
        }
        else
        {
            while (q2.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int element = q1.front();
            q1.pop();
            return element;
        }
    }
    int top()
    {
        if (Empty())
            return 0;
        else if (q1.empty())
            return q2.back();
        else
            return q1.back();
    }
};