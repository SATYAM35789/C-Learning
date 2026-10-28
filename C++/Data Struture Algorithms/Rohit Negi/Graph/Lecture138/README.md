### Bipartite Graph using BFS  :- 
It is a graph in which the vertices can be divided into two disjoints sets, such that no 2 vertices within the same set are adjecent , In other words, it is a graph in which every edge connects a vertex of one set to a vertex of other set. 
So isme hamare jo verteces present unko do part/set mai batana istarike se ki jisme same set do vertices neighbour nahi hana chahiye. 
Note:- So dono set mai aise vertices aayengi jisme jo neighbour nahi hai. So agar aisa graph bana sakte hai , then we call it as it is Biparted Graph. Aur ye dono set ke edges apas mai connected hai. 

On a particular node, ek question puchhenge kya isko set1 mai rakhe then check karenge kya new node set1 ka neighbour hai if no then set 1 mai rakh do if yes then set 2 mai rakh do and vice-versa. 
To solve these problem we have 2 color algorithum. 
Kya ham apne graph  ko do color mai part mai kar sakte hai, aise ki same color adjecent or neighbour mai nahi hona chahiye, ye sirf naming convection ho sakta , set ko set1 aur set2 na bol kar Red aur blue, do color mai kar diye. So basically isme apne parent(pahle wala node) ko check kar rahe hai wo kaisa hai red ya blue, if ed then child blue and vice-versa. (Graph may be undirected Graph so how can we got the info about parent aur pahle wala node.)
Note :- Agar circle present hai aur odd length ka hai, then  wo Biparted nahi ho sakta. 
1. Agar present node Red hai then iske neighbour blue honge and so on. 
2. Edge case :- Jab node ke bagal ek side red hai dusre side blue then ham present node ko koi bhi color nahi de sakte and ye Biparted Graph nahi honga. 

So agar hamko graph ko color karna hai then hamko graph ko travserse karna honga , jiske liye hum BFS ya DFS use karte hai. 
BFS :- So starting node ko koi bhi color de do, phir is node ko queue mai daalo , bahar nikalo , iske neighbour ko ander dalo aur dursa color de do, usko bhi queue mai daalo and do so on. 
Note :- Queue mai us neighbour ko daalna hai jo color nahi hai.

Color vector :- So ham ek array le lenge, jisme  0 represent's red and 1 represent's blue. and -1 represent ki abhi koi color nahi kiye hai. 
Note :- Agar node par hai toh apne neighbour ke color ko check karo if same then cannot be Biparted if not same then give another(different from neighbour) color and it can be biparted check for further. 

Steps :- 
1. It will lool at its all neighbour
-> If color is not assignied then assignes color to them , khud ke opposiye wala. and push the neighbour into queue. 
-> If already color assigned then check, Is all the   neighbour having same color or different so if different then not biparted graph. 

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int v, vector<int> adj[])
{
    vector<int> color(v, -1);
    queue<int> q;

    for (int i = 0; i < v; i++) // Disconnected Node ko bhi check karna
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 0;

            while (q.empty())
            {
                int node = q.front();
                q.pop();

                for (int j = 0; j < adj[node].size(); j++)
                {
                    // color not assigned to them
                    if (color[adj[node][j]] == -1)
                    {
                        color[adj[node][j]] = (color[node] + 1) % 2; // (color[node]+1)%2 :- Iski help se ham neighbour mai different color daal payenge
                        q.push(adj[node][j]);
                    }
                    // Color is already assigned
                    else
                    {
                        if (color[node] == color[adj[node][j]])
                            return 0; //   not a Bipartite Graph
                    }
                }
            }
        }
    }

    return 1; // Bipartite graph hai
}

int main() 
{
    // Case 1: Bipartite Graph (Square: 0-1-2-3-0)
    int v1 = 4;
    vector<int> adj1[v1];
    adj1[0] = {1, 3};
    adj1[1] = {0, 2};
    adj1[2] = {1, 3};
    adj1[3] = {0, 2};

    if(isBipartite(v1, adj1))
        cout << "Graph 1 is Bipartite." << endl;
    else
        cout << "Graph 1 is NOT Bipartite." << endl;

    // Case 2: Non-Bipartite Graph (Triangle: 0-1-2-0)
    int v2 = 3;
    vector<int> adj2[v2];
    adj2[0] = {1, 2};
    adj2[1] = {0, 2};
    adj2[2] = {0, 1};

    if(isBipartite(v2, adj2))
        cout << "Graph 2 is Bipartite." << endl;
    else
        cout << "Graph 2 is NOT Bipartite." << endl;

    return 0;
}
```

Time ans Space Complexity :- O(V+E) O(V)

### Bipartite Graph using DFS:- 
DFS approch ye pahle ek raste ko traverse karta hai jata hai, jab tak wo khatam nahi ho jata, phir return hota hai, so ham traverse karte hue apne node ko uske parent se different bharte jayenge, same tarike se wapas bhi aayenge aur next route ke traverse karte jayenge, while traversing agar next node already colored hai aur usko same color mila hua hai then it is not bipartite graph nahi hai wo return karta jayenga apne parent ko and so on till starting node ko bhi same message nahi pahuch jata. 
Note :- If not bipartite graph find in any route then hamko ab yahi return karna hai ki ye biparted graph  nahi hai. 

Code Part :- 
1. ISBiparted() bool type ka, parameter : int type ka node, adj naam ka array jo store karega vector int type ke value, color vector int type ka as reference
2. Ab neighbour ko ek ek karke traverse karte hai, ek for loop j=0 se j less then adj of node ke size itna
   1. Agar color assigned nahi hai, if(color[adj[node][j]]==-1) then 
      1. color[adj[node][j]] mai different color daal do
      2. IsBiparted ko call kardo next neighbour ke liye. Agar ye 0 atta hai then return kardo 0 ko. 
   2. Agar neighbour ko color mila hua hai,
       1. Agar color same hai node ka apne neighbour se, if(color[node]== color[adj[node][j]]) then return 0 , which means ki bipartite graph nahi hai. 
       2.  Agar different hai color then , wo part already visited hai waha jane ki zarurat nahi hai

Time and Space Complexity :- same. 

Code Implementation :- 
```
#include <iostream>
#include <vector>
using namespace std;

bool checkBip(int node, vector<int> adj[], vector<int> &color)
{
    // look at each neighbour
    for (int j = 0; j < adj[node].size(); j++)
    {
        // Color is not assigned to the neighnour
        if (color[adj[node][j]] == -1)
        {
            color[adj[node][j]] = (color[node] + 1) % 2;
            if (!checkBip(adj[node][j], adj, color)) // agar 1 return karega tabhi next node ko dekhenge nahi toh return back karte jao
                return 0;
        }

        // Color already assigned hai
        else
        {
            // Color same neighbour ka
            if (color[node] == color[adj[node][j]])
                return 0;

            // agar color same nahi then wo part toh visited waha jane ki zarurat nahi hai
        }
    } // agar for loop return 0 nahi karta hai, then ye bipartite hai
    return 1;
}

bool isBipartite(int v, vector<int> adj[])
{
    vector<int> color(v, -1);

    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (checkBip(i, adj, color) == 0)
                return 0;
        }
    }
    return 1;
}

int main()
{
    // Test Case 1: Bipartite Graph (0-1, 1-2, 2-3, 3-0) -> Even Cycle
    int v1 = 4;
    vector<int> adj1[v1];
    adj1[0] = {1, 3};
    adj1[1] = {0, 2};
    adj1[2] = {1, 3};
    adj1[3] = {0, 2};

    if(isBipartite(v1, adj1))
        cout << "Graph 1 is Bipartite." << endl;
    else
        cout << "Graph 1 is NOT Bipartite." << endl;

    // Test Case 2: Non-Bipartite Graph (Triangle: 0-1, 1-2, 2-0) -> Odd Cycle
    int v2 = 3;
    vector<int> adj2[v2];
    adj2[0] = {1, 2};
    adj2[1] = {0, 2};
    adj2[2] = {0, 1};

    if(isBipartite(v2, adj2))
        cout << "Graph 2 is Bipartite." << endl;
    else
        cout << "Graph 2 is NOT Bipartite." << endl;

    return 0;
}
```


Real World use cases of Bipartite graph :-
1. Cancer. 
2. Recommendation system :- Different user hai, agar unka choices similar hai dusre user se than , then ist user ke sare interest ko user2 ko shoe karwa sakte hai. 
3. Stable Mairrage problem :- 5 ladke hai 5 ladikiya, shadi karane se pahle sabki pasand puchh li , kon kon pasand hai, unko so hamko ye confirm karna hoga ki unki shadi tute n, ho jaye jo unko pasand hai. 
