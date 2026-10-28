#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int value)
    {
        data = value;
        next = NULL;
        bottom = NULL;
    }
};
// Merge Function
Node *merge(Node *head1, Node *head2)
{
    // Creating dummy node
    Node *head = new Node(0);
    Node *tail = head;

    // Doing Compairsion , to insert in linked list, jab tak ye dono exist kare
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            tail->bottom = head1;
            head1 = head1->bottom;
            tail = tail->bottom;
            tail->bottom = NULL;
        }

        else
        {
            tail->bottom = head2;
            head2 = head2->bottom;
            tail = tail->bottom;
            tail->bottom = NULL;
        }
    }
    if (head1)
        tail->bottom = head1;
    else
        tail->bottom = head2;

    return head->bottom;
}

// Function which return the rrot of the flattered linked list
Node *flatter(Node *root)
{
    Node *head1, *head2, *head3;

    while (root->next)
    {
        head1 = root;
        head2 = root->next;
        head3 = root->next->next;

        // Breaking the connection
        head1->next = NULL;
        head2->next = NULL;

        root = merge(head1, head2);
        root->next = head3;
    }

    return root;
}

int main()
{
    //  Creating main list
    Node *head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    Node *head2 = new Node(10);
    head2->bottom = new Node(20);

    Node *head3 = new Node(19);
    head3->bottom = new Node(22);
    head3->bottom->bottom = new Node(50);

    Node *head4 = new Node(28);
    head4->bottom = new Node(35);
    head4->bottom->bottom = new Node(40);
    head4->bottom->bottom->bottom = new Node(45);

    //  Linking main list using next
    head->next = head2;
    head2->next = head3;
    head3->next = head4;

    //  Flatten the list
    Node *result = flatter(head);

    //  Display flattened list (using bottom)
    cout << "Flattened List: ";
    Node *temp = result;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }

    return 0;
}
