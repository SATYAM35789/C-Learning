/*  Static Cast
  1. Capable enogh that can perform all the conversions carried out by the implicit cast.
  2. Compiletime casting

  syntex:
  static_cast <new_data_type> (expressions);

*/
#include<iostream>
using namespace std;
int main()
{
    double multiplication = 3.6*1.7 ; 
    int result; 
    result = static_cast <int> (multiplication) ;   // This is done by compiler but doing this because to check it is implicit or not.
    cout<<" Result "<< result<<endl;  // This result is type of implicit conversion. 
    return 0;
}