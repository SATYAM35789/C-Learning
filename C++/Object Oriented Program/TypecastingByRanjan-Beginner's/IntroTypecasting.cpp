/* Type Casting:- Converting one datatype into  amother datatype. 
Two Types:- 
Implicit type casting or implicit type conversion:- Automatic conversion.
Because the type convertion is done by the compiler automatically. 
Explicit type casting or explicit type conversion:- Forced Converstion.

*/
#include<iostream>
using namespace std;

// int main()
// {
//     int number1 = 9;  // here number1 is int datatype.
//     double number2;   // here nimber2 is the double datatype.
//     number2 = number1;
//     cout<<"Interger Value = "<<number1<<endl;
//     cout<<"Double Value = "<<number2<<endl;

//     return 0;
//   // In result WE have int type of datatype. Here the value are not changed. 

    // Order of the typecast in implicit conversion
    // Lowest to Highest
    // bool-> char->short->int->unsigned->long int->unsigned long int-> long long int-> float->double->long double 
    //  lower to higher would not be changed, aotomatically. 
    //  In Higher to lower there would be the loss of data. 
// } 

// Implicit Casting
int main()
{
    int number1 ;  
    double number2 = 9.76;   
    number1 = number2;
    cout<<"Interger Value = "<<number1<<endl;
    cout<<"Double Value = "<<number2<<endl;
// Here we can see that double type of datatype is converted into int type of datatype.
// so here the compiler automatically converted double into int

    return 0;
}