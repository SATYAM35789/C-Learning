#include<iostream>
using namespace std;

template<typename X>
class Array
{
    private:
       X arr[10];
       int size;
    public:
       Array(){
        size=10;

       }
       void insert(int index, X value)
       {
        arr[index]=value;
       }
       X getValue( int index)
       {
        return arr[index];
       }


};

// While generalizing we got error at creating the object , we have to specify the the datatype of the object first.
// Specify karne ke liye classname aur object ke bech mai angular bracket<> use karenge uske ander datatype likh denge  
int main()
{   
    Array <int> o1;
    Array <float> o2;
    o1.insert(0,10);
    o1.insert(1,20);
    o2.insert(5.3,10.1);
    cout<<endl;

    return 0;
}