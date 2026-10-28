/*
customer A1("Rohit", 123, 1000);
Wants to copy A1 object
customer A2(A1);
Copy constructor are already exist in the program. If create the copy constructor than compiler not create again.

    Understanding the copy constructor
    Customer (Custromer &B)
    {
       name=B.name;
       account_number = B.account_number; 
       balance = B.balance;

    }
};
int main()
{
  Customer A2(A1);

}

*/
#include<iostream>
using namespace std;

class Customer
{
    string name;
    int account_number;
    int balance;

    public:
    // Default constructor 
    Customer()
    {
        cout<<"Default constructor called\n";
        name="Rohit";
        account_number = 678;
        balance = 900;
    }
    Customer(string name, int account_number, int balance)
    {
        cout<<"Second Constructor is called"<<endl;
        this->name=name;
        this->account_number;account_number;
        this->balance=balance;

    }
    void Dispaly()
    {
        cout<<name<<" "<<account_number<<" "<<balance<<endl;
    }
    // Copy Constructor
    Customer(Customer &B)
    {
        name=B.name;
        account_number=B.account_number;
        balance=B.balance;
    }
};
int main()
{
    Customer A1;
    A1.Dispaly();
    Customer A2("Satyam",20675675, 3000);
    Customer A3(A2);
    A3.Dispaly();
    Customer A4;
    A4 = A1;   // Assignment opertor
    A4.Dispaly();
}