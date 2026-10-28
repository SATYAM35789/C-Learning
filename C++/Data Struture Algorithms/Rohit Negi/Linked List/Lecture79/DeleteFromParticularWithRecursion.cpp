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

Node *CreateLinkedList(int arr[], int index, int size)
{
    //  Base case
    if (index == size)
        return NULL;

    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index + 1, size);

    return temp;
}

//     Delete a particular node with Recursion
Node *deleteNode(Node *curr, int x)
{
    if (x == 1)
    {
        Node *temp = curr->next;
        delete curr;
        return temp;
    }
    curr->next = deleteNode(curr->next, x - 1);
    return curr;
}

int main()
{
    Node *Head, *Tail;
    Tail = Head = NULL;

    //  Insert the node at End

    int arr[] = {2, 4, 6, 8, 10};
    Head = CreateLinkedList(arr, 0, 5);

    //  Traversing the linked list to verify
    Node *temp;
    temp = Head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}