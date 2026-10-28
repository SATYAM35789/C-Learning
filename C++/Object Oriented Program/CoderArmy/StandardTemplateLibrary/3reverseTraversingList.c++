#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Reverse Traversing
int main()
{
    list<int>l;
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(45);
    l.push_front(50);

    for(auto it = l.rbegin(); it!=l.rend(); it++){ 
        // here is not <= used because it is dynamically operated and their address may be anything in any order 
        cout<<*it<<" ";
    }
}