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

ListNode *rotateList(ListNode *head, int k)
{
    // no node present
    if (head == NULL || head->next == NULL)
        return head;

    // count number of nodes
    int count = 0;
    ListNode *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    // when k is grater than No of node in the list
    k = k % count;
    if (k == 0)
        return head;

    count -= k;
    ListNode *curr = head, *prev = NULL;
    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    ListNode *Tail = curr;

    // Second list uske last node pe leke jao
    while (Tail->next != NULL)
    {
        Tail = Tail->next;
    }

    Tail->next = head;
    head = curr;
    return head;
}
