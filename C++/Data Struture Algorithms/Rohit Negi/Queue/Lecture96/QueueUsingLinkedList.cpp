#include <iostream>
using namespace std;

// Queue using linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
    Node *front, *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Queue is empty or not
    bool IsEmpty()
    {
        return front == NULL;
    }

    // Push element into the queue
    void push(int x)
    {
        // Empty
        if (IsEmpty())
        {
            front = rear = new Node(x);
            return;
        }
        // Empty na ho
        else
        {
            rear->next = new Node(x);
            rear = rear->next;
        }
    }

    void pop()
    {
        if (IsEmpty())
        {
            cout << " Queue underflow\n";
            return;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    int start()
    {
        if (IsEmpty)
        {
            cout << " Queuue is empty";
            return -1;
        }
        else
            return front->data;
    }
};

int main()
{
    Queue q;
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