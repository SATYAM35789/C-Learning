### Strongly Connected Component :- 
In a directed graph, SCC is a subset of vertices where every vertex in the subset is reachable from every other vertex in the same subset by traversing  the directed edges. 
So ek diected graph diya hoga jisme, ek sabse bada subset hoga jisme har ek vertex se har ek vertex par ja sakte hai then then usko bolenge SCC.
So isme do tarah ke question puch jate hai
1. Count batao ki aise kitne SCC ho sakte hai
2. Print that Component's

So agar ek node se dusre node ja pa rahe hai aur dusre node se wapas pahle wale node par aa par rahe in directed graph then it is SCC. Ab ham in dono nodes ko bol sakte hai ki ye SCC hai. Simple to say that afar directed node loop form kar raha hai then wo cycle as subset of SCC kah sakte hai. 
Note :- Single node ko as SCC manege as single node connected graph se then single node se single node par toh ja he sakte hai. Ham apne component ko kisi bhi order mai likh sakte hai agar sorted mai nahi bola hai toh print karte waqat. 

How can we solve this problem?
Sirf simple DFS traversing karne se koi fayda nahi hai hamara ans find nahi kar pa rahe , ek baar mai sabko traverse kar de rahe hai. So is type ke problem ko solve karne  ke liye koi n koi pattern find karne ki kosis kya karo, Isko sovle karte hai Kosaraju Algorithum ke help se. 

So jab ham DFS traversing kar rahe the tab Ek component se dusre component mai chale ja rahe the jiske wajah se pura traversing ho ja rahi thi, lakin ham kuchh aisa karna hoga ki ham tab SCC1 ko pura traverse na karle tab tak SCC2 mai n ja paaye. So jo edge, SCC1 ko SCC2 se connect kar rahi hai uska ulta karde tab ham SCC1 se SCC2 par nahi ja payenge. 

So ab Detailing of Strongly Connected Component mai ghuste hai?
Note :- So agar ham kis bhi SCC kahte ki ham ki kisi bhi vertex se kisi bhi vertex par pahuch sakte hai So agar ham SCC component ke edges ke direction ko reverse kar dete hai then too Ye SCC1 he rahega. 
2. If 2 nodes are the part of the same cycle,  then Only it will be strongly connected. Ye pura sahi nahi hai.
Agar graph mai kisi node se kisi aur node par jane ke rasta hai, then wo Strongly connected hai. It may be possible ki we same cyclye mai na ho we see the example in lecture. 

So Given graph mai, sari edges ki direction reverse kar do.  So ab agar DFS  lagayenge toh hamara ans mil sakta hai. So jaise disconnected node ko traverse karte hai waise he traverse kar lenge. Aur har baar jab new node se dfs laga rahe honge disconneced graph mai, tab SCCCount ko ek se bada denge. 

Ek aur problem hai?
Jo order hai dfs lagane ka same order mai hona chahiye like scc1->scc2->scc3. Warna hamara ans Galat aayega. Agar traversing or visited ka order change ho raha hai then phirse purani problem arise ho jayegi ham ek scc se dusre scc tak mai ghus jayenge kyuki hamko pata he nahi hoga kaha rukna hai. 
So is problem ko visited array ke help se nahi solve kar payenge. 

So How we maintain the order ? 
Two steps :- Solve the overall Problem
1. Kis order mai DFS Lagana hai -> Topological sort (dfs)
2. Edges ko reverse karenge :- reverse edges -> topological order ke order mai visit karte jayenge. 

So hamko itna toh pata he hai ki agar SCC hai then ek n ek toh cycle present he hoga. Generally scc1->scc2 ye represent kar raha hai ki pahle scc1 then scc2 par jao traversing ke liye. Which is similar to Topological sort. Aur hamko pata hai ki cycle ka topological sort nahi nikalta hai. Kanh's Algorithum  useful hita kyuki ye answer detect kar leta tha , answer nahi nikalta tha. DFS method Sirf Acyclic graph ke uppar he lagte the ye cycle bhi nahi detect kar pata tha. Lakin ye kuch n kuchh answer la kar zarur de deta tha so iska ab ham fayda uthayenge. 
Conclusion:- Ye confirm hai ki scc1 -> scc2 jo edge connect kar raha hai Directed hai so Is edge ka 1 node hamesha pahle aayega is edge ke 2nd node jisko point kar raha hai. So jaha cycle present hai unka order galat aayega lakin, so jaha cycle present nahi hai, wo order sahi dega. 

Pseudo Code :- Kosaraju Algorithum 
1. Topological sort :- DFS - visited found then ander daalo.  
2. Reverse the edges
3. Pop element from the stack
    1. If it is not visited 
       1. scc++
       2. DFS apply karo
    2. Not visited Avoid

Code Implementation
```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//  Topological Sort
void Topological(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s)
{
    visited[node] = 1;

    // look ar its all neighbour
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            Topological(adj[node][j], adj, visited, s);
    }
    // After visit, push it in the stack
    s.push(node);
}

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited);
    }
}

int kosaraju(int v, vector<vector<int>> &adj)
{
    stack<int> s;
    vector<bool> visited(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            Topological(i, adj, visited, s);
    }

    // Reverse the edges
    vector<vector<int>> adj2(v);

    for (int i = 0; i < v; i++)
        for (int j = 0; j < adj[i].size(); j++)
        {
            int u = i;
            int v = adj[i][j]; // i mai jitne bhi element hai unme edge bhej rahe hai
            adj2[v].push_back(u);
        }

    // Abhi sara visited hai, so unvisited mark karenge pahle
    for (int i = 0; i < v; i++)
        visited[i] = 0;
    // popped element from the stack
    int scc = 0;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!visited[node])
        {
            scc++;
            DFS(node, adj2, visited);
        }
    }

    return scc;

    // Topological Sort
    //  Reverse the edges
    //  Popped the element from stack
    //   If  the popped node is not visiyed yet
    // scc++ DFS Apply
}

int main()
{
    int v = 5;
    vector<vector<int>> adj(v);

    // Building a Directed Graph
    // 0 -> 2, 2 -> 1, 1 -> 0 (Component 1)
    // 0 -> 3, 3 -> 4 (Other edges)
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);

    int sccCount = kosaraju(v, adj);

    cout << "Total Strongly Connected Components: " << sccCount << endl;

    return 0;
}
```

Time ans Space Complexity :- V+E

### Tarjan Algorithum
Is mwthod se karne ek fayada hai ki is method se single traversing karne se apna answer nikal sakte hai. 
Kosaraju method se hamne tin baar traverse kiya tha :-
1. Topological sort
2. Edges reverse
3. Stack ko pop kiya, phir traverse kiya. 

SCC hone ke liye, if u->v exist then v->u would also exist , then it is call scc. 
disc :- It store the time at which the node is discovered. 
low :- It store the lowest discovery time to reachable from that node. 

So while travesing from  u->v , u puchh raha hai v se ki kya tum mujh par ya mujse pahle aaye hue element par pahuch sakta hai. If ha then scc hai aur yahi toh low bhi kahta hai. So ab check karenge ki agar disc of node chhota aata hai low of node se then scc nahi hoga. 
note :- 
1. Generally on single node 2/2:- (low of 2)  represent that ki kya ham  kow 2 means ki ham sirf wahi pahuch sakte hai jiska dics time 2 hai. whereas in 5/3 low of node : ham is node se waha pahuch sakte hai jiska discovery time 3 hai. So yaha par disc of node 5 hai low of node 3 hai  so ham yaha se disc of 3 par ja sakte hai jo ki 5 se pahle aata hai, then ham wapas apne node par bhi aa sakte hai so ye scc hoga. 

Working :- 
1. Node ko traverse karte jayenge aur usko stack mai daalte jayenge.
2. Agar visited node milta hai then low of node ko update kar denge min(disc[neigh], low[node])
   1. Ab node se wapas aate waqt low of node ko min( low[node], low[neigh])
3. Ab jab low time and disc time chhota aa raha hai then ab hamko pata chal jayega ki scc mil chuka hai.  

So ham is example ke through ye conclusion nikal sakte hai ki ham sirf visited ko dekh kar apne low of node ko update nahi kar sakte hai. It may be possible that ki visited node se wapas aane ka rasta n ho. 
How can we diffentiate the visited node se wapas aane ka raste hai ki nahi or Konsa visited node ko consider kare aur konsi ko nahi.  So simply ham visited node ko check lar lenge ki kya wo hamare stack mai present hai ki nahi, if nahi then usko consider nahi karenege.  

Stack :- Ye stack hamara dfs walastack nahi hai . Jab hamko hamara low aur disc same mil rahe the tab ham is stack se apne sare element ko remove karte hai .

Steps :-  
1. if neighbour is not visited
    1. visit it
    2. DFS apply 
    3. low node = min(low[node],low[neigh])
2  else
    1. If neighbour is already in the stack
       1. low node = min (low[node], disc[node])
Ab sare neighbour ko visit kar liye ab check karenge kya disc[node]==low[node] hai then ek ek karke stack se element pop hote jayenge jab tak current node nahi milta. 

Code Implementation :- 
```

```