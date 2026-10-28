#include <iostream>
#include <stack>
#include <climits>
using namespace std;

int canRepresentBST(int arr[], int N)
{
    stack<int> lower, upper;
    lower.push(INT_MIN);
    upper.push(INT_MAX);
    int left, right;

    for (int i = 0; i < N; i++)
    {
        // 1St Condition :-
        if (arr[i] < lower.top()) // range se bahar hai, lower se bhi chhota
            return 0;

        // 2nd Condition :- upper se bahar ho sakta hai
        while (arr[i] > upper.top())
        {
            upper.pop();
            lower.pop();
        }
        // When the value is in range
        left = lower.top();
        right = upper.top();
        lower.pop();
        upper.pop();
        // Stack ke ander right side wale liye lower and upper bound
        lower.push(arr[i]);
        upper.push(right);
        // Stack ke ander left side wale liye lower and upper bound
        lower.push(left);
        upper.push(arr[i]);
    }
}

int main()
{
    // Case 1: Valid Preorder
    int arr1[] = {40, 30, 35, 80, 100};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    if (canRepresentBST(arr1, n1))
        cout << "Array 1: Valid BST representation" << endl;
    else
        cout << "Array 1: Not a BST" << endl;

    // Case 2: Invalid Preorder (45, 80 ke baad nahi aa sakta agar root 40 hai)
    int arr2[] = {40, 30, 35, 20, 80, 100};
    // Isme 20, 35 ke baad aa raha hai (Right child ke subtree mein), jo galat hai
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    if (canRepresentBST(arr2, n2))
        cout << "Array 2: Valid BST representation" << endl;
    else
        cout << "Array 2: Not a BST" << endl;

    return 0;
}
