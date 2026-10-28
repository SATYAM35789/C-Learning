#include <iostream>
using namespace std;

// Implement queue using Array
class Queue
{
    int *arr;
    int front, rear, size;

public:
    Queue(int n)
    {
        arr = new int(n);
        size = n;
        front = rear = -1;
    }

    // Queue is empty or not
    bool IsEmpty()
    {
        return front == -1;
    }

    // Queue is Full or not
    bool IsFull()
    {
        return rear == size - 1;
    }

    // Push element into the queue, end
    void push(int x)
    {
        // Empty
        if (IsEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // Full
        else if (IsFull())
        {
            cout << "Queue is overflow\n";
            return;
        }
        // Insert
        else
        {
            rear = rear + 1;
            arr[rear] = x;
        }
    }

    // Pop element, starting
    void pop()
    {
        // Empty
        if (IsEmpty())
        {
            cout << "Queue UnderFlow\n";
            return;
        }
        // If not empty, than pop the element
        else
        {
            if (front == rear)
                front = rear = -1;
            else
                front = front + 1;
        }
    }

    // Starting mai konsa element rakha hua hai
    int start()
    {
        if (IsEmpty())
        {
            cout << " Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    Queue q(5);
    q.push(7);
    q.push(27);
    q.push(73);
    q.push(37);
    q.push(47);
    q.pop();
    int x = q.start();
    if (!q.IsEmpty())
        cout << x << " ";
}
