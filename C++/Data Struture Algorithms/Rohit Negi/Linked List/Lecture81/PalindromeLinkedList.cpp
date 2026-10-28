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

bool isPalindrome(ListNode *head)
{
    // Count the no. nodes
    int count = 0;
    ListNode *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    count /= 2;
    ListNode *curr = head, *prev = NULL;
    //  Skip number of nodes
    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;

    //  Reverse the second linked list, curr is pointing
    ListNode *front;
    prev = NULL;

    while (curr)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    //  Prev is pointing to second list
    //  Head is pinting to first list
    ListNode *head1 = head, *head2 = prev;

    // Check pallindrome
    while (head1)
    {
        if (head1->val != head2->val)
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 1;
}
