#include <iostream>
using namespace std;

// process of compairing parent with child, to build max  heap
void maxHeapify(int arr[], int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
        ;
    largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        maxHeapify(arr, largest, n);
    }
}

void minHeapify(int arr[], int index, int n)
{
    int smaller = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] < arr[smaller])
        ;
    smaller = left;
    if (right < n && arr[right] < arr[smaller])
        smaller = right;

    if (smaller != index)
    {
        swap(arr[smaller], arr[index]);
        minHeapify(arr, smaller, n);
    }
}

void BuildHeap(int arr[], int n)
{
    // Step down
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, i, n);
        minHeapify(arr, i, n);
    }
}

void printHeap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    int arr[] = {10, 3, 8, 6, 4, 13, 15, 12, 56, 43};
    BuildHeap(arr, 10);
    printHeap(arr, 10);
}
