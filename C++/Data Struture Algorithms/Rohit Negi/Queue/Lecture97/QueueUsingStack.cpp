#include <iostream>
#include <stack>
using namespace std;

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

int main()
{
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.peek() << endl; // 10

    cout << q.pop() << endl; // 10
    cout << q.pop() << endl; // 20

    q.push(40);

    cout << q.peek() << endl; // 30
    cout << q.pop() << endl;  // 30
    cout << q.pop() << endl;  // 40

    cout << q.Empty() << endl; // 1 (true)

    return 0;
}