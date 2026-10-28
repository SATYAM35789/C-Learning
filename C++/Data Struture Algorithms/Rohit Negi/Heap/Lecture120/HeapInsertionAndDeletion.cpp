#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;
    int size;       // Total element in heap
    int total_size; // total size of an array

public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // Insert in the heap
    void insert(int value)
    {
        // Checking ki insert kar sakte hai ki nahi
        if (size == total_size)
        {
            cout << "Heap is overflow\n";
            return;
        }
        // Agar size bacha toh insert kar denge.
        else
        {
            arr[size] = value;
            int index = size; // Ki particular index par insertion hua hai.
            size++;

            // Correct position khjna: compair with itsparent
            while (index > 0 && arr[(index - 1) / 2] < arr[index])
            {
                swap(arr[index], arr[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
            cout << arr[index] << " is inserted into the heap \n";
        }
    }

    // Correct position par jo leaf node tumne add kiya tha usko
    void Heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Largest store index of element which is greater b/w parent, right and left.
        if (left < size && arr[left] > arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right; // Iske baad parent,left aur right mai jo bada hai wo largest ke ander aa jayenga.

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }
    }

    // Delete in the heap
    void Delete()
    {
        if (size == 0)
        {
            cout << " Heap Underflow \n";
            return;
        }

        cout << arr[0] << " Deleted from the heap ";
        arr[0] = arr[size - 1]; // Last element ko 1st position par laa rahe hai
        size--;
        if (size == 0)
            return;

        Heapify(0);
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(8);
    H1.insert(84);
    H1.Delete();
    H1.insert(28);
    H1.insert(85);
    H1.insert(86);
    H1.insert(3);
}

// arr[(index-1)/2]<arr[index] : Agar parent(position :arr[(index-1)/2]) chhota hai child(Child position : arr[index]) se