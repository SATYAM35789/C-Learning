/* Inheritance:- The capability of a class to derive property and charecterstices from another class. 
        Access ->     Outsideside-> Within Class -> Derived Class 
   Public:-               yes          yes            yes
   Protected:-           not             yes          yes
   Private:-            not             yes            No

   Access:- means us location par jake us ko delete/update. 
   Syntex of child class:-  classKeyword ChildClass: AccessSpecifier BaseClass;'

   Priority which access specifier leads
   Private >  Protected >  Public

   Base       Child         Output
   Public     public        Public
   Public     Protected     Protected
   Public     private       Private
   Protected  public        Protected
   Protected  Protected     Protected
   Protected  Private       private
*/
class Human
{
    private:
      int a;
    protected:
      int b;
    public:
      int c;

    // Seeing is we can able to access the datamember within  the class
    void fun()
    {
        a=10;
        b=20;
        c=30;
    }
};
int main()
{
    Human Rohit;
    Rohit.c = 10;    // C is defined in Public so we able to access. 

    Rohit.fun();

}