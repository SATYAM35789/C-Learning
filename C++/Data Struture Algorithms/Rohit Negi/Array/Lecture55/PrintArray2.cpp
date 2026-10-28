// Pichhe wali index pahle pass kar rahe hai.
#include <iostream>
using namespace std;

void print(int arr[], int index)
{
    // Base Case
    if (index == -1)
        return;
    print(arr, index + 1); // 3,4,1,2,8
    cout << arr[index] << " ";
    // print(arr, index + 1);  // 8,2,1,4,3
}

int main()
{
    int arr[] = {3, 4, 1, 2, 8};
    print(arr, 0);
}