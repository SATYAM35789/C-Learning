/*#1 Multilevel Inheritance:- 
DataMember = []
Example 1:- GrandFather->Father->Son
Example 2:- Person[ name, age]->Emloyee[salary]->Manager[department, no_of_emplo]
Example 3 :- Animal[veg,Non_veg]->Dog[]->German_spharad[]
*/
#include<iostream>
using namespace std;

class Person
{
    protected : 
    string name;

    public:
    void introduce()
    {
        cout<<" My name is :"<<name<<endl;

    }
};

class Employee : public Person
{
    protected:
    int salary;

    public:
    void month_salary()
    {
        cout<<" My monthaly salary is "<<salary<<endl;
    } 
};

class manager : public Employee  // By inheriting Employee , both above class will be inherited. 
{
    public:
    string department;
    manager(string name, int salary, string department)
    {
        this->name = name;
        this->salary = salary;
        this->department = department;
    }
    void work()
    {
       cout<<"I am leading the department"<<department<<endl;
    }
    
};
int main()
{
    manager A1("Satyam", 200, "Finance");
    A1.work();
    A1.month_salary();
    A1.introduce();
}