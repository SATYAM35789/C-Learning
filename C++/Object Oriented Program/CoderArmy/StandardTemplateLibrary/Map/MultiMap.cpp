#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    multimap<int,int>m; // Bu using multi, duplicates are allowed.
    m.insert(make_pair(20,30));
    m.insert(make_pair(30,310));
    m.insert(make_pair(40,30));
    m.insert(make_pair(20,230));
    m.insert(make_pair(50,30)); 

    //m.[100]= 60; // Here duplication is allowed so compiler gets confused here , in which key the updation will be.
    for(auto it = m.begin(); it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}