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
    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void dispaly(){
        cout<<name<<" "<<age<<endl;
    }

};

class student : public Human
{
    int roll_number , fees;
    public:
    // Makinhg constructor to intize the data member of an object.
    // Mai yahi se upper wale construcor ko call kar sakta hu
    student(string name, int age, int roll_number,int fees):Human(name, age)
    {
        this->roll_number = roll_number;
        this->fees = fees;
    }

    void display()
    {
        cout<<name<<" "<<age<<" "<<roll_number<<" "<<fees<<endl;
    }

};
int main()
{
    student A1("Rohit", 23, 43,998);
    // Accessing the fun of parent class with the help of derived class of an object.
    A1.work();
    A1.display();
}
/* 
In derived class callind constructor:-
Compiler go Student class , constructor than it show there that first it call to the parent class constructor. 

Two display()
where does compiler go first parent class and derived class?
Jiska object us class ko access karne ki kosis karenga, so compilier see the display in object called class and then 
and access it. 
Agar display child class or called class mai nahi toh derived class mai jayega. 
*/