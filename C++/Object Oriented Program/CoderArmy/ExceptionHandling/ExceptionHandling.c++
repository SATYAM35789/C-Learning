/* 
 Definition: Exception Handling
Exception is an unexpected problem that arises during the execution of a program and our problem terminates 
suddenly with some error/issues.

There are two types error:-
1. Compile time error: Compile time means that the written code is converted into machine code.(Compilation)
   During this error may can be:-
   Syntex error
2. Run Time error:- when the program is run , output ke waqt . Ex Divided by zero.Or Allocating  memory more   
   Exception is come under this type.
   Jab program run hota hai toh, Waha likh deta Run time error lakin hame pta nahi hota hai ki wo kis typr ka 
   error hai, To know the reason, and in which line it exist. we call it exception handling. 

   Try :- It reprsent a block of code that may through a exception placed inside the try block. 
   It's followed by one or more catch blocks. If an exception occured , try block throw that exception.
   jo bhi part of code exception kar sakta hai usko yaha likhenge. 

   Catch:- It represent a block of code that is executed when a particular exception is thrown from the try block.
   The code to handle the excution is written inside the catch block.
   ye throw ko catch karega

   Throw:- An execution in C++ can be thrown using the throw keyword.When a program encounters a throgh statement, 
   then it immediately terminates the current function and starts finding a matching catch block to handle the 
   thrown exception. Exception ko fakna  

*/
#include<iostream>
using namespace std;
class Customer{
    string name;
    int balance,account_number;

    public:
    Customer(string name, int balance, int account_number){
        this->name = name;
        this->balance =balance;
        this->account_number = account_number;
    };

    // Deposit
    // void deposit(int amount){
    //    if(amount>0){
    //     balance+=amount;
    //     cout<<amount<<"rs  credited successfully \n"<<endl;
    //    }
    //    else{
    //      throw "Amount should be greater than 0 ";
    //    }
    // }

    void deposit(int amount){
        if(amount<=0)
        // agar throw chalta hai toh niche ka part nahi chalega, aur direct catch mai bhej dega 
        throw "Amount should be greater than 0 ";
        
        balance+=amount;
        cout<<amount<<"rs  credited successfully \n"<<endl;  
    }

    // Withdraw
    void withdraw(int amount){
        if(amount>0&&amount<=balance){
            balance-=amount;
            cout<<amount<<"rs debited successfully"<<endl;
        }
        // error handling here
        else if(amount<0)
        {
            throw "Amount should be  greater than 0 ";
        }
        else{
            throw "Your balance is low";
        }
    }
};
int main(){
    Customer C1( "Rohit" , 5000, 10);
    //  Jo hamara error hai woh deposit and withdraw fn mai toh he aa sakta hai so
    try{
      C1.deposit(100);
      C1.withdraw(6000); // There nothing happend in output we what happend to this part of code.
    }
    // because hame pata hai ki throw mai ek string
    // Fayda yah hai ki error hone ke baad bhi program output de raha hai. 
    catch ( const char *e){
        cout<<"Exception Occured:"<<e<<endl;  // e = jo bh exception ka naam 
    }
}