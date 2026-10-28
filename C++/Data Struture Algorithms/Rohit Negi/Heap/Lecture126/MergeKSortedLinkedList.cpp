#include <iostream>
#include <bits/stdc++.h>
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

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
    // Kya a aur b ka order sahi hai and Heap ke case mai ulta kaam karta hai.
};

Node *mergeKLists(Node *arr[], int k)
{
    // Min Heap
    priority_queue<Node *, vector<Node *>, Compare> p(arr, arr + k);

    Node *root = new Node(0); // Creating duplicate node so ki linked list return aur banane mai east ho.
    Node *tail = root;

    Node *temp;

    while (!p.empty())
    {
        temp = p.top(); // 0 ,1,3,4 5,6,7
        p.pop();
        tail->next = temp;
        tail = tail->next; // increment
        if (temp->next)
            p.push(temp->next);
    }
    return root->next; // 0 wale ko remove karke ke bhej rahe hai.
}