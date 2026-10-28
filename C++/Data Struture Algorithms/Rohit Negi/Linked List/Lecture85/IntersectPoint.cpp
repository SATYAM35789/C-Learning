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

// Function to find intersection point in Y shaped linked list
int intersectPoint(Node *head1, Node *head2)
{
    // Number of nodes Counting
    Node *curr1 = head1, *curr2 = head2;
    int count1 = 0, count2 = 0;

    while (curr1)
    {
        count1++;
        curr1 = curr1->next;
    }

    while (curr2)
    {
        count2++;
        curr2 = curr2->next;
    }
    // Level matching of the Nodes
    curr1 = head1, curr2 = head2;

    while (count1 > count2)
    {
        count1--;
        curr1 = curr1->next;
    }

    while (count2 > count1)
    {
        count2--;
        curr2 = curr2->next;
    }

    // Jaha dono same ho kaye us node ka data ko wapas karna hai.
    while (curr1 != curr2)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // Agar in dono branxhes mai se koi bhi ek null means , intersection point nahi hai.
    if (!curr1)
        return -1;

    return curr1->data;
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
    //  Common part (intersection)
    Node *common1 = new Node(30);
    Node *common2 = new Node(40);
    Node *common3 = new Node(50);

    common1->next = common2;
    common2->next = common3;

    //  First Linked List: 10 → 20 → 30 → 40 → 50
    Node *head1 = new Node(10);
    Node *second1 = new Node(20);

    head1->next = second1;
    second1->next = common1;

    //  Second Linked List: 15 → 30 → 40 → 50
    Node *head2 = new Node(15);
    head2->next = common1;

    //  Display both lists
    cout << "List 1: ";
    display(head1);

    cout << "List 2: ";
    display(head2);

    // Find intersection
    int result = intersectPoint(head1, head2);

    if (result == -1)
        cout << "No intersection\n";
    else
        cout << "Intersection at node with data: " << result << endl;

    return 0;
}
