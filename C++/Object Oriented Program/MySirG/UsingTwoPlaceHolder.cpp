#include<iostream>
using namespace std;

template<typename X , typename Y>
X big( X a, Y b)
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
    cout<<big(4.5,5)<<endl;
    return 0;

}