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

ListNode *reverseList(ListNode *head)
{
    ListNode * slow = head, *fast = head;
    while(fast&&fast->next)
    {
      slow=slow->next;
      fast = fast->next->next;
    }
     return slow;
}