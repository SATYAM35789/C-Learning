/* Explict casting : Programmer mannually change the datatype from one to another. 
   Need of explict casting ? Using a assignment opretor


*/
#include<iostream>
using namespace std;
/*
int main()
{
    int num1 = 7, num2 = 3;
    float result ;
    cout<<"This is the Implicit conversion"<<endl;
    cout<<" Result :"<<num1/num2<<endl;   // Here we are losing some data. To retrive we use  explict datatype.  
    return 0;

}
*/
int main()
{
    int num1 = 7, num2 = 3;
    float result ;
    cout<<"This is the Implicit conversion"<<endl;
    cout<<" Result :"<<num1/num2<<endl;   // Here we are losing some data. To retrive we use  explict datatype.  
    cout<<"This is the Explicit conversion"<<endl;
    // Syntex oF asssinment  
    // (type) expression  
    result = (float) num1/num2;   
    cout<<"Result:"<<result<<endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    return 0;

}