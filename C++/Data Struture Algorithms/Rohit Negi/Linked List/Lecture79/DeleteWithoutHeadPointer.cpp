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

//     Delete Node without head or jisko point kar raha usko delete kardo not given head pointer
void deleteNode(Node *curr)
{
    Node *temp = curr->next;
    curr->data = temp->data;
    curr->next = temp->next;
    delete temp;
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