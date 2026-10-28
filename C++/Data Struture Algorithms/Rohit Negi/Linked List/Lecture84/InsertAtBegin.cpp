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

Node *insertAtBeginning(Node *head, int value)
{
    Node *newNode = new Node(value);

    // Case 1: Empty list
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = head;

    // Last node find
    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;

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

#include <iostream>
using namespace std;

int main()
{
    Node *head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    display(head);

    return 0;
}