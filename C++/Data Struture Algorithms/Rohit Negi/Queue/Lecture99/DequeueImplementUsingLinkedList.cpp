#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class Dequeue
{
    Node *front, *rear;

public:
    Dequeue()
    {
        front = rear = NULL;
    }

    // Push front
    void push_front(int x)
    {
        // Empty
        if (front == NULL)
        {
            front = rear = new Node(x);
            cout << "Pushed" << x << " in front of deque\n";
            return;
        }
        else
        {
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
            cout << "Pushed" << x << " in front of deque\n";
            return;
        }
    }

    // push back

    void push_back(int x)
    {
        // Empty
        if (front == NULL)
        {
            front = rear = new Node(x);
            cout << "Pushed" << x << " in back of deque\n";
            return;
        }
        else
        {
            Node *temp = new Node(x);
            temp->next = front;
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout << "Pushed" << x << " in back of deque\n";
            return;
        }
    }

    // Pop front
    void pop_front()
    {
        // Empty
        if (front == NULL)
        {
            cout << " Dequeue Underflow";
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            // greater than 1 node
            if (front)
                front->prev = NULL;
            //  1 node
            else
                rear = NULL;
        }
    }
    // pop back
    void pop_back()
    {
        // Empty
        if (front == NULL)
        {
            cout << " Dequeue Underflow";
        }
        else
        {
            Node *temp = rear;
            rear = rear->prev;
            delete temp;
            // greater than 1 node
            if (rear)
                rear->next = NULL;
            //  1 node
            else
                front = NULL;
        }
    }
    // start
    int start()
    {
        if (front == NULL)
            return -1;
        else
            return front->data;
    }
    // end
    int end()
    {
        if (front == NULL)
            return -1;
        else
            return rear->data;
    }
};

int main()
{
    Dequeue d;
    d.push_back(5);
    d.pop_front();
    cout << d.start() << endl;
}