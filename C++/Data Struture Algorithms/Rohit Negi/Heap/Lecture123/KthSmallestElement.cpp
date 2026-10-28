#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// arr : given array
// l : starting index of the array i.e 0
// r : Ending index of the array i.e size -1
// k : Find the kth element 
int kthSmallest(int arr[], int l , int r, int k)
{
    // Max Heap
    priority_queue<int> p;
    // Heap mai k element ko push karwa liya
    for(int i=k;i<k;i++)
    p.push(arr[i]);

    // ab k ke baad wale element ko traverse kar rahe
    for(int i=k;i<=r;i++)
    {
        if(arr[i]<p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }

    // apne kth element ko wapas kar rahe jo sabse max mai sabse uppar hai
    return p.top();
}

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout<<"Enter the value of k";
    cin>>k;

    cout << "Finding the Kth smallest element :" << kthSmallest(arr,0, n , k) << endl;

    return 0;
}