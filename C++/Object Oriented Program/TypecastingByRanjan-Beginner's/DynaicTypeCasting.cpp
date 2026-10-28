/*  Dynamic Cast
1. Dynamic_cast is a runtime cast opertor used to perform  conversion  of one type variable to another only on 
   class pointer and references. 
2. It means it check the valid casting of the variables at the run time , and if the casting fails, it returns a
   NULL value 

Syntex: 
dynamic_cast <new_data_type> (expression);

*/
#include<iostream>
using namespace std;

class Base
{
   string name ; 
};
class derived : public Base
{
   virtual void message(){

   }

};
int main()
{
   Base b; 
   derived d;

   Base *p = new derived;
   derived *pd = dynamic_cast <derived *> ( p ); // error because base to derived conversion are not allowed with dynamic
// With dynamic casting unless the base class is polymorphic. 
   if(pd != NULL){
      cout<<"Dynamic casting is done successfully"<<endl;
   }
   else{
      cout<<"Dynamic casting is failed"<<endl;
   }
   return 0;
}