#include <iostream>
using namespace std;

void print(int arr[], int index, int n)
{
    // Base Case
    if (index == n)
        return;
    print(arr, index + 1, n); // 8,2,1,4,3
    cout << arr[index] << " ";
    // print(arr, index + 1, n); // 3,4,1,2,8
}

int main()
{
    int arr[] = {3, 4, 1, 2, 8};
    print(arr, 0, 5);
}

// Reverse order mai print karne ke liye you hamko pahle call karna hoga function ko, jo bata raha hoga ki pahle mujse pahle wale ko print kardo
