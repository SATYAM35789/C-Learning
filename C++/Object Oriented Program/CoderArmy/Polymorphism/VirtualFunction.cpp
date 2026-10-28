/* Virtual function

class Animal
{
  public:
 virtual void speak()   // By using Virtual we specify that we are going use that one run time 
  {
    cout<<"Hu Hu"<<endl;
  }

};
  class Dog: public Animal
  {
    public:
    void speak()
    {
      cout<<"Bark"<<endl;
    }
  };
  int main()
  {
     Animal *p;
     p = new dog(); // dog ka ek pointer create hoga aur uske address ko p ke ander store karwa do. 
     p->speak(); // Here we want to print the bark But we are geting "Hu Hu "  Because it has been decided at compile time To go with that fun.
    // Here we wanted that if we have created the Dog object then dog speak() fun would access. 
  }
Question: Why we created the Animal pointing pointer if we want access the dog. 
Question: Why we have written the Virtual at Animal not in the derived class. 
*/
#include<iostream>
using namespace std;

class Animal
{
    public:
    virtual void speak()
    {
        cout<<"Hu Hu"<<endl;
    }
};
class Dog : public Animal
{
    public:
    void speak()
    {
        cout<<"Bark"<<endl;
    }
    void roti()
    {
        cout<<"Hello\n";
    }
};
int main()
{
    Animal *p;
    p = new Dog();
    p->speak();

    // We can got the result of above
    Dog d1;
    d1.speak();
}
/*
  P ek pointer hai jo point kar raha hai p type ke pointer ko. P ko pata hai ki wo sirf class Animal ko hi point kar 
  sakta hai. roti() is not present in Animal it cannot access. 

  Rule: Parent class ka jo pointer hai wo apne child class ke object ko store karwa sakta hai. 

*/