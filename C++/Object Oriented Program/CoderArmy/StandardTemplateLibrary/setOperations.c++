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
    // Search the element?
    // find operator
    if(s.find(10)!=s.end()) // jo bhi value ye return karega wo usko itrator point karega. if not than end() isko point karega. 
    cout<<"Present\n";
    else
    cout<<"Absent\n";
    
    // searching with another method
    if(s.count(10))   // s.count(110) checks how many times it occured in the set.
    cout<<"prsent";
    else
    cout<<"absent";
    cout<<s.count(10)<<" "<<endl;
}