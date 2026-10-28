#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Problem: We want store three variable in a pair but pair has two variable only?
// name, age, weight
// taking pair as(age weight) single name
int main()
{
   pair<string, pair<int,int>>p;
   p.first = "Rohit";
   p.second.first=25;
   p.second.second = 75;

   cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;

   /*
   using second method
   p=make_pair("rohit",make_pair(25,75));
   */  
}