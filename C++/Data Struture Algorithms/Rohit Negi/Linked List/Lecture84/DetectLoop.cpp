#include <iostream>
#include <vector>
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

bool check(vector<Node *> &visited, Node *curr)
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == curr)
            return 1;
    }
    return 0;
}

// function to check if the linked list has a loop
bool detectLoop(Node *head)
{
    Node *curr = head;
    vector<Node *> visited;

    while (curr)
    {
        //  Node is already visited or not
        if (check(visited, curr))
            return;

        visited.push_back(curr);
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

    // 🔁 Create loop (important for testing)
    third->next = second; // loop created

    if (detectLoop(head))
        cout << "Loop detected" << endl;
    else
        cout << "No loop" << endl;

    return 0;
}
