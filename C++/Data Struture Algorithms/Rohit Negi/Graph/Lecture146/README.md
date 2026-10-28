### Floyd Worshall Algorithum :- 
UseCase:- Multi source shortest path algorithum. Sare node ka sare node se shortest path nikalne hai. So first we see the Floyd worshall algorthum,And their time and space complexity. And then we see if we do same with dijkstra or Bellmon ford then what will be there complexity. 
Condition :- So is algorithum ko ham sirf directed graph ke uppar laga sakte hai, So weight can be +ve and -ve anything can be exist.  
Warshal :- A->B, B->C then B->C , agar A aur B ka relation hai, B aur C ka relation hai then B aur C ka relation hoga. Transitivity rule. So ye path ko find karega. 
Floyd :- Chhote path ko update karna. Aur ye us path ke calculations agar chhota hai pahle wale se then usko update kar dega. 

So graph ka direct raste ka cost toh pata hai hamko, so ham ek dusre raste ke through bhi chack  kar rahe agar cost kam pad raha hai toh update kar de rahe apne cost ko. Means ki ek intermediate node ke through ja raha hai. 
Intermediate node :- Select each node as Intermediate node. Ek ek kareke sare node ko intermediate node choose karo. 
A-C(Direct path)  lakin A-B, B->C exist karta hai then B intermediate node kahlata hai. 
Note :- Agar kisi ko intermediate node bana rahe hai then ham try karenge ki wo node jitne ka bhi intermediate ban sakte sare possibility ko try kar lenge. Means ki ham ab jaha bhi jayenge usi intermediate node ke through jayenge. Is process ke baad hamko answer mil jayega. Node ko as city bhi treat kar sakte hai. 

Example :- Ek graph hai with 4 vertex and 7 edges. Directed graph hai with weight so uske accoding apne adjecency matrix mai full kar denge, Same to same ko 0 se, else jaha nahi ja sakte usko intmax or infinite se. path(i,j)= min(path(i,j), path(i,k)+path(k+j))
Note : Matrix Filling
1. Jis bhi node ko intermediate node choose kar rahe hai, so is baat ka koi matlab nahi hai ki jis node par hai us node par jao means ki 0 se 0 par jao means ki ham kahi ja he nahi rahe or answer change nahi ho raha hai so as reseult intermediate node ke col aur row ka sare element ko ignore aur waise ke waise note kar lenge. like 0 node as intermediate so (00) oth row and 0th col. And digonal ko bhi waise ke waise likh denge. Ex (2,0) 2->0 and 0->0 = (2,0). 
2. Other case mai path(i,j)= min(path(i,j), path(i,k)+path(k+j)). 
3. No. of matrix  (V+1) honge, ek matrix for normal edges aur vertex ke info note kar raha hoga and V matrix for the intermediate node making to all the vertex. 
4. And jis node ko intermediate bana liye hai, usko as intermediate node use kar sakte agar usko include karne se chhota path milta hai toh. 
5. Ordering of intermediate node change kar denge toh hamare ans pad koi fark nahi padega. So kisi ko bhi intermediate node bana le transitivity hamko ans lakar de he degi. 

Kisi bhi intermediate node, ka 3 Case hoga
1. Passing through the intermediate node
2. Directly involvement of intermediate node
3. Intermediate  node not connected, means ki ham pahuch he nahi sakte hai. 

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
//  -1 show that ki unke bich mai edge exist nahi karti
void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size(); // vertex kitna hone wala hai uska infomation
    for(int i=0;i<n;i++)
    for(int j=0; j<n;j++)
    if(matrix[i][j]==-1)
    matrix[i][j] = INT_MAX; 

    //  Floyd Waeshall Algorithum 
    for(int k=0;k<n;k++)  // selecting the intermediate node one bby one
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        // Edge case :- matrix[i][k] / matrix[k][j])  inme me se koi bhi INT_MAX hua toh usko ignore kardo
        if(matrix[i][k] == INT_MAX || matrix[k][j]== INT_MAX)
        continue;

        matrix[i][j] = min(matrix[i][j] , matrix[i][k]+ matrix[k][j]);
    }

    // So uppar jaha -1 present tha usko INT_max banaya tha, So ab koi abhi INT_MAX hai toh usko wapas -1 ke form he return karna hai
    for(int i=0;i<n;i++)
    for(int j=0; j<n;j++)
    if(matrix[i][j]==INT_MAX)
    matrix[i][j] = -1; 
}

```

Time Complexity :- 
O(Ncube) -> O(Vcube)
Space Complexity :- O(1)

How it detecting the -ve cycle :- 
So agar -ve cycle present hai toh , hamare diagonal, matrix mai tab ham bol denge ki -ve cycle present hai. 

So if hamare pass +ve weight hai toh kya ham Dijkstra lagaye ya Floyd Warshall use kare?
Dijkstra
1. Sparse ElogV fo single node, So v node ke liye EVlogV = vsqlogV
2. Dense  Vsq for single source so V node ke liye O(Vcube)

Floy- Warshall ko kyu jayada use karte hai :- 
1. Kyuki iska Implementation bahut easy hai. 
2. So we not need to worry about the type of graph sparse or dense. 

Routing Table :- 
Here we have the option to use the Floyd-Warshall and Dijkstra Algorithum ? Here we can prefer the dijkstra algorithum  we prefer this because there very low no. edges. 
