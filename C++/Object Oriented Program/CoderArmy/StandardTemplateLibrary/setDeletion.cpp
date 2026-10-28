#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
1.Search
2.Delete
3.Insert
*/
int main()
{
    set<int ,greater<int>>s;
    s.insert(130);
    s.insert(20);
    s.insert(230); 
    s.insert(10);
    s.insert(100);
    s.insert(110);
    s.insert(50);
    
    //Delete
    s.erase(110);
    cout<<s.count(110)<<" ";  //count, count of thata number
}