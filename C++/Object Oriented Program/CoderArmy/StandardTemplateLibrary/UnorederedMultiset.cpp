#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_multiset<int>s; // duplicates are allowed when we use multi
    s.insert(10);
    s.insert(20);
    s.insert(15);
    s.insert(30);
    s.insert(11);
    s.insert(10);

    for(auto it=s.begin(); it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
}
/*
set, multiset, unordered_set, unordered_multiset
set: Unique element, sorted.
multiset: sorted, duplicates are allowed.
unordered set: unique
unordered_multiset: duplicates are allowed. 
*/