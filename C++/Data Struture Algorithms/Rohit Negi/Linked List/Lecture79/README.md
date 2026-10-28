## Delete Node

### Delete first Node from Linked list:- :-
1. Sabse pahle ek pointer le lenge temp naam ka jo ki head ko point karege. 
2. Head ko head ki next value ko point karwa denge. 
3. temp jisko point kar raha hai usko delete kar denge. 

What would be the cases which we may consider while deleting:-
1. Jab koi link list exist n kare , so uppar wali approch tabhi lagayenge tab Linked list exist kare.
```
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

Node *CreateLinkedList(int arr[], int index, int size)
{
    //  Base case
    if (index == size)
        return NULL;

    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index + 1, size);

    return temp;
}

int main()
{
    Node *Head, *Tail;
    Tail = Head = NULL;

    //  Insert the node at End

    int arr[] = {2, 4, 6, 8, 10};
    Head = CreateLinkedList(arr, 0, 5);

    // Delete a node at start
    if(Head!=NULL)
    {
        Node *temp = Head;
        Head=Head->next;
        delete temp;
    }

    //  Traversing the linked list to verify
    Node *temp;
    temp = Head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
```

### Delete a Node from the End of the Linkedd List:-
SO end se delete karne ke liye pahle humko end tak jana padega, Hum head pointer ko move nahi karwa sakta for the same reason we discussed earlier. 
1. So ab ek pointer le lenge current (curr) naam ka 
2. Is variable ko move karwayenge aur check karenge, jaha null waha ruk jao aur usko delete kar do. 
3. Isko delete karene ke baad humko last node ko null karna hai , ye tabhi possible jab ek aur pointer last node ke prevNode ko point kare. 
Note: We need to pointer to delete from the end of the list. 

Creating two pointer:-
At start curr points head and prev point to NULL and After that prev point to curr and curr points to curr->next and so on until it reached to the end of the linked list. 

Constraints :- 
1. Linked list should exist.
2. When there is only one node exist in the linked list in case of deleting from the end. or according above approch. 
3. When we have more than one linked list. 
```
```

### Delete partcular Node:-
1. Particular node ko delete karne ke liye pahle uske pahle pahuchna padega. So pointer banayenge curr naam ka, maan lo usko delete kar diye lakin ek aur pointer ki zarurat padegi , particular node ke baad vali node ko store karne ke liye (prev).

Constraints :- 
1. Delete the first node.  
It handles the Delete from end Node case we donot need do any change. 
```
Node *deleteNode(Node *head, int x){
    if(x==1)
    {
      Node *temp = head;
      head = head->next;
      delete temp;

      return head;  // Return the address of Head
    }
    x--;  // x= x-1
    Node *curr = head;
    Node *prev = NULL;

    while (x--)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next=curr->next;
    delete curr; 

    return head;
    
}

```
### Delete from Particular node by recursion
1. Particular node par reach karenge. Ek temp pointer banayenge aur jisko delete karna hai uske next address ki value store kar lenge. :- Base Case
2. Main:- function call , to go to next node. and x ko ek se decrement kar denge. Is main function jo bhi return karege usko curr->next mai daal fo.  
```
Node *deleteNode(Node *curr, int x)
{
    if (x == 1)
    {
        Node *temp = curr->next;
        delete curr;
        return temp;
    }
    curr->next = deleteNode(curr->next, x - 1);
    return curr;
}
```

### Delete without head pointer
so hamko mile ek pointer jo jis pointer ko delete karna hai, bina head ke, so ham kya karenge. So ab jo pointer mila hai uske next ke data ko copy kar lenge with the help of temp and aur temp le next ka address curr ke next mai daal denge , phir temp ko delete kar denge. 
```
void deleteNode(Node *curr)
{
   Node *temp = curr->next;
   curr->data = temp->data;
   curr->next = temp->next;
   delete temp;
}
```
### Compexity compairsion of Array and Linked List or Need of Linked List
1. Array take O(n) and Linked list O(1) At starting place.
2. Array take O(1) and Linked list O(n) At starting place.
linked list case mai O(n) while creating tail we them also need the O(n) tail ko wapas se last Node par lana padega. Isi Case mai agar tail iske aage wale ko point karta tha O(n) nahi lagega. We have doubly linked list. 

