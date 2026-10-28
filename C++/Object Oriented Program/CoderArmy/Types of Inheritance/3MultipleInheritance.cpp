/* Multiple inheritance:- Multi class like Teacher, YouTuber se inherit ho raha hoga toh, wo Multiple Inheritance.
   Data member= []
   Example1: 
   YouTuber[subscriber, typeofvideos]
   Teacher[Salary,Subject]
   Rohit[Teacher, YouTuber, gamer]
   
*/
#include<iostream>
using namespace std;

class Engineer
{  void money()    // This is privated by default show cannot be access by the CodeTeacher object.

   {
     cout<<"Hello Money"<<endl;
   }
   public:
   string specilization;
   void work()
   {
    cout<<"I have a specilization in "<<specilization<<endl;
   }
   Engineer()
   {
      cout<<" Hello enginner"<<endl;
   }
};
class Youtuber
{
    public:
    int subscriber;

    Youtuber()
    {
        cout<<" Hello Youtuber"<<endl;
    }

    void contentcreator()
    {
       cout<<"I have a subscriber base of "<<subscriber<<endl;
    }
};
class CodeTeacher: public Engineer, public Youtuber
{
    public:
    string name;
    
    CodeTeacher()
    {
        cout<<"Hello CodeTeacher"<<endl;
    }
    CodeTeacher( string name, string specilization , int subsciber)
    {
        this->name = name;
        this->specilization = specilization;
        this->subscriber = subsciber;
    }
    void show()
    {
      cout<<"My name is:"<<name<<endl;
      work();
      contentcreator();
    }

};
int main()
{
  CodeTeacher A1; // Seeing Which constructor run first
  
}
