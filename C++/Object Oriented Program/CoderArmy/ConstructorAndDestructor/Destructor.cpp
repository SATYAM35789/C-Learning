/*Destructor
It is an instance member function that is invoked automatically whenever an object is going to be destroyed.
It is a last fn that is going to be called before an object is destroyed.
Destructor released the dynamically allocated memory. JO bhi resorces dynamically mili hai ise. Not delete the object.  
class Customer
{
   string name;
   int *balance;

   Customer(string name, int bal)
   {
      this->name=name;
      balance = New int;
      * balance = bal;
   }
   ~Customer()
   {
      cout<<"name";
   }
}
int main(){
   Customer A1("Satyam",1000);
}
*/
#include<iostream>
using namespace std;
class Customer
{
   string name;
   int *data;
   public:
   
   Customer(string name , int da)
   {
      this->name=name;
      data = new int;
      *data = da;
   }
   ~Customer()
   {
      cout<<name;
   }
};
int main(){
   Customer A1("satyam",10);

}