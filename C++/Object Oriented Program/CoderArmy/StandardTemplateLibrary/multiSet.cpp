// Multi-set can able have a duplicates element in it. and they are in sorted array.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int>s;
    s.insert(10);
    s.insert(20);
    s.insert(10);
    s.insert(30);

    //Printing the element of the multi set
    //Imlementation:- Red-black tree, AVL tree.
    for(auto it = s.begin(); it!=s.end();it++)
    {
        cout<<*it<<" ";
    } 
}