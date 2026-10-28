#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    // One way to solve the error when the dinominator is 0 if laga lo

    try{

    if(b==0)
    throw "Divide by 0 is not Possible";
    int c = a/b;
    cout<<c<<endl;   
    }
    
    // Try ke baad hamesha
    catch( const char *e){
       cout<<"Exception is Ouccured:"<<e<<endl;
    }
    
}