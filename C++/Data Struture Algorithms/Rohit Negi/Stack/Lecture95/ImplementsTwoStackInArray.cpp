#include <iostream>
#include <stack>
using namespace std;

class twoStack
{
public:
    int *arr;
    int top1, top2, size;

    twoStack(int n)
    {
        arr = new int[n];
        top1 = -1;
        top2 = n;
        size = n;
    }

    // Function to push an integer into the stack1
    void push1(int x)
    {
        // stack bara toh nahi hai
        if (top1 + 1 == top2)
            return;

        top1++;
        arr[top1] = x;
    }

    void push2(int x)
    {
        // stack bara toh nahi hai
        if (top2 - 1 == top1)
            return;

        top2--;
        arr[top2] = x;
    }
    // Function to remove an element from top of the stack1
    int pop1()
    {
        // Kahi stack khali nahi hai
        if (top1 == -1)
            return -1;

        int element = arr[top1];
        top1--;
        return element;
    }

    // Function to remove an element from top of the stack1
    int pop2()
    {
        // Kahi stack khali nahi hai
        if (top2 == size)
            return -1;

        int element = arr[top2];
        top2++;
        return element;
    }
};

int main()
{
    twoStack st(5);

    st.push1(10);
    st.push1(20);
    st.push2(30);
    st.push2(40);

    cout << st.pop1() << endl; // 20
    cout << st.pop2() << endl; // 40

    st.push1(50);
    st.push2(60);

    cout << st.pop1() << endl; // 50
    cout << st.pop2() << endl; // 60

    return 0;
}