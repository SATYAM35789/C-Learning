#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//  “I used encoding technique assuming bounded values”
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
int main()
{
    Solution s;

    //  Push elements (within range 0–100)
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);
    s.push(6);

    cout << "Current Min: " << s.getMin() << endl; // 2

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
