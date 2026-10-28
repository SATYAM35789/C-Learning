## Circle of String :- 
### Understanding the problem :- 
So Is question mai kuchh string diya hua hai, ye bol raha hai ki hamko iska chain banana hai, agar chain ban jata hai toh yes return kardo. Example ab bc cd da. 

Chain banane ka condition :- Agar ek string ka last character dusre string ka start se match karta hai then chain ban sakta hai. Chian - Example ab bc cd da. 
Not Circle formed Example :- abc-cde-edf

Note :- Hamare circle ka sare string part hone chahiye. Example :- abc-cde-eapd-dpec-cde we can see in this example that ki abc is not the part of circke so we return No. 

Another Example :- abad, dabc, cdea, akrt, trdd, dcka 
Chaining the string :- abad-dcka-akrt-trdd-dabc-cdea-abad Circle Formed.

### What a solution can be?
So ham apne example ko dekhne ke baad ye kah sakte hai ki, ek string ke pass multiple string ho sakte hai jiske sath wo chain bana sakta hai, so sayad ek string choose kare toh ans aa jaye aur na bhi aaye ye bhi ho sakta hai. Choose kya karna hai, is choose ko dur karne ke liye ham node bana rahe hai. 

So ab ek string ko ek node ke tarah treat karte hai, Creating a node so that ki circle form kar paaye, So jo chain condition ki satisfy kar raha hai us se connectivity form karlo. 
like abad -> dabc (Arrow ke sath). So agar end of string barabar hai start of string se then end of string se arrow niklega aur start of string par jayega. 

Node Connectivity ke baad hamko ek aisa cycle khojna hai jo sare node ko visit karde exactly once.
Hamiltonian Cycle ka concept :- Har node exactly ek baar visit karna hai, aur hamare pass ek node hona chahiye jo end node se starting par jaye. 
So isme visit kar rahe hote hai, jo visit ho chuka hoga waha nahi jayenge aue aage jate jayenge tab tak sare node visit nahi ho jate, So ab last node visit hone ke baad iske pass ek edge hona chahiye jo starting node par ja raha ho. 
Time Complexity :- nfactorial :- n!  : sare permutation and combination try karne padte hai. Kyuki sari node se cycle formed karna hota hai. So yaha ek hamiltonian cycle. And yaha ham ek path ko multiple time visit kar rahe hai. 

2nd Approch :- 
Agar koi string diya hua hai, so hamko us string sirf starting aur ending character se fark padta hai. So ab jo first character hai string ka wahi us string ka naam hoga, aisa isliye kyuki while connecting to another string first character ko he dekh rahe hai kya wo same jo usse connnect kar raha hai. Last Character string  ka bata raha hai ki last character par chale jao agar us character se string exist karta hai toh. 
ex ac :- a: String ka naam hai , c: go to this sting . So is chiz ko ham aise represent kar sakte hai :- ac =  a -> c

Example :- abad-dcka-akrt-trdd-dabc-cdea-abad
1. ad-da-at-td-dc-ca-ad
2. a -> d
   d -> a
   a -> t
   t -> d
   d -> c
   c -> a

3  a -> d -> a -> t -> d -> c -> a  Answer

note :- Start aur end character uthao aur edge bana do. So toh ab Hank0 Euclarian Ckt check karlo ans mil jayega hamko.  
2. So hamne jo edges banai hai usko wo string ko toh he so kar rahi agar ha inko exactly ek baar visit kar rahe hai aur jaha se start kar rahe hai waha aa pa rahe hai then it isko Eclarian circuit bolte hai. 

#### Note:- Iske pahle approch mai hamne apne string as node mai change kar diya tha lakin iss approch mai apne string ko Edge mai change kar de rahe hai.

Pseudo Code
1. Create edges between first and last character of string. 
2. Eluerian CKT present hai, then ans yes hoga if not then No.
   Directed Graph mai Eluerian ckt :- 1. InDegree == OutDegree 2. DFS : All the edges are the part of single connected component. 

1. -> apne string ko 0,1,2 ke form mai convert kar denge taaki hamare liye easy ho jaye. 

Code Implementation
```
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited);
    }
}

int isCircle(int n, vector<string> A)
{
    // Edges create karna
    // Adjecency list
    vector<int> adj[26]; // 26 : small letter ke string hai and a=0,b=1,... z=25. So itne he combination ban sakte hai.
    vector<int> InDeg(26, 0);
    vector<int> OutDeg(26, 0);
    for (int i = 0; i < n; i++)
    {
        string temp = A[i];
        int u = temp[0] - 'a';               // temp ke first charcter  store kar rahe hai ,
        int v = temp[temp.size() - 1] - 'a'; // last string char ko stored kar rahe hai
        adj[temp[u]].push_back(v);

        // Find Indegree and OutDegree
        OutDeg[u]++;
        InDeg[v]++;
    }

    // Eluerian Ckr exist or not
    // Find Indegree and OutDegree

    for (int i = 0; i < 26; i++)
    {
        if (InDeg[i] != OutDeg[i])
            return 0; // Not Eluerian ckt
    }

    //  ALL the edges are part of one component
    vector<bool> visited(26, 0);
    int node = A[0][0] - 'a';
    DFS(node, adj, visited); // A[0][0] :- A[0] means iske first string A[0][0] A ka first string, and string first character

    // Indegree exist but not visited
    for (int i = 0; i < 26; i++)
    {
        if (InDeg[i] && !visited[i]) // InDeg or OutDeg kuchh bhi le sakte hai
            return 0;
    }

    return 1;
}

int main() {
    vector<string> A = {"abc", "bcd", "cda"};
    if (isCircle(3, A))
        cout << "Yes, it forms a circle!" << endl;
    else
        cout << "No circle possible." << endl;
    return 0;
}
```

Time Complexity :- V+E
Space Complexity :- Constant