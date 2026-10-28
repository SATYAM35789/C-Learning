#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int main()
{
    Node *head = NULL, *tail = NULL, *temp;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter data: ";
        cin >> value;

        Node *newNode = new Node();
        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else
        {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    // Traversal
    temp = head;
    if (head)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    return 0;
}