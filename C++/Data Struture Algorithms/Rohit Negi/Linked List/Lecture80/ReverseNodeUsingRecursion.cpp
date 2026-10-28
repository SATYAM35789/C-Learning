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

ListNode * Reverse(ListNode *curr, ListNode *prev){
   if(curr==NULL)
   {
     return prev;
   }
   ListNode * fut = curr->next;
   curr->next = prev;
   return Reverse(fut, curr);
}

ListNode *reverseList(ListNode *head)
{
    Reverse(head , NULL);
}