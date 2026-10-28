#include<iostream>
using namespace std;

class Customer
{
   string name;
   int account_number,balance;
   static int total_balance;
   static int total_Customer;   // Intialize outside the class (to count it should be zero)

   public:
   
    Customer( string name, int account_number, int balance)    // used to intialize the object
    {  
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
        total_Customer++;
        total_balance+=balance;
    }
    // To Deposit the money in the bank
    void deposit(int amount)
    {
        if(amount>0){
            balance+=amount;
            total_balance+=amount;
        }
    }

    // To Withdraw
    void withdraw(int amount)
    {
        if(amount<=balance&&amount>0)
        {
            balance-=amount;
            total_balance-=amount;
        }
    }

    // Display The detail of Customer
    void display()
    {
        cout<<name<<" "<<account_number<<" "<<balance<<total_Customer<<endl;
    }

    // Used to give detail of totalcustomer with help of class. 
    static void accessStatic()         // Only able access the static data member
    {
        cout<<"Tatal number of customer "<<total_Customer<<endl;
        cout<<"Tatal number of Balance "<<total_balance<<endl;
    }

    // print the total with help of object
    void display_total()
    {
        cout<<total_Customer<<endl;
    }
};
int Customer::total_Customer = 0;
int Customer::total_balance = 0;


int main()
{
  Customer A1("Rohit",1,3000);
  Customer A2("Mohit",2,2000);
  Customer A3("Mohan",3,1000);
  A1.deposit(800);
  A2.withdraw(200);  
   Customer::accessStatic();
}

/*
Using static data member when it is protected, with the help of class. 

*/