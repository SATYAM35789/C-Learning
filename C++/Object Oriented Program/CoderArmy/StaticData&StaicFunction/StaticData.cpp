/*
Thay are attribute of classes or class member. It is declared using static keyword. Only one copy of that member
is created for the entire class and is shared by all  the object.
Class: hum class isiliye banate hai, taki jo bhi variable, data member, aur jo bhi data member unke function un 
sbb class ke ander likho 
Class Customer
{
   string name;
   int acc_num,balance;
   static int total_Customer;   // Intialize outside the class (to count it should be zero)

   public:
     Customer( string a, int b, int c)     used to intialize the object
    {  
        name = a;
        acc_acc=b;
        balance = c;
        toat_Customer++;
    }
};
syntex: to intialize the static data member outside the class.
datatypeOfDataMember Class_name:: DatamemberName = value; 
int Customer :: total_Customer =0;
int main()
{
   Customer A1("Rohit",1,1000);
   Customer A2("Mohit",2,1010)
}
Note: Static Member belongs to Class , Static data member created when class creted. Because of this we access it
without creating an object. 
and other data member are the part of the object. When create object then ye sab create honge. 
*/

#include<iostream>
using namespace std;

class Customer
{
   string name;
   int account_number,balance;
   

   public:
   static int total_Customer;   // Intialize outside the class (to count it should be zero)
    Customer( string name, int account_number, int balance)    // used to intialize the object
    {  
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
        total_Customer++;
    }
    void display()
    {
        cout<<name<<" "<<account_number<<" "<<balance<<total_Customer<<endl;
    }
    void display_total()
    {
        cout<<total_Customer<<endl;
    }
};
int Customer::total_Customer = 0;
int main()
{
  Customer A1("Rohit",1,1000);
  Customer A2("Mohit",2,1010);
  Customer A3("Mohan",3,1000);
  Customer::total_Customer=5;  // Prove that it belongs to class. not an object
  A2.display_total();  
}

