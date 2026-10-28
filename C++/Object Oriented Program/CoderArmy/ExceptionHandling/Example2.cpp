 #include<iostream>.
#include<exception>
using namespace std;

class exception 
{  
    protected:
    string msg;

    public:
    exception(string msg)
    {
        this->msg = msg;
    }
    string what(){
        return msg;
    }
};

class run_error : public exception
{
    public:
    runtime_error(const string &msg): exception(msg);
};
class Customer{
    string name;
    int balance,account_number;

    public:
    Customer(string name, int balance, int account_number){
        this->name = name;
        this->balance =balance;
        this->account_number = account_number;
    };

    void deposit(int amount){
        if(amount<=0)
        // agar throw chalta hai toh niche ka part nahi chalega, aur direct catch mai bhej dega 
        throw runtime_error("Amount should be greater than 0 ");
        
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
            throw runtime_error( "Amount should be  greater than 0 "); // Now Here throw, throw an object so change in catch
        }
        else{
            throw runtime_error( "Your balance is low");
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
    catch ( const runtime_error &e){
        cout<<"Exception Occured:"<<e.what()<<endl;  // e = jo bh exception ka naam 
    }
}
// runtime_erroe is a class which throw , then object is created and throw which is catch by the catch fn in main