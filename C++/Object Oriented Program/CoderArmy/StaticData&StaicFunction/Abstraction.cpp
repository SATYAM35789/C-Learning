/*
Abstractipon :- Displaying essential information and hiding the details. 
Example related to real world :- 1. Order momo at F cafe 2. Sending message to friend. Pow(2,4) power fun
*/
#include<iostream>
using namespace std;

class Customer
{  
    private:                         //default case
    string name;
    int account_number,balance, age;
    public:
    Customer( string name, int account_number, int balance, int age)    // used to intialize the object
    {  
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
        this->age=age;
    }

    // To Deposit the money in the bank
    void deposit(int amount)
    {
        if(amount>0){
            balance+=amount;
        }
        else
        {
            cout<<"Invalid Amount"<<endl;
        }
    }

    // To Withdraw
    void withdraw(int amount)
    {
        if(amount<=balance&&amount>0)
        {
            balance-=amount;
        }
        else
        {
            cout<<"Your balance is low withdraw"<<endl;
        }
    }
    void updateage(int age){
        if(age>0&&age<100){
            this->age=age;
        }
        else
        {
            cout<<"Invalid age"<<endl;
        }
    }

    // Display The detail of Customer
    void display()
    {
        cout<<name<<"  "<<account_number<<"  "<<balance<<"  "<<age<<endl;
    }
};

int main()
{
  Customer A1("Rohit",1,3000,33);
  Customer A2("Mohit",2,2000,23);
  Customer A3("Mohan",3,1000,27);
  A1.deposit(10);
  A1.updateage(40);
  A1.deposit(45);
  A1.display();
}