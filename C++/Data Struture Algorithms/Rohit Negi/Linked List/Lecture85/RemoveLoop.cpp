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

// Function to remove a loop in the linked list
void removeLoop(Node *head)
{
    //  Detect the loop
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }
    if (fast == NULL && fast->next == NULL)
        return;

    slow = head;
    // Meet the slow and fast
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    //  Slow ko last node par lekar jao, for breaking the loop
    while (slow->next != fast)
    {
        slow = slow->next;
    }

    slow->next = NULL;
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
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    // Linking
    head->next = second;
    second->next = third;
    third->next = fourth;

    // 🔁 Create loop (test case)
    fourth->next = second;

    // Remove loop
    removeLoop(head);

    // Display list after removing loop
    display(head);

    return 0;
}
