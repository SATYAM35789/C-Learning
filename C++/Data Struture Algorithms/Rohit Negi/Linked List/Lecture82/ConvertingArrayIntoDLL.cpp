#include <iostream>
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

int main()
{
    Node *head=NULL , *tail = NULL;
    //  Create doubly linked list 
    int arr[] = {1,2,3,4,5};

    for(int i=0; i<5 ; i++)
    {
        //  Linked List doesnot exist
        if(head==NULL)
        {
            head = new Node(arr[i]);
            tail = head;
        } 
        // Linked list exist
        else{
            Node *temp = new Node(arr[i]);
            tail->next= temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    // Print the value of Doubly linked list
    Node *trav = head;
    while (trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
} 