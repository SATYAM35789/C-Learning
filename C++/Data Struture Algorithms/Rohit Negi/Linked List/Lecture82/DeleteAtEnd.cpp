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

    //  Delete at End
    if (head != NULL)
    {
        // If only one node exist
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        //  More than 1 Node exist
        else
        {
            Node *curr = head;
            //  Last node par jao
            while (curr->next)
            {
                curr = curr->next;
            }
            curr->prev->next = NULL;
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