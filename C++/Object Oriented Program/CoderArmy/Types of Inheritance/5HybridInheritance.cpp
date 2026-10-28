/*
Hybrid Inheritance :-Combination of two different type of other inheritance. 
Example:-      class student boy girl male female
Student[]
Male[]
Boy[{Student}{male}]
Female[]
Girls[{Student} {Female}]

*/
#include<iostream>
using namespace std;

class Student
{
    public:
    void print()
    {
        cout<<"I am student \n";
    }
};
class male
{
   public:
   void Maleprint()
   {
     cout<<"I am Male\n";
   }
};
class Female
{
   public:
   void Maleprint()
   {
     cout<<"I am Female\n";
   }
};   
class Boy : public Student , public male
{
  public : 
  void Boyprint()
  {
    cout<<"I am boy\n";
  }
};
class Girl : public Student , public Female
{
  public : 
  void Girlprint()
  {
    cout<<"I am Girl\n";
  }
};

int main()
{
    Girl G1;
    G1.Girlprint();
    G1.print();
    Boy B1;
    B1.Boyprint();
    B1.Maleprint();
    B1.print();
    return 0;
}

