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
    Customer(string name, int account_number)
    {
        this->name=name;
        this->account_number=account_number;
        balance= 3455;

    }
    // Inline Constructor
    inline Customer(string a, int b, int c): name(a),account_number(b),balance(c)
    {
        cout<<"No. of parameter inlized in Inline constructor, no other constructor should have that no of parameter"<<endl;
    }

    void Dispaly()
    {
        cout<<name<<" "<<account_number<<" "<<balance<<endl;
    }
};
int main()
{
    Customer A1,A2;
    A1.Dispaly();
    A2.Dispaly();
    Customer A3("Suhani", 20);
    A3.Dispaly();
    Customer A4("Tamanna", 2054,900);
    A4.Dispaly();
}