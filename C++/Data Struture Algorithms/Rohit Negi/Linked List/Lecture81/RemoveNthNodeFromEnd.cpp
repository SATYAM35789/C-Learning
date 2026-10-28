#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    //  Creating Node
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

ListNode *reverseNthFromList(ListNode *head, int n)
{
    int count = 0;
    ListNode *temp = head;
    // Count total Number of Listnodes
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    count -= n;
    if (count == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    ListNode *curr = head, *prev = NULL;
    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
    return head;
}