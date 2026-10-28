#include<iostream>
using namespace std;

class MinHeap {
    int *arr;
    int size; 
    int total_size;

public:
    MinHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // Insert in Min Heap
    void insert(int value) {
        if (size == total_size) {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        // Up-Heapify: Agar naya element parent se CHHOTA hai, toh swap karo
        while (index > 0 && arr[(index - 1) / 2] > arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        cout << value << " inserted into the min heap\n";
    }

    // Down-Heapify for Min Heap
    void Heapify(int index) {
        int smallest = index; // Max heap mein 'largest' tha
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Teeno mein se sabse CHHOTA dhoondo
        if (left < size && arr[left] < arr[smallest])
            smallest = left;
        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            Heapify(smallest);
        }
    }

    // Delete Minimum (Root)
    void Delete() {
        if (size == 0) {
            cout << "Heap Underflow\n";
            return;
        }

        cout << arr[0] << " (Min) deleted from the heap\n";
        arr[0] = arr[size - 1];
        size--;

        if (size > 0)
            Heapify(0);
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap H1(10);

    H1.insert(40);
    H1.insert(20);
    H1.insert(10);
    H1.insert(5);

    cout << "Current Min Heap: ";
    H1.print();

    H1.Delete();
    cout << "Heap after deleting min: ";
    H1.print();

    H1.insert(2);
    cout << "After inserting 2: ";
    H1.print();

    return 0;
}