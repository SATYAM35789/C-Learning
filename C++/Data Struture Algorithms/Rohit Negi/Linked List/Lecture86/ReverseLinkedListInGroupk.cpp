#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
// Reverse a linked list
Node *Reverse(Node *curr, Node *prev)
{
    if (curr == NULL)
        return prev;

    Node *front = curr->next;
    curr->next = prev;
    return Reverse(front, curr);
}

// Reverse the given linked list in group of k order
Node *reverselt(Node *head, int k)
{
    // Creating Dummy Node
    Node *first = new Node(0);
    first->next = head;
    head = first;

    // Reverse in Group of 4
    int x;
    Node *second, *prev, *curr, *front;
    while (first->next)
    {
        x = k;
        second = first->next;
        prev = first;
        curr = first->next;

        // Jab tak x aur curr exist karta , reversing the Node
        while (x && curr)
        {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
            x--;
        }
        // Connecting the Node After reverse in k or x order
        first->next = prev;
        second->next = curr;
        first = second;
    }
    //  Dummy node delete
    first = head;
    head = head->next;
    delete first;

    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    //  Create Linked List: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    cout << "Original List: ";
    display(head);

    int k = 3;

    //  Reverse in groups of k
    head = reverselt(head, k);

    cout << "After Reversing in groups of " << k << ": ";
    display(head);

    return 0;
}