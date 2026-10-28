#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Insert At Bottom :-
stack<int> insertAtBottom(stack<int> st, int x)
{
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }

    st.push(x);

    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    return st;
}

int main()
{
    stack<int> st;

    //  Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Original Stack (Top to Bottom): ";
    stack<int> temp1 = st;
    while (!temp1.empty())
    {
        cout << temp1.top() << " ";
        temp1.pop();
    }
    cout << endl;

    //  Insert at bottom
    st = insertAtBottom(st, 5);

    cout << "After Inserting at Bottom: ";
    stack<int> temp2 = st;
    while (!temp2.empty())
    {
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout << endl;

    return 0;
}