#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//We can sort it in descending Order also using greater<type>
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

    for(auto it = s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
}