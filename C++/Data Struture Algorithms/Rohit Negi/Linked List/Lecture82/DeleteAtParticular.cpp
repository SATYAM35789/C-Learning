#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

Node *CreateDLL(int arr[], int index, int size, Node *back)
{
    if (index == size)
        return NULL;

    //  Creating Node
    Node *temp = new Node(arr[index]);
    temp->prev = back;
    temp->next = CreateDLL(arr, index + 1, size, temp);
    return temp;
}

int main()
{
    Node *head = NULL, *tail = NULL;
    //  Create doubly linked list
    int arr[] = {1, 2, 3, 4, 5};

    head = CreateDLL(arr, 0, 5, NULL);

    //   Delete at given postion
    int pos = 3;

    // Delete at start
    if (pos == 1)
    {
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        //    If more than 1 node exist
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            head->prev = NULL;
        }
    }
    else
    {
        Node *curr = head;
        while (--pos)
            curr = curr->next;
        // Delete at end
        if (curr->next == NULL)
        {
            curr->prev->next = NULL;
            delete curr;
        }
        // delete at middle
        else
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }

    // Print the value of Doubly linked list
    Node *trav = head;
    while (trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}