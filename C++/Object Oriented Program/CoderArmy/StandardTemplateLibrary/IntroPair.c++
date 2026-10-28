/*
Standaerd Template Libraray:- is a powerful tool. 
for ex Searching an element in unsorted array is O(n) an in sorted array is log(n). But we find in constant time 
by using STL. 
STL: is not part of C++. Programmer introduced this topic in a c++. 
Pair:- Pair is container that store the data. Kisi do chhej ko sathg mai rakh do. 
syntex: pair<type1, type2>name_of_pair;
 Example:-  Rohit, 30  want it to be pair. 
            pair<string, int>P;  // Declaration
               P=make_pair(" Rohit",30);  // 1st method to store the data.
               
               P.first="Rphit";          // 2nd method to store the data. 
               P.second=30;

Pair may implement with the class.
example   
class Add
{
    public:
    string first;
    int second;
};
int main()
{
  Add P;
  P.first = "Rohit"
  P.second = 30;
}
*/ 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    pair<string, int>p;
    // Two method
    //p = make_pair("Rohit",30);
    p.first="Rohit";
    p.second=30;
    cout<<p.first<<" "<<p.second<<endl;
}