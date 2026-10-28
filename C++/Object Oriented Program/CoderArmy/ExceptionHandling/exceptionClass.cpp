/* There are two types of error handling 
1. Built in Error handling:-
    Main are std:bad_alloc  , std:runtime_error
2. User defined:-
    
*/

#include<iostream>
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
int main(){
    try {
    int *p = new int[1000000000];  // Put the 0 
    cout<<"Memory allocation is successfull \n";
    delete[]p;
    }
    catch( const bad_alloc &e)   // Exception is an class here is an Object
    {
        cout<<"Exception Occured due to line 6:"<<e.what();
    }
}