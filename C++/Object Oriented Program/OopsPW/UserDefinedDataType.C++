//#1. User Defined Data Type:-
// Here We have created the own datatype 
#include<iostream>
using namespace std;

class student{    // Student is new data type
public:
    string name;          // This three are  property 
    int rno;       
    float gpa;
   
};
int main(){     // student is a datatype and s1 amd s2 are the variables.
    student s1;
    s1.name = "Satyam Mishra";
    //s1.rno = 78;
    s1.gpa = 8.2;
    cin>>s1.rno;   // We can also take the input

    student s2;
    s2.name = " ARM";
    s2.rno = 356;
    s2.gpa = 8.5;

    cout<<s1.name<<""<<s1.rno<<""<<s1.gpa<<endl;
    cout<<s2.name<<""<<s2.rno<<""<<s2.gpa<<endl;
    


}
