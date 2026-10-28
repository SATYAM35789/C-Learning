#include <iostream>
using namespace std;

void fun3(int n)
{
    // Base Case
    if (n == 0)
    {
        cout << "Happy Birthday\n";
        return;
    }
    cout << n << "days left for birthday";
    fun3(n - 1);
}

int main()
{
    int n = 5;

    // // Iterative approch
    // for(int i=0;i<n;i++)
    // cout<<i<<"days left for birthday\n";
    // cout<<"Happy Birthday\n"

    // //  Using  Function :-
    // fun3(3);
    // fun2(2);
    // fun1(1);
    // fun0(0);

    // // Sirf ek function call mai, solution, iske liye defined function se uske next fun call karna hoga
    // fun3(3);

    //  Recursive Method :-
    fun3(3);
}