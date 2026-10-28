#include <iostream>
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

Node *find(Node *curr1, Node *curr2, Node *x)
{
    if (x == NULL)
        return NULL;

    while (curr1 != x)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return curr2;
}

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

    // Assign random pointer to clone it .
    tailCopy = headCopy;
    temp = head;

    while (temp)
    {
        tailCopy->arb = find(head, headCopy, temp->arb);
        tailCopy = tailCopy->next;
        temp = temp->next;
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
