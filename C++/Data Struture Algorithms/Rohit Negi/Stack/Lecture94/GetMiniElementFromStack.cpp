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
int main()
{
    Solution s;

    //  Push elements
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);
    s.push(6);

    cout << "Current Min: " << s.getMin() << endl; // 2

    //  Pop elements
    cout << "Popped: " << s.pop() << endl;         // 6
    cout << "Current Min: " << s.getMin() << endl; // 2

    cout << "Popped: " << s.pop() << endl;         // 2
    cout << "Current Min: " << s.getMin() << endl; // 3

    cout << "Popped: " << s.pop() << endl;         // 7
    cout << "Current Min: " << s.getMin() << endl; // 3

    cout << "Popped: " << s.pop() << endl;         // 3
    cout << "Current Min: " << s.getMin() << endl; // 5

    return 0;
}