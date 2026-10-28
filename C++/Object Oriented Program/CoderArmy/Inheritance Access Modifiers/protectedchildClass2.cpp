#include<iostream>
using namespace std;

class Human
{   
    string Religion,Colour;

    public:    // If private than it is not able access in child class to. 
    string name;       
    int age, weight;

};

class Student : private Human {   // here private do  any accessspecifier in base we can able to access under this class
    int roll_number, fees;    
    public:
    
    Student(string name, int age, int weight, int roll_number, int fees)
    {
        this->name= name;
        this->age= age;
        this->weight= weight;
        this->roll_number= roll_number;
        this->fees= fees;
    }
    void display()
    {
        cout<<name<<" "<<age<<" "<<weight<<" "<<roll_number<<" "<<fees<<endl;
    }

    
};
class Teacher: public Human{
        public:
        int salary, id;
};

int main()
{
    Student A("Rohit",23,56,117,80000);
    A.display();
    Teacher B;
    B.name = " Mohit";
    B.age = 35;
    B.weight=45;
    B.salary = 350000;



    return 0;
}  