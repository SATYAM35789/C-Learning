#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> p; // Max heap wali
    p.push(10);
    p.push(50);
    p.push(13);
    p.push(180);

    cout << " Printing top of element\n";
    cout << p.top() << " ";

    // Deleting the element
    p.pop();
    cout << p.top() << " ";

    // Size
    cout << p.size() << " ";

    // Traversing
    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
}