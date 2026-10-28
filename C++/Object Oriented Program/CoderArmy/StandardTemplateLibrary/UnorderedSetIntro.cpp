/* Unordered set:
1. It store the unique element.
2. It store the data in unordered way. 
3. Important:- Search, insert, delete in order of O(1), which is most important tool. 
Application:- Instagram userid combination.
Implementation:- Hashing.
The order will not same as we entered in it.
We can use same property , we use earlier.   
*/
#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_set<int>s;
    s.insert(10);
    s.insert(20);
    s.insert(15);
    s.insert(30);
    s.insert(11);
    s.insert(10);

    for(auto it=s.begin(); it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
}