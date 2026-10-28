#include<iostream>
using namespace std;
class human
{
   protected:
   string name;
   int age,height;
};

class youtuber: virtual public human
{
    protected:
    string subscriber;
    int videos;
};

class teacher :virtual public human
{
    protected:
    string subject;
    int id;
};
class student: public youtuber,public teacher
{
     protected:
     int fee;

     public:
     student(string name,int age,int height,string subscriber,int videos,string subject,int id,int fee)
     {
        this->name=name;
        this->age=age;
        this->height=height;
        this->subscriber=subscriber;
        this->videos=videos;
        this->subject=subject;
        this->fee=fee;
     }
        void display()
        {
            cout<<name<<" "<<age<<" "<<height<<" "<<subscriber<<" "<<videos<<" "<<subject<<" "<<id<<" "<<fee<<endl;
        }

     
};
int main()
{
   student A1("satyam",20,5,"100k",500,"OOPS",245,62000);
   A1.display();
}