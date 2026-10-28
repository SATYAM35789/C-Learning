#include<iostream>
using namespace std;

class Human
{                  // When this is private then unable to acces the attribute of this class.
    public:    
    string name;
    int age, weight;

};

class Student : public Human   // jo be is class human class se aayega wo public rehega.
{
    int rol_number, fees;

    // protected:       It seems like to be that it come from base to derived. and we know this is protected so
    // string name;     cannot be access.
    // int age, weight;

};
int main()
{
    Student A;
    A.name="rohit";
}