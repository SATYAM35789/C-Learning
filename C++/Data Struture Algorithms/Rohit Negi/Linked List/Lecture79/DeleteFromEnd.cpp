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

int main()
{
    Node *Head, *Tail;
    Tail = Head = NULL;

    //  Insert the node at End

    int arr[] = {2, 4, 6, 8, 10};
    Head = CreateLinkedList(arr, 0, 5);

    // Delete a node at end
    if (Head != NULL)
    {
        //   Only one node is present
        if (Head->next == NULL)
        {
            Node *temp = Head;
            delete temp;
            Head = NULL;
        }
        //  More than one node is present
        else
        {
            Node *curr = Head;
            Node *prev = NULL;

            // curr->next is not null
            while (curr->next == NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            delete curr;
        }
    }

    //  Traversing the linked list to verify
    Node *temp;
    temp = Head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}