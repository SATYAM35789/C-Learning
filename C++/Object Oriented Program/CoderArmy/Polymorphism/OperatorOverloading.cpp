/*
Operator Overloading:- same operator doing different work. 
class complex
{
  int real, imag;
  public:
  complex(int real, int imag)
  {
    this->real=real;
    this->imag= imag;
  }
  void display()
  {
     cout<<real<<"+i"<<imag<<endl;
  }
  // Here C1 call the + function and C2 is pass as the parameter. 
  complex operator+( complex &c)
  {
    complex ans;
    ans.real =real + c.real;
    ans.img = img +  c.imag;
    return ans;
  }
};
int main()
{
   complex C1(3,2);
   complex C2(4,6);
   complex C3=C1+C2; this are the two object (user defined data type object) so addition for this not possible. So here we use operator overloading. 
   C3.display(); using this operator as a function. 
  
  return 0;
}
*/
#include<iostream>
using namespace std;

class complex
{
  int real, imag;
  public:
  complex()
  {

  }
  complex(int real, int imag)
  {
    this->real=real;
    this->imag= imag;
  }
  void display()
  {
     cout<<real<<"+i"<<imag<<endl;
  }
  complex operator +(complex &C)
  {
     complex ans;
     ans.real = real+ C.real;
     ans.imag = imag + C.imag;

     return ans;
  }


};

int main()
{
   complex C1(3,4);
   complex C2(4,6);

   complex C3 = C1 + C2;  // C1.fun(C2)
   C3.display();
}
