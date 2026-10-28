### BFS Traversal :- 
Traversal means ki jitne bhi nodes hai un sabko visit karna hai. In different topics we have seen traversing like in array and vector farward and backward traversing, In singly LL visiting all nodes, In tree we have seen many traversing like preOrder, inorder, postOrder and levelorder and many many more traversing. Just like we have traversing technique in the Graph also their 1. BFS Traversing 2. DFS Traversing. 

Lets call BFS travesing as CORONA virus so, in corona  virus active person ke agal- bagal jo bhi rahta hai usko phir uske agal bagal koi rahta hai usko corana virus ho jata tha. Jo jo active person ke contect mai aate hai unko ho jata tha corna virus. Graph mai kisi ko starting point select karlo aur store karlo, us se jo connected hai unko store karlo, phir jaha store kiya usme se next element ko select karo jinke connected node ko abhi corona nahi hua unko, usko select karne ka baad same process apply karo until sabko korna nahi ho jata, so these stored value in this process is the BFS Traversing. 

Lets talk about the BFS Traversing , select the starting node (store it too) and name it level 0, selecting node se unke agal bagl wale ko visit karo and store it and name this nodes as level 1, now select node of level 1 and do same process of visting connected node and store them name the level and so until all visited and leveled. 
Level:- show the distance from the starting nodes. How to level nodes :- Agar level one mai 2 nodes hai isme pahle nodes se connected nodes ko level2 hoga aur dusre nodes se bhi connected nodes ko bhi level 2 hoga. So it means ki level ke jitne bhi nodes hai un sare nodes se connected nodes ko level+1 name hoga. 

So hamko yaha Adjecency List diya hoga koi actual graph toh nahi diya hoga, For BFS we need Queue Data structure. And Visited Naam ke ek Array jo hamko batayega ki ye nodes visited ho chuke hai ki nahi. 
Queue :- Queue mai connected nodes ko daal do 
visited : Visited Array mai jisse connected hai usko daal do

So starting nodes ko queue mai dalo, us se connected nodes ko queue mai store karlo , phir starting ko Visited mai store karwa lo and so on until Queue is empty. 

Visited Array ko le lo aur jisme sare node ko le lo aur inko 0 se initialize karlo jo show kar raha hia ki ye abhi visited nahi hai. Apne kisi ek node starting node maan kar queue mai daalo aur marke karlo ki ye visit ho gaya hai means visited array mai is node ko 1 kardo. Starting nodes se connected node ko adjecebcy list se queue mai dalo iske baad starting node ko ans mai store karlo and do so until queue is empty with each and every node. 
Note :-  Jo already visited hai unko queue mai nahi dalna hai. 

Steps
1. Pop a node from queue and put it in the ans
2. Node will look into its unvisited neighbour
   -> push them them in queue
   -> Mark them as One. 


Code Part :- 
1. BFSGraph() vector type ka, parameter: int type ka v, vector type ka Adj[] array le lo
2. queue lelo int type ka
3. ek vector lelo bool type ka, visited naam ka aur isko 0 se initialize karlo. 
4. queue mai push kardo 0 ko
5. Vistited of 0 ko 1 kardo. 
6. Ek vector banalo ans naam ka , int type ka
7. Jab tak queue empty nahi ho  jata, 
   1. node mai q.front daal do
   2. queue ke first ko pop kardo
   3. ans mai node ko push_back kardo. 
   4. ek for loop chalo j =0 se laker adj[ node] ke size itna chalte raho
      1. Agar visted[adj[node][j]] , zero ke barabar hai tab 
         1. visted[adj[node][j]] ko one mark kardo
         2. q.push kardo visted[adj[node][j]] ko
8. Return kardo ans ko. 

Space Complexity : O(v)
Time Complexity :- 
Particular node do baar include ho rahi hai ek baar 1 node connected hai isiliye , second time , dusri nodes se connected hai isliye. 
1. Sare node ko cover kiya 
2. Sare edges ko 2 bat
O(V+2E) -> O(V+E)

Code Implementation :- 
```
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfsGraph(int v, vector<int> adj[])
{
    queue<int> q;
    q.push(0);
    vector<bool> visited(v, 0);
    visited[0] = 1;

    int node;
    vector<int> ans;

    while (!q.empty())
    {
        node = q.front();
        q.pop();
        ans.push_back(node);

        // 0 ke bagal wale node ko dekhna hai
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (visited[adj[node][j]] == 0)
            {
                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
            }
        }
    }
    return ans;
}

int main() {
    int v = 5; // Number of vertices
    vector<int> adj[5];

    // Graph edges build kar rahe hain
    adj[0] = {1, 2, 3};
    adj[1] = {0};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};

    vector<int> result = bfsGraph(v, adj);

    cout << "BFS Traversal starting from node 0: ";
    for(int x : result) cout << x << " ";
    
    return 0;
}
```

BFS Real world Application :- 
For example mera koi dost hai  real world mai lakin wo abhi mera dost naji bana hai Instagram par so if search his name then there is chances that us naam se hazaro log exist karte hai , then hazaro toh naam mai ham kho jayenge so yaha BFS is used wo kuchh same naam ke aise log lata hai jinka chances hota unme se koi ho on the basis of your friend circle. Different level par jeyenga aapke dost ka naam search karega jitne milega utne dikha dega. 

### DFS Traversal :- 
DFS Traversal ko bol do travelling wala. 
Isme ko traveller hai wo uske sare states ko travel karna  hai, start wo kahi se bhi kar sakta hai, starting nodes jisse bhi connected usme kisi ko choose kar sakta hai, wo tab aage badte jayega tab tak aage ka rasta band nahi ho jata, band hone ke baad phir wpas pichhle wale state ke pass jayega aur puchhega kya yaha se koi rasta hai agar hai toh chala jayega agar nahi hai toh wapas pichhle wale ke pass jayega aur same question karega , jab sare par nahi chala jata tab tak ye kaam karta rahega. 
Jab jaha se chala tha wahi wapas aa gaya sare jagah ghum chuke tab ham bahar aa jeyenga. Agar koi aisa node atta hai ghumte hue ki ham waha ja chuke tab , tab us nodes se wapas jana shuru kar denge.

Note :- So BFS or DFS ka multiple ans exist kar sakte hai.

Hamko ek AdjList given hogi so isse hamDFS kaise nikal sakte hai ? 
1. Recursion se 2. Jo recursion hoga wo stack se bhi ho sakta hai. .

Recursion :- 
Requirement :-  Sabse pahle ek visited array le lenge jisko 0 se initialize kar denge. 
Starting node par jao usko visited mark karlo aur usko Ans mai store karlo. Starting node se jaha bhi jao uske visited mark karlo and ans mai store karlo uske baad jaha bhi jao same step follow karo, if next node jaha gaye wo visited toh wapas aa jao and check aur ki kya koi node jo visited nahi hai, toh waha chale jao and if visited hai then wapas aa jao same step karo.

Steps:- 
1. It will vist its all neighbour one by one. 
    - And it will explore that path
2. If all neighbour are explore than it will back from where it's been called. 

Code Part :- 
1. DFS lelo vood type ka, parameter : int type ka node lelo, vector type ka Adj array le lo , visited aur ans le lo as reference
2. visited mai node lo 1 bana do
3. ans mai pushback kardo node ko
4. ek ek karke sare node ke neibhour ko visit karega, ek for loop le lo jo chalega j =0 se adj[node].size()
   1. Agar visited[adj[node][j]] barabar hai 0 ke tab
      1. DFS ko call kare adj[node][j] ke liye. 
5. Ans ko return kardo. 

Time Complexity and Space Complexity: same as BFS. 

Code Implementation :- 
```
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (visited[adj[node][j]] == 0)
            DFS(adj[node][j], adj, visited, ans);
    }
}

vector<int> dfsOfGraph(int v, vector<int> adj[]) // v = no. of vertex
{
    vector<bool> visited(v, 0);
    vector<int> ans;
    DFS(0, adj, visited, ans);

    return ans;
}

int main()
{
    int v = 5; // Total vertices (0 to 4)
    vector<int> adj[v];

    // Edges add kar rahe hain (Example Graph)
    // 0 -> 1, 0 -> 2
    // 1 -> 3
    // 2 -> 4
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // DFS call karna
    vector<int> result = dfsOfGraph(v, adj);

    // Output print karna
    cout << "DFS Traversal: ";
    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
```
