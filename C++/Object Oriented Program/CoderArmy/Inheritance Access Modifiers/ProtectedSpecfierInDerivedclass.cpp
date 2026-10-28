#include<iostream>
using namespace std;

class Human
{                  
    public:    
    string name;       
    int age, weight;

};

class Student : protected Human   // jo be is class human class se aayega wo public rehega.
{
    int rol_number, fees;     // name can be printed (by making function) from here but from here but not outside.
    public:
    void fun(string n, int a, int w)       // Here name becomes protected as above in 12 we use Protected.
    {
        name=n;
        age=a;
        weight=w;
        cout<<name<<" "<<age<<" "<<weight<<endl;
    }
};            
int main()
{
    Student A;
    A.fun("Rohit", 23, 56);
}