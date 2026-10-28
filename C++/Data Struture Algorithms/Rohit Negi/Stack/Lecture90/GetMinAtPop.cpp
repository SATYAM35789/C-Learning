#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to push the elment in the stack
stack<int> push(int arr[], int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            st.push(arr[i]);
        else
            st.push(min(arr[i], st.top()));
    }
    return st;
}

// Fun to print the minimum value  while poping
void getMinAtPop(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    //  Input array
    int arr[] = {5, 3, 7, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    //  Push elements into stack
    stack<int> st = push(arr, n);

    //  Print minimum at each pop
    cout << "Minimum at each pop: ";
    getMinAtPop(st);

    return 0;
}