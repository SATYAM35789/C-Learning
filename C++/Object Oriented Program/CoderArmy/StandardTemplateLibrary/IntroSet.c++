/*
Set :- It is also an container that store the data.
Property :- 
1.It stores only unique element.  
2.It store the value in sorted array.(by default ascending order)
Application:-
1. log(n): search,insert,delete
Implementation of the set:-AVL trees it takes log(n) time to insert,search,and delete. Or 
Red-Black tree (no of rotaion is less as compaired to Delete.) 
Real World Example:- Id created on the instagram or any other application.
Syntex:- set<int>name_of_set;
We can sort it in descending Order also using greater<type>
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int>s;
    s.insert(130);
    s.insert(20);
    s.insert(230); 
    s.insert(10);
    s.insert(100);
    s.insert(110);
    s.insert(50);

    for(auto it = s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
}