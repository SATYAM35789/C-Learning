#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Person{
    public:
    int age;
    string name;

    bool operator < (const Person &other)const{
        // Yaha p2 as argument pass hua hai aur p1 call kar raha hai.
        return age<other.age;   // Change the < operator to > and see change
    }
};
int main()
{
    set<Person>s;
    Person p1,p2,p3;
    p1.age=10,p1.name = "Rohit";
    p2.age=40,p2.name = "Satyam";
    p3.age=30,p3.name = "Sidhu";

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);

    for (auto it=s.begin();it!=s.end();it++)
    {
        cout<<it->age<<" "<<(*it).name<<endl;
    }    
};