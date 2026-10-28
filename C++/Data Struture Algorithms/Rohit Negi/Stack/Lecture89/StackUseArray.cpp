#include <iostream>
using namespace std;

// Implement Stack with Array
class Stack
{

    int *arr;
    int size;
    int top;

public:
    bool flag;
    // Constructor to initialize the value
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[s];
        flag = 1;
    }
    // push
    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack is OverFlow\n";
            return;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << "Pushed value" << value << "into the stack /n";
            flag = 0;
        }
    }

    // pop
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack UnderFlow\n";
        }
        else
        {
            cout << "Popped" << arr[top] << "From the stack\n";
            top--;
            if (top == -1)
                flag = 1;
        }
    }
    // peek
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    // IsEmpty
    bool IsEmpty()
    {
        return top == -1;
    }
    // IsSize
    int IsSize()
    {
        return top + 1;
    }
};

int main()
{
    Stack S(5);
    S.push(5);
    S.push(6);
    S.push(7);
    S.push(8);

    S.pop();
    S.pop();

    cout << S.peek() << endl;
    cout << S.IsSize() << endl;

    int value = S.peek();
    if (S.flag == 0)
        cout << value << endl;
}

// Handling one edge case empty ke case mai -1 aur -1 insert ke case mai bhi -1. We crete flag.