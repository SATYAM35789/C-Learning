#include<iostream>
using namespace std;
class human
{
    public:
    virtual void fun()=0;
};
class student :public human
{
    public:
    void fun()
    {
        cout<<"Hello";
    }
};
int main()
{
human *p;
p=new student;
p->fun();

}
