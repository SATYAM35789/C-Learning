#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
Node *insertAtEnd(Node *head, int value)
{
    Node *newNode = new Node(value);

    // Empty list
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

void display(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    Node *head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    display(head);

    return 0;
}