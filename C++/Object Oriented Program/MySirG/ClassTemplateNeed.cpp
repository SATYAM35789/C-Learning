/* #2
  THis class can array in which 10 values of integer can be done. Memory flexibilty ke liye DMA aur new keyword ka
  istamal kar sakte hai. 
  Problem:- Agar mai chahta hu ki array mai interger ke badle float value rakhna chahta hu . toh phir?
   Toh phir ye class kaam nahi aayegi hame dusra class banana padega. same class with different datatype. 

   Solution is Generalizing the Class. 
  
*/
#include<iostream>
using namespace std;

class Array
{
    private:
       int arr[10];
       int size;
    public:
       Array(){
        size=10;

       }
       void insert(int index, int value)
       {
        arr[index]=value;
       }
       int getValue( int index)
       {
        return arr[index];
       }


};

int main()
{
    Array o1;
    o1.insert(0,10);
    o1.insert(1,20);

    return 0;
}