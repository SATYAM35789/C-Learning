#include<iostream>
using namespace std;

class Human
{
    protected:
    string name;
    int age;

    public:
    Human()
    {
        cout<<"Human called \n";
    }

    ~Human()
    {
        cout<<"Human destructor \n";
    }
};

class student : public Human
{
    int roll_number , fees;
    public:
    
    student()
    {
        cout<<" Hello derived \n";
    }

    ~student()
    {
        cout<<" student destructor \n";
    }


};
int main()
{
   student A1;
}
/*  In case of constructor
When we creating the  object derived class it goes to derived class, and compiler  the that derived class 
class is inheriting something from parent class(Human), then go to the parent class object.

Destructor working case in inheritance:-
Destructor work opposite to the constructor. 
  
*/