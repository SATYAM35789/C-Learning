#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *arb;

    Node(int value)
    {
        data = value;
        next = NULL;
        arb = NULL;
    }
};

Node *copyList(Node *head)
{
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = head;

    // Clone created without Random pointer
    while (temp)
    {
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    tailCopy = headCopy;
    temp = head;

    //  Insert them in the original LL
    Node *curr1 = head, *curr2 = headCopy;
    Node *front1, *frontCopy;

    while (curr1)
    {
        front1 = curr1->next;
        frontCopy = curr2->next;
        curr1->next = curr2;
        curr2->next = front1;
        curr1 = front1;
        curr2 = frontCopy;
    }

    // Assign Random pointer to clone linked list
    curr1 = head;
    while (curr1)
    {
        curr2 = curr1->next;
        if (curr1->arb)
            curr2->arb = curr1->arb->next;
        curr1 = curr2->next;
    }

    // Break the LL
    curr1 = head;
    while (curr1->next)
    {
        front1 = curr1->next;
        curr1->next = front1->next;
        curr1 = front1;
    }
    return headCopy;
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

//  Create list
Node *createList()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    return head;
}

//  Set random pointers
void setRandomPointers(Node *head)
{
    Node *first = head;
    Node *second = head->next;
    Node *third = second->next;
    Node *fourth = third->next;

    first->arb = third;   // 1 → 3
    second->arb = first;  // 2 → 1
    third->arb = fourth;  // 3 → 4
    fourth->arb = second; // 4 → 2
}

//  Display random pointers
void displayRandom(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        if (temp->arb)
            cout << temp->arb->data;
        else
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main()
{
    //  Create original list
    Node *head = createList();

    //  Set random pointers
    setRandomPointers(head);

    //  Display original
    cout << "Original List: ";
    display(head);

    cout << "Original Random:\n";
    displayRandom(head);

    //  Clone list
    Node *clonedHead = copyList(head);

    //  Display cloned
    cout << "\nCloned List: ";
    display(clonedHead);

    cout << "Cloned Random:\n";
    displayRandom(clonedHead);

    return 0;
}
