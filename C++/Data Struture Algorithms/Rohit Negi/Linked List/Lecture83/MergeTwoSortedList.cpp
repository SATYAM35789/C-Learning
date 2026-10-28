#include <iostream>
#include <vector>
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

Node *sortMerge(Node *head1, Node *head2)
{
    Node *head = new Node(0);
    Node *tail = head;

    while (head1 && head2)
    {
        if (head->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;
        }
        else
        {
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    if (head1)
        tail->next = head1;
    else
        tail->next = head2;

    // Removing extra node
    tail = head;
    head = head->next;
    delete tail;

    return head;
}

int main()
{
    Node *head = NULL, *tail = NULL;
    //  Create doubly linked list
    int arr[] = {};
}