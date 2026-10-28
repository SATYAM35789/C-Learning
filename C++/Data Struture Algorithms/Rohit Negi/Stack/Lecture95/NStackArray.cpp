#include <iostream>
#include <stack>
class Node
{
public:
    int index;
    Node *next;

    Node(int x)
    {
        index = x;
        next = NULL;
    }
};

class NStack
{
public:
    // Initialize data structre
    stack<int> st; // Empty index kon kon se hai
    int *arr;      // Original array jaha data store hoga
    Node **Top;    // Top element's of particular stack ko store kar raha hai

    NStack(int N, int S)
    {
        arr = new int[S];
        Top = new Node *[N];
        for (int i = 0; i < N; i++)
            Top[i] = NULL;
        for (int i = 0; i < S; i++)
            st.push(i);
    }

    // Pushes x into the M stack.
    bool push(int x, int m)
    {
        if (st.empty())
            return 0;

        arr[st.top()] = x;
        Node *temp = new Node(st.top());
        temp->next = Top[m - 1];
        Top[m - 1] = temp;
        st.pop();
        return 1;
    }
    // Pops top element from thr mth stack
    int pop(int m)
    {
        if (Top[m - 1] == NULL)
            return -1;

        int element = arr[Top[m - 1]->index];
        st.push(Top[m - 1]->index);
        Top[m - 1] = Top[m - 1]->next;
        return element;
    }
};

int main()
{
    NStack st(3, 6); // 3 stacks, total size = 6

    // Push elements
    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 2);
    st.push(40, 3);
    st.push(50, 2);

    // Pop elements
    cout << st.pop(1) << endl; // 20
    cout << st.pop(2) << endl; // 50
    cout << st.pop(3) << endl; // 40

    // More operations
    st.push(60, 3);

    cout << st.pop(3) << endl; // 60

    return 0;
}