/*
list:- it is like a doubly linked list.We can implement doubly linked list directly with the help of linked list. 
syntex: list<type>name_oflist; 
Example: 30,50,70,80.
list<int>l1;          fn()like:- push_back(),push_front(),pop_front(),pop_back(),front(),back()
l1.push_back(30);
l1.push_back(50);
l1.push_front(70);
l1.pushback(90);
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//push_front push_back
// size
//pop_front ,pop_back
int main()
{
    list<int>l;
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(45);
    l.push_front(50);
    l.pop_front();
    l.pop_back();
    
    cout<<l.front()<<" "<<l.back()<<endl;
    cout<<l.size()<<" "<<endl;
}