#include <iostream>
using namespace std;

int main()
{
    int arr[] = {23, 43, 22, 5, 45, 66};

    for (int i = 0; i < 5; i++) // No. of round
    {
        int index = i;
        for (int j = i + 1; j < 6; j++)
        {
            if (arr[j] < arr[index])
                index = j;
        }
        swap(arr[i], arr[index]);
    }

    // Print the element to verify the answer
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}