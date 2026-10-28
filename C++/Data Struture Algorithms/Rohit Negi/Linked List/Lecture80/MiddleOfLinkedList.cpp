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

ListNode *middleList(ListNode *head)
{
    int count = 0;
    //   Count total number of nodes
    ListNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    count /= 2;
    //  Number of steps to take from the start
    temp = head;
    while (count--)
    {
        temp = temp->next;
    }
    return temp;
}