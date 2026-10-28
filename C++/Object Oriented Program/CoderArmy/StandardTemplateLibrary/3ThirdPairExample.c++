#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// name,age,weight
// pair first two variable and third is single
// Practice for 4variable, 5 variable, 6 variable
// name,age,weight, money
int main()
{
   pair<pair<string, int>,int>p;
   p=make_pair(make_pair("Rohit",75), 80);
   cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<endl;
}