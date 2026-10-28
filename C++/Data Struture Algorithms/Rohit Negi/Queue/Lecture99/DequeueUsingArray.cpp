#include <iostream>
using namespace std;

class Dequeue
{
    int front, rear, size;
    int *arr;

public:
    Dequeue(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool IsEmpty()
    {
        return front == -1;
    }
    bool IsFull()
    {
        return (rear + 1) % size == front;
    }

    void push_front(int x)
    {
        // empty
        if (IsEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // full
        else if (IsFull())
        {
            return;
        }
        // Normal
        else
        {
            front = (front - 1 + size) % size;
            arr[front] = x;
            return;
        }
    }
    // Push Back
    void push_back(int x)
    {
        // empty
        if (IsEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // full
        else if (IsFull())
        {
            return;
        }
        // Normal
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
            return;
        }
    }

    void pop_back()
    {
        // empty
        if (IsEmpty)
        return;
        else
        {
            // Single element
            if (front == rear)
                front = rear = -1;
            //  greater than 1 element
            else
                rear = (rear-1+size) % size; // ek kadam pichhe
        }
    }

    int start()
    {
        if(IsEmpty())
        {
            return -1;
        }
        else arr[front] ; 
    }

    int End()
    {
        if(IsEmpty())
        {
            return -1;
        }
        else arr[rear]; 
    }
};

int main()
{
    Dequeue d(5);
    d.push_back(8);
    d.push_back(8);
    d.push_front(45);
    d.push_front(45);
    d.start();
    d.End();

}