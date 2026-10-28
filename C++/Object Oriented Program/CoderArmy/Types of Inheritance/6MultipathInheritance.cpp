/*
Multipath Inheritance:- Multiple path se , kisi class mai same cheeje aa rahi hai.  
example
Human[ name, age]
Youtuber[{Human}]
Enginner[{Human}]
CodeTeacher[{Youtuber},{Engineer}]
*/
#include<iostream>
using namespace std;

class Human
{
   public:
   string name;

   void display()
   {
    cout<<"my name is:"<<name<<endl;
   }

};
class Engineer : public virtual Human
{
   public:
   string specilization;
   void work()
   {
    cout<<"I have a specilization in "<<specilization<<endl;
   }
};
class Youtuber : public virtual Human
{
    public:
    int subscriber;

    void contentcreator()
    {
       cout<<"I have a subscriber base of "<<subscriber<<endl;
    }
};
class CodeTeacher: public Engineer, public Youtuber
{
    public:
    int salary;
    CodeTeacher()
    {

    }
    CodeTeacher( string name, string specilization , int subsciber, int salary)
    {
        this->name = name;
        this->specilization = specilization;
        this->subscriber = subsciber;
        this->salary= salary; 
    }
};
int main()
{
  CodeTeacher A1;
  A1.display();
  CodeTeacher A2("Satyam","Cse",9900,89);
  A2.display();
}
// Multiple copies have inherted in the CodeTeacher by using the virtual in the parent class of CodeTeacher where 
// Human is inherited un both the class. 