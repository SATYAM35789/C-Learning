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
    //   Insert at any given postion
    int pos = 2;

    //  insert at start
    if (pos == 0)
    {
        //  Linked list exist na kare
        if (head == NULL)
        {
            head = new Node(5);
        }
        //  Linked list exist
        else
        {
            Node *temp = new Node(5);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    else
    {
        Node *curr = head;
        // Go to the node after which i have to insert
        while (--pos)
        {
            curr = curr->next;
        }
        // insert at end
        if (curr->next == NULL) // Last Node
        {
            Node *temp = new Node(5);
            temp->prev = curr;
            curr->next = temp;
        }
        //  insert at middle
        else
        {
            Node *temp = new Node(5);
            temp->next = curr->next;
            temp->prev = curr;
            curr->next = temp;
            temp->next->prev = temp;
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