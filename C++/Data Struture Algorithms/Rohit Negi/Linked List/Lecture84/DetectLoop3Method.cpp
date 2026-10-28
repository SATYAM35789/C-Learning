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

// function to check if the linked list has a loop
bool detectLoop(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;

        if (slow == fast)
        {
            return true;
        }
        return false;
    }
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

    if (detectLoop(head))
        cout << "Loop detected" << endl;
    else
        cout << "No loop" << endl;

    return 0;
}
