#include <iostream>
using namespace std;

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

class Stack
{
    Node *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }
    // push
    void push(int value)
    {
        Node *temp = new Node(value);
        if (temp == NULL)
        {
            cout << "Stack is overflow\n";
        }
        temp->next = top;
        cout << "Pushed value" << value << endl;
        top = temp;
        size++;
    }
    // pop
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is underFlow\n";
            return;
        }
        Node *temp = top;
        cout << "popped data" << top->next << endl;
        top = top->next;
        delete temp;
        size--;
    }
    // peek
    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }
    // IsEmpty
    bool IsEmpty()
    {
        return top == NULL; // 0 means khali nahi hai
    }
    // IsSize
    int IsSize()
    {
        return size;
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(67);
    s.push(55);
    s.push(45);
    s.pop();
}