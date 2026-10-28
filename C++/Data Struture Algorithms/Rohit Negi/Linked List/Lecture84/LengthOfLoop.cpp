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

// Function to find the length of a loop in the linked list
int countNumberInLoop(Node *head)
{
    Node *slow = head, *fast = head;

    // Detect the loop
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return 0;

    int count;
    slow = fast->next;
    while (slow != fast)
    {
        count++;
        slow = slow->next;
    }

    return count;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // Linking
    head->next = second;
    second->next = third;

    //  Create loop (important for testing)
    third->next = second; // loop created

    if (countNumberInLoop(head))
        cout << "Loop detected" << endl;
    else
        cout << "No loop" << endl;

    return 0;
}
