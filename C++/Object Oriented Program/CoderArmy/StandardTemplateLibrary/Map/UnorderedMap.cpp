#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Unique keys are present, duplicates are not allowed.
// Not necessary it should be in sorted form. 
// Implementation: Hashing
// insert, search, delete in oeder of O(1) time.
int main()
{
    unordered_map<int,int>m;
    m.insert(make_pair(20,30));
    m.insert(make_pair(30,310));
    m.insert(make_pair(40,30));
    m.insert(make_pair(20,230));
    m.insert(make_pair(50,30));
    m[20]= 70; 
    
    for(auto it = m.begin(); it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}