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
    vector<int> ans;
    ListNode *temp = head;

    while (temp != NULL)
    {
        ans.push_back(temp->val);
        temp = temp->next;
    }

    int i = ans.size() - 1;
    temp = head;

    while (temp != NULL)
    {
        temp->val = ans[i];
        i--;
        temp = temp->next;
    }
    return head;
}