/*
Hierarchical inheritance:- Base class having multiple children
Human[name, age] BASE CLASS
Student[{Human} rollno, fees]  child of Human
Teacher[{Human},salary, employ_id]  child of Human

*/
#include<iostream>
using namespace std;

class Human  // Here must be default constructor if any other type of constructor is present
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
    void display()
    {
        cout<<name<<" "<<age<<" "<<roll_number<<" "<<fees<<endl;
    }
};
class Teacher : public Human
{
   int salary;

   public:
   Teacher(int salary, string name, int age)
   {
     this->salary=salary;
     this->name = name;
     this->age = age; 
   }
   void display()
   {
     cout<<name<<" "<<age<<" "<<salary<<endl;
   }
};
int main()
{
    student A1("Rohit", 23, 43,998);
    A1.display();
    Teacher A2(900,"mohit",34);
    A2.display();
}