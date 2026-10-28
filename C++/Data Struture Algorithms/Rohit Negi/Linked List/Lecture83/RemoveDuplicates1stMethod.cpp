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
    //  First Method
    vector<int> ans;
    ans.push_back(head->data);

    Node *curr = head->next;
    while (curr)
    {
        // Duplicates nahi mila
        if (ans[ans.size() - 1 != curr->data])
        {
            ans.push_back(curr->data);
            curr = curr->next;
        }
        //  Duplicates mila
        curr = curr->next;
    }
    curr = head;
    int index = 0;
    Node *prev = NULL;
    while (index < ans.size())
    {
        curr->data = ans[index];
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    return head;
    // Note prev pointer ke help se humko ektra condition likhne ki zarurat nahi padegi. vector se hum linked list
    // apna data dal rahe the, linked list abhi bhi bachi hai usko null karne padegea iske liye.
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