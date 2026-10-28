#include <iostream>
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

Node *deleteK(Node *head, int k)
{
    Node *curr = head, *prev = NULL;
    int count = 1;

    if (k == 1)
        return NULL;

    while (curr)
    {
        // k==count,  delete node
        if (k == count)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count = 1;
        }
        //  k != count , skip the node
        else
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
    }
    return head;
}