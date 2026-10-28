/*  Ek code bar bar n likhna pade . 
Single Class:- A data members accces by derived class from parent class.
Example 1:
Human Class:-data members:-name, age 
Student class :- Data members:- name, age (inherited by human), collagefees, rollno.

*/
#include<iostream>
using namespace std;

class Human
{
    protected:
    string name;
    int age;

    public:
    // This fun used to check , is i able use that fun. 
    void work()
    {
        cout<<"I am working \n";
    }
};

class student : public Human
{
    int roll_number , fees;
    public:
    // Makinhg constructor to intize the data member of an object.
    student(string name, int age, int roll_number,int fees)
    {
        this->name= name;
        this->age = age ; 
        this->roll_number = roll_number;
        this->fees = fees;
    }


};
int main()
{
    student A1("Rohit", 23, 43,998);
    // Accessing the fun of parent class with the help of derived class of an object.
    A1.work();
}