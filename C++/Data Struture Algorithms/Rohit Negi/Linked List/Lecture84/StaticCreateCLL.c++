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
    // Static nodes
    Node n1, n2, n3;

    // Assign data
    n1.data = 10;
    n2.data = 20;
    n3.data = 30;

    // Linking circularly
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n1; // circular

    // Traversal
    Node *temp = &n1;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != &n1);

    return 0;
}