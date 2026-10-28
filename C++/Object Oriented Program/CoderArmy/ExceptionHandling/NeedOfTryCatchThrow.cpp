#include<iostream>
#include<exception>
using namespace std;


int main(){
    try {
    int *p = new int[1000000000];  // Put the 0 
    cout<<"Memory allocation is successfull \n";
    delete[]p;
    }
    catch( const /*exception*/bad_alloc &e)   // Exception is an class here e is an Objec. here we bad_alloc  child of exception
    {
        cout<<"Exception Occured due to line 6:"<<e.what();
    }
}