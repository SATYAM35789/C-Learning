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
    Node *curr = head;
    unordered_map<Node *, bool> visited;

    while (curr)
    {
        //  Node is already visited or not
        if (visited[curr] == 1)
            return 1;

        visited[curr] == 1;
        curr = curr->next;
    }

    return 0;
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
