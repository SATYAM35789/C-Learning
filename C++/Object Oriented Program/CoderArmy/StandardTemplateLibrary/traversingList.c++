#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Traversing
int main()
{
    list<int>l;
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(45);
    l.push_front(50);
    
    // auto :- We donot know the which type of itrator is . So compiler itself automatically which would be. 
    // auto = list<int>::itrator
    for(auto it = l.begin(); it!=l.end(); it++)  // l.end()points next element. 
    {
        cout<<*it<<" "<<endl;
    }
}