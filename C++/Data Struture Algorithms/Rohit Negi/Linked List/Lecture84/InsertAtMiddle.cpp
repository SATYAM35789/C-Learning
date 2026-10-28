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

Node *insertAtPosition(Node *head, int value, int pos)
{
    Node *newNode = new Node(value);

    // 🔹 Case 1: Empty list
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    // 🔹 Case 2: Insert at Beginning
    if (pos == 1)
    {
        Node *last = head;

        // last node find
        while (last->next != head)
        {
            last = last->next;
        }

        newNode->next = head;
        last->next = newNode;
        head = newNode;

        return head;
    }

    // 🔹 Case 3: Insert at Position (middle/end)
    Node *temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

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

    head = insertAtPosition(head, 10, 1);
    head = insertAtPosition(head, 20, 2);
    head = insertAtPosition(head, 30, 3);

    display(head);

    return 0;
}