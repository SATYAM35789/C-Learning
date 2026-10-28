#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

Node *removeDuplicates(Node *head)
{
    //  Second Method
    Node *curr = head->next, *prev = head;
    // Edge case if said that element may be 0
    if (!head || !head->next)
        return head;

    while (curr)
    {
        // Duplicate milta hai
        if (curr->data == prev->data)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        //  Duplicate nahi milta
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
        return head;
    }
}

int main()
{
    Node *head = NULL, *tail = NULL;
    //  Create doubly linked list
    int arr[] = {
        1,
        1,
        2,
        3,
        3,
        3,
        4,
        4,
    };
}