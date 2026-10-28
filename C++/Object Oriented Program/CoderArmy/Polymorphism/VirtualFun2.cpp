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
class Cat : public Animal
{
    public:
    void speak()
    {
        cout<<"Miyao"<<endl;
    }
    
};
int main()
{
    // Animal *p;
    // p = new Dog();
    // p->speak();

    // // We can got the result of above
    // Dog d1;
    // d1.speak();

    Animal *p;
    vector<Animal*>animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Animal());
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    // Vector mai jiska bhi address store kara rakha hai usko bahar nikalo aur batao wo karta kya hai?
    // Kaise karenge  TypeCasting. Address nikalenge aur dekhenge waha kya present hai, Dog/Cat/Animal Compair
    for(int i=0;i<animals.size;i++) 
    {
        p= animals[i];
        p->speak();
    }
}