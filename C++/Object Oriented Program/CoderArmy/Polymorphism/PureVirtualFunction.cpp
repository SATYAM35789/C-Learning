/*  Pure virtual Functiion is also known as Absract class.

*/
#include<iostream>
using namespace std;

class Animal
{
    public:
    virtual void speak()= 0;  // Jiska koi bhi object create n Ho.  
    // Using this we confirm that we unable to create object of this class. 
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
}
/* Pure function should be present in every deived class. 
*/