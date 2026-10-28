/*
Polymorphism:- It is derived from greek word, which means many forms.
They are of two type:-
1. Compile time :- 1. Function Overloading 2. Operator Overloading
Compile Time:- It's check the written code, syntex error(comma). then it converted into machine execution code.(Binary form)
2. Runtime :- Virtual Function
RunTime Error:- Execution code is than run. And this is called Runtime. (Exception handling error)  

Function Overloading:- same name with different forms (parameter). 

*/
#include<iostream>
using namespace std;

class Area
{
    public: 
    int calculateArea(int r)
    {
        return 3.14*r*r;
    }
    int calculateArea(int l,int b)
    {
        return l*b;
    }

};
int main()
{
    Area A1,A2;
    cout<<A1.calculateArea(5)<<endl;
    cout<<A2.calculateArea(5,8)<<endl;

}
