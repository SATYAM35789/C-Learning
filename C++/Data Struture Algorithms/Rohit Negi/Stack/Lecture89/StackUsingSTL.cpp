#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(76);
    s.push(56);
    s.push(63);
    s.push(62);
    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
}