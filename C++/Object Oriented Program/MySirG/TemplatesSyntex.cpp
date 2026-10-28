#include<iostream>
using namespace std;
/*Syntex of templates
 With help of templates keyword :
 1. Function Templates(Generic Function) :- In angular bracket(<>), we can write typename/class use as same perpose.
    Typename ke baad jo bhi likh rahe hai, wo(X) store karega jo bhi datatype as argument hum pass kar rahe during calling fun hai.  
    X is going to represent the datatype we pass/ supply during calling the function.
    Bahar X because jis type ka hum value return kar rahe hai us type ka datatype likh denge
    Note:
    We can also add different place holder using comma if we want different type to datatype to pass in same function. 
 2. Class Templates:-

*/
// #1
template<typename X>
X big( X a, X b)
{
    if(a>b)
       return a;

    else
       return b;
}
int main()
{
    cout<<big(3,4)<<endl;
    cout<<big(4.5,5.8)<<endl;  // X ka matlab double (by default (4.5))
    return 0;

}