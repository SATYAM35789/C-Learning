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

int main()
{
    Node *head = NULL;
    //  Insert at start
    //  Linked Doesnot exist
    if (head == NULL)
    {
        head = new Node(5);
    }

    //  Linked List Exist
    else
    {
        Node *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        Node *temp = new Node(10);
        curr->next = temp;
        temp->prev = curr;
    }

    // Print the value of Doubly linked list
    Node *trav = head;
    while (trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}