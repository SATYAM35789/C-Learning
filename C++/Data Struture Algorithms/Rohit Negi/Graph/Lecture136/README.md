### Topological Sort :- 
Topological sort nikalne ke liye , sabse pahle is requirement check karenge , ki jis graph ka hamko topological sort nikalna hai wo DAG (Directed Cyclic Graph) hai ki nahi, it means ki graph mai direction hona chahiye aur cycle present nahi hona chahiye. 
So ab hamko graph diya hoga aur bolega ki Topological sort nikal kar batayiye so sort ka matlab hota ki data ko arrange karna hota hai (ascending or descending mai). 
Kaise arrange karna hai  ue hamko diya hua hai, so u -> v where u = initial node (jaha se arrow nikal taha hai) v: final node (jaha arrow ja rahi hai ). So u hamesha pahle aayega v se.
Note : Hamko multiple ans mil sakte hai topological sorting ke. 

Topological sort DAG ke liye he  kyu lagta hai?
Directed :- If not directed than adjenecy list mai do combination banega ek u->v and v->u , so iske wajah se ham contradict kar denge ki konsa pahle aana chahiye konsa baad mai. 
Cuclic :- Is case mai bhi u->v , jisme u pahle aana chahiye aur v baad mai , ye condition fulfilled nahi ho sakti. 

Definition : Topological Sort :- 
Toppological sorting for a DAG is a linear ordering of vertices such that for every directed edge u->v, the vertex u comes before v. 

Topological sort ko DFS ke help se bhi kar sakte hai. Let's see how :-
Ham kisi bhi node ko select kar sakte hai, aur DFS approch laga sakte ki apne neighbour ko pakdo aur aage chalte jao jab tak node khatam ho jaye khatam hone ke baad wapas aa jao pichhle node par dekho ke sare neighbour cover hai kya , if yes then go back and do same precedure if not then go to the neighbour untila all covered. 
So there may chabces that koi node unvisited raha is full precedure mai so uske liye visited array loop ka conecpt use kar sakte. 
Note : Pahle check karlo jisko starting node bana rahe hai, wo visited hai ki nahi, if nahi then ham usko starting node le skte hai. 

DFS mai visit kar diye gaye element ko ham ek vector mai store karte hai

So DFf mai vector use karte samay hamko shifting ka use karna padta , jiske wajah se time complexity increse hoti, stack use karne se shifting ki zarurat nahi padegi aur hamari problem solve ho jayegi. 

Lets see how stack solve the problem? use ham DFS he kar rahe hai but answer ko stack mai use karenge.
Node(starting) par jao aur bolo ki jo jo node tum par depenedent hai pahle unko daalo phir mujko daalna. So jab hum return kar rahe honge nodes se tab ham apne data ko store karwayenge stack mai. Dependent means U->v , v is dependent on u so go to v and check ye bhi kisi aur per dependent hai ya nahi. 
Note :- Koi node tabhi ander jayega , jab us node se directed node ander chale gaye ho. 

Use Case of Topological Sort :- 
1. Processor  : Jo processor hoti hai wo ek dusre par dependent hoti hai. So computer pahle check karta g=hai kya ye DAG hai then  sabka topological sort nikalta hai tab uska excution karta hai.

Time Complexity :- O(V+E)
Space Complexity :- O(v)

Code Implementation :- Hamko ek DAG graph diya hai in adjList representation , vertex in the grapg as v
```
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited, stack<int> &s)
{
    visited[node] = 1;

    // Look at its neighbour one by one
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (visited[adj[node][j]] == 0) // also write as if(!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited, s);
    }

    // Agar sare neighbour ko push lar diya hai toh push kardo node ko stack ander
    s.push(node);
}

vector<int> topSort(int v, vector<int> adj[])
{
    // DFS find karo
    vector<bool> visited(v, 0);
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            DFS(i, adj, visited, s);
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    int v = 6; // Number of vertices
    vector<int> adj[v];

    // DAG (Directed Acyclic Graph) build kar rahe hain
    // Edges: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};
    // 0 aur 1 ke koi outgoing edges nahi hain

    vector<int> result = topSort(v, adj);

    cout << "Topological Sort Order: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
```

### Topological Sort using BFS :- 
So we have special algorithum jiska naam hai kahn's Algorithum.let vertex = process So yaha jo process hai wo bol raha haga ki pahle mai execute hoga phir koi hoga, . So pahle konsa execute hoga , wo process or vertex jis par aur koi incoming edge na aa rahi ho or jiska koi parent n ho. (u->v : u ko parent , v ko child). 
Node :- Execute hone ke baad vertex or process ko romove kardo, phir unke edges ko bhi remove kardo, suke baad jo agar koi node mile jis par koi incoming edges nahi phir usko and do so on. 
Sare node ko traverse karlo jaha ja rahe hai usko 1 se uska indegree bada do or adjlist mai jao aur dekho ki paricular vertex se kaha kaha ja rahe hai, so waha jakr ek se bada do. So is info ko ek vector mai store karwa lenge. 
So ab vector mai jis ki value 0 milti hai usko queue mai daal do, phir queue se queue ko pop karo or uske front wale ko bahar niaklo aur apne ans mai daal do, so ab ab jisko bahar nikala hai wo jis jis par edge daal raha tha usko ek se - kardo , agar iske baad vector mai 0 milta hai toh uske bhi queue mai daal do and do so on till queue is empty. 

Steps :- 
1. Find indegree of all vertex.
2. Push Zero-indegree vertex into queue
3. pop element from queue or Node ke neighbour ke indegree ko ek se kam kardo. 
4. Jiski zero indgree ho gaya hai usko push kardo into the queue. 

Time and Space : O(V+E) , O(V)

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topSort(int v, vector<int> adj[])
{
    vector<int> ans;
    vector<int> indegree(v, 0); // Store the indegree of every node

    // Step 1: Indegree calculate karo
    for (int i = 0; i < v; i++)
        for (int j = 0; j < adj[i].size(); j++)
            indegree[adj[i][j]]++;

    // Step 2: Queue mein woh nodes push karo jinpar koi dependency nahi hai (indegree 0)
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (indegree[i] == 0)
            q.push(i);

    // Step 3: BFS process
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // node ke neighbour mai jis bhi node par edge ja rahi usko ek kam kardo
        for (int j = 0; j < adj[node].size(); j++)
        {
            indegree[adj[node][j]]--;
            if (indegree[adj[node][j]] == 0)
                q.push(adj[node][j]);
        }
    }
    return ans;
}

int main()
{
    int v = 6;
    vector<int> adj[v];

    // Example DAG: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> result = topSort(v, adj);

    cout << "Topological Sort Order: ";
    for (int node : result)
        cout << node << " ";
    cout << endl;

    return 0;
}
```
Ek Pro-Tip (Cycle Detection):
Kahn's Algorithm ki sabse badi khasiyat yeh hai ki isse aap cycle detection bhi kar sakte hain.
Agar graph mein cycle hogi, toh kabhi bhi kisi node ki indegree 0 nahi hogi (cycle ke nodes ek-dusre par dependent rahenge).
Iska matlab queue khali ho jayegi lekin kuch nodes ans list mein nahi aayenge.
Check: Agar ans.size() != v, toh iska matlab graph mein cycle hai aur topological sort possible nahi hai.
