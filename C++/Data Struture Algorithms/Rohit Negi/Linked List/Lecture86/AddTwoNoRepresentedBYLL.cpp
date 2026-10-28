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

// Function to add two numbers reprented by linked list.
Node *addTwoLists(Node *first, Node *second)
{
    first = Reverse(first, NULL);
    second = Reverse(second, NULL);

    Node *curr1 = first, *curr2 = second;
    Node *head = new Node(0);
    Node *tail = head;
    int sum, carry = 0;
    // Addition
    while (curr1 && curr2)
    {
        sum = curr1->data + curr2->data + carry;
        tail->next = new Node(sum % 10);
        curr1 = curr1->next;
        curr2 = curr2->next;
        tail = tail->next;
        carry = sum / 10;
    }
    // Branches jaha se same nahi hai, waha se :-
    while (curr1)
    {
        sum = curr1->data + carry;
        tail->next = new Node(sum % 10);
        curr1 = curr1->next;
        tail = tail->next;
        carry = sum / 10;
    }

    //  curr2 toh exist nahi karta,
    while (curr2)
    {
        sum = curr2->data + carry;
        tail->next = new Node(sum % 10);
        curr2 = curr2->next;
        tail = tail->next;
        carry = sum / 10;
    }

    // Carry toh exist nahi karta
    while (carry)
    {
        tail->next = new Node(carry % 10);
        tail = tail->next;
        carry /= 10;
    }

    // Dummy node bhi present hai usko remove, and apne list ko remove karna
    head = Reverse(head->next, NULL);

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
    //  First number: 342  (3 → 4 → 2)
    Node *first = new Node(3);
    first->next = new Node(4);
    first->next->next = new Node(2);

    //  Second number: 465 (4 → 6 → 5)
    Node *second = new Node(4);
    second->next = new Node(6);
    second->next->next = new Node(5);

    cout << "First Number: ";
    display(first);

    cout << "Second Number: ";
    display(second);

    //  Add two lists
    Node *result = addTwoLists(first, second);

    cout << "Result (Sum): ";
    display(result);

    return 0;
}
