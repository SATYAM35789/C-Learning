#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> makeBeautiful(vector<int> arr)
{
    stack<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        // Stack Can be element
        if (s.empty())
            s.push(arr[i]);
        // non negative number in arr
        else if (arr[i] >= 0)
        {
            // Element present is stack is non negative
            if (s.top() >= 0)
                s.push(arr[i]);
            // Element present is stack is  negative
            else
                s.pop();
        }
        // negative number in arr
        else
        {
            // Element present is stack is  negative
            if (s.top() < 0)
                s.push(arr[i]);
            // Element present is stack is non negative
            else
                s.pop();
        }
    }

    vector<int> ans(s.size());
    int i = s.size() - 1;
    while (!s.empty())
    {
        ans[i] = s.top();
        i--;
        s.pop();
    }

    return ans;
}

int main()
{
    //  Input array
    vector<int> arr = {4, -2, -2, 3, -1, 2};

    cout << "Original Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    //  Function call
    vector<int> result = makeBeautiful(arr);

    cout << "Beautiful Array: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}