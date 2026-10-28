/*  Constructor:-
It is a special function that is invoked automatically at the time of object creation. 
The name of constructor should be same as class name. 
It doesnot have any return type.
It is used to initialize the value.
example:
class Customer
{
    string name ;
    int account_number;
    int balance;

    Customer()   Default constructor
    {
        cout<<"Contructor is Called"<<endl;
    }
    Customer(string a, int b , int c)   // Parametrized Constructor
    {   
    }
    Customer(string name, int account_number , int balance)   // Parametrized Constructor
    {   
    }
};
int main()
{
   Customer A1; A1 likhte object form ho jayega means A naam ka box jisme name, accoubt_number, balance jaise 
   chote- chote dibe box A ke under aa jayega.(apne aap call ho jata hai) 
   value intialize means value variable ko koi naam dena.
   Object ko object banata hai by intializing the value.
   Customer A2("Rohit", 123,09866); 
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
    Customer( int a,string b, int c)
    {
        cout<<"Third constructor is callled"<<endl;
        name= b;
        account_number=a;
        balance = c;
    }
    Customer(string name, int account_number)
    {
        this->name=name;
        this->account_number=account_number;
        balance= 3455;

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
    Customer A3("Satyam",20,56657);
    A3.Dispaly();
    Customer A4(456,"Videsh",800);
    A4.Dispaly();
    Customer A5("S", 20);
    A5.Dispaly();
}