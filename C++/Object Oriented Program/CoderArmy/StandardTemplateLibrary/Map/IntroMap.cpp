/* Map
1. It store the value in key-value pair. where key is unique always and value may be duplicates. 
2. It just like an array where the index of the array may be modified. Means map ka jo index hai wo key ho jati hai 
   aur hum usko apne according rakh sakta hu. 
3. In sorted form on the basis of key. 
4. Search, insert and insert will ouccur in log(n) time. 
5. Implementation is not the basis of array, because the opertion like insertion, not take log(n) time. 
   Its implmentation is on othebased it able to give the property of the array. 
6.Implementation by AVL tree.
  Physically it seems like Array but internally it is AVL tree. Or red black tree. 
7.Application:- On instagram while logging it asked id and password. The process of matching or confirming that 
  you can login .
  pmap store the count of the value.  
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Syntex:- map<keydatatype,vluedatatype>mapname;
int main()
{
    map<int,int>m;
    m.insert(make_pair(20,30));
    m.insert(make_pair(30,310));
    m.insert(make_pair(40,30));
    m.insert(make_pair(20,230));
    m.insert(make_pair(50,30));
    // Another way to insert and it can update the value. 
    m[100]= 60;
    m[20]=70;  // Agar present nahi hai to create kar denga, if present than it update the value. 

    // Print
    for(auto it = m.begin(); it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl; // .first karke hum key ko access kar sakte hai, .second se hum value ko access kar sakte hai
    }
    cout<<endl;
    cout<<m[200]; // here 200 is key , yaha jo output  hai wo 0 hai , yaha matlab ye ho sakta hai ki is key par 0 hai
    // To solve above problem we have. 
    if(m.count(60))
    cout<<m[60]<<" ";  // Yaha agr value nahi toh kuchh nahi print hoga lakin uper 0 orint ho raha tha. 

    // To delete
    m.erase(20);
}