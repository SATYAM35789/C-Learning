#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Person{
    public:
    int age;
    string name;
};
int main()
{
    set<Person>s;
    Person p1,p2,p3;
    p1.age=10,p1.name = "Rohit";
    p2.age=20,p2.name = "Satyam";
    p3.age=30,p3.name = "Sidhu";  
    // Here it gives the error because it unbable decide the criteria of element to enter

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);  
}