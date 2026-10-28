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
// Merge Function
Node *merge(Node *head1, Node *head2)
{
    // Creating dummy node
    Node *head = new Node(0);
    Node *tail = head;

    // Doing Compairsion , to insert in linked list, jab tak ye dono exist kare
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;
        }

        else
        {
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    if (head1)
        tail->next = head1;
    else
        tail->next = head2;

    return head->next;
}

void mergeSort(Node *arr[], int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    // left part
    mergeSort(arr, start, mid);
    // Right Part
    mergeSort(arr, mid + 1, end);

    arr[start] = merge(arr[start], arr[mid + 1]);
}

// Function to merge k sorted Linked List
Node *mergeKLists(Node *arr[], int k)
{
    mergeSort(arr, 0, k - 1);
    return arr[0];
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int k = 3;

    // 🔹 Creating array of linked lists
    Node *arr[k];

    // List 1: 1 → 4 → 7
    arr[0] = new Node(1);
    arr[0]->next = new Node(4);
    arr[0]->next->next = new Node(7);

    // List 2: 2 → 5 → 8
    arr[1] = new Node(2);
    arr[1]->next = new Node(5);
    arr[1]->next->next = new Node(8);

    // List 3: 3 → 6 → 9
    arr[2] = new Node(3);
    arr[2]->next = new Node(6);
    arr[2]->next->next = new Node(9);

    cout << "List 1: ";
    display(arr[0]);

    cout << "List 2: ";
    display(arr[1]);

    cout << "List 3: ";
    display(arr[2]);

    // 🔹 Merge all lists
    Node *result = mergeKLists(arr, k);

    cout << "Merged List: ";
    display(result);

    return 0;
}