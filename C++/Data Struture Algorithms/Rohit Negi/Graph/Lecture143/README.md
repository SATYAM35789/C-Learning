### Dijkstra's Algorithum :- Single source shortest path algorithum
Ek graph given hoga , jo undirected hoga , lekin uska weight diya hoga. Source node se shortest path path nikalna for every other node connected with that node directly or indirectly. 

So ham Iske pahle wale lecture mai topological sort ke through answer nikal rahe the yaha nahi nikal sakte kyuki ye Isme direction nahi hai, aur cyclic bhi hai. Aur uske pahle walr lecture ka bhi concept nahi use kar sakte kyuki usme hamko hamre pass weight nahi diya gaya tha. 

For example :- 
Hamare pass Teen state hai Delhi Uk Up, Delhi-Uk ->3, Delhi-up->5 and Up-UK->1. So ab delhi ko as source node maante hai, Delhi se aur state ka shortest distance nikalte hai, 
Isme se shortest distance delhi toh confirm hai jo 0 hoga, Delhi ka Delhi se distance. Delhi se up ka distance 5 hai aur delhi se uk ka 3, so yaha se ek node ka shortest distance confirm hota
1. Delhi to Uk :- source node to up to uk or source node to Uk :- 5+x > 3
2. Delhi to Up :- source node to uk to up or source node to Up :- 3+x < 5   
2nd wala shortest ho sakta hai if x=1 but 1st wala kabhi bhi shortest nahi ho sakta
Note :- Chhoti walo value ko choose karna sahi hoga, kyuki wo ans de sakta hai. 
2. Jiska answer mil chuka hai uake liye calculate karne ki zarurat nahi hai. For example delhi source node hai uske answer 0 hai hoga, Delhi se Uk gaye jo 3 km hai, so yaha ham wapas uk to delhi nahi nikalenge. 
Delhi->uk->delhi  :- which also means Delhi to Delhi, now we have Delhi to Uk =3 and uk -> delhi=3 so we have 6 km which grater than 0 that minimum we have. 

So Delhi source node hai toh uska shortest distance mil jayega hamko, uske baad uske neighbour ko check karo jo neighbour sabse chhota hai usko minimum maan lo aur apne dist mai update kardo, phir us min walle node par jao aur waha jiska ans hmako mil chuka hai like source node usko ignore kardo, uske neighbour mai jo shortest hai usko update kardo dist array mai and so on karte jao. 

Algo Basix Idea :- 
1. Source node ka distance source node se 0 hai, aur source node aur sare node ka distance ko int_max maan liya . 
2. So pahle source ke neighbour , so ab source ke neighbour , apne weight + abhi tak ka minimum ko int_max se compaire karke update kar lenge, so ab source uske neighbour ka distance uske weight itna hai. 
3. So ab Source node explore hi chuka means uske neighbour ko dekh liye hai then, uske source node ko nahi dekhna hai.
Note :
1.  Agar kisi node par chale gaye tab ye samjh lenge, ab sabse chhota distance yahi hone wala hai,is se chhota nahi milega hamko.  
2. Ham us neighbour ko visit kar rahe hai jo minimum hai aur explore nahi hua hai.
Explore :- Uske sare neighbour ko ham visit karna. 
3. Ham node ko select kaise karenge, apne dist aur explore vector ke help se, so jo abhi explore nahi hua hai hamre explore array mai usme se sabse minimum kis index par stored hai dist array mai usko. 

Given :-
1. Adj list: Given in 3d form. vector< vector< int>> adj[N] :- so yaha hai adj array ke index ek 2d vector ko point kar raha hai. 
like 0-> {1,2}  row 1 :- iska 1st col 1: node , 2nd col 2: vertex
         {2,6}  row 2

2. Explore vector : Ye N size ki hogi aur Isko 0 se intialize karenge jo batayega ki kon se explore hua hai konse nahi.
3. dist vector : Ye har node ki har node se shortest distance ko store karke rakhega, aur isko intially INT_MAX se intialize kar denge. 

Summary
1. Select the vertex(noder) which is not explored yet and its dist is minimum among all the unexplored vertices. O(V)
2. Relex the edges(V-1)
    1. Look at your all the unexplored neighbour
    2. if(dist[ node]+weight < dist[ neighbour]) then dist[ neighbour] = dist[ node]+ weight  

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int s)
{
    vector<bool> Explored(V, 0);
    vector<int> dist(V, INT_MAX);

    dist[s] = 0;
    int count = V;
    while (count--)
    {
        // Selecta a node which  is not explored yet and its distance value is minimum
        // for selecting minimum we need
        int node = -1, value = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            if (!Explored[i] && value > dist[i])
            {
                node = i;
                value = dist[i];
            }
        }
        Explored[node] = 1;

        // Relex the edges
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0]; // First col of 2d vertex represent the vertex.
            int weight = adj[node][j][1];    // Second col of 2d vertex represent the weight.
            // Neighbour should not be explored
            if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
                dist[neighbour] = dist[node] + weight;
        }
    }
    return dist;
}

int main()
{
    int V = 4;
    // Adjacency list: adj[u] = {{v1, w1}, {v2, w2}}
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 5});
    adj[0].push_back({2, 8});
    adj[1].push_back({2, 9});
    adj[1].push_back({3, 2});
    adj[2].push_back({3, 6});

    int source = 0;
    vector<int> distances = dijkstra(V, adj, source);

    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << (distances[i] == INT_MAX ? -1 : distances[i]) << endl;
    }

    return 0;
} 
```

Time Complexity :- 
Explore and dist :-
iteration v  
ek vertex V-1 edges se connected ho sakta hai = v
Ye kaam hamko V time karna hota tha
(V+(V-1))*V
v*v= o(Vsq)

Space Complexity :- O(V)

### 2nd Method To solve Dijkstra Algorithum :- 
2nd approch ko try karne se pahle jaan lete hai ki hamko 1st method problem kaha aa rahi thi ki ham 2nd method try kar rahe hai, So explore dist array jab bhi ham next node ko select kar rahe the explore karne je liye tab ham wo value select kar rahe the jo  explore nahi hua hai aur chhota hai ye karne ke liye ham barbar Iterate kar rahe the V time. 
So ham min heap ka use kar sakte , jisme ham us node ko select kar rahe honge jo dist ki value sabse kam hogi. So min heap mai value pair ke form mai daalenge. pair< int,int>p1; first= minimum dist, Second=vertex
So mimimum element ko bahar nikalo aur explored karo uske neighbour ko. 
Note: 
1. jab bhi neighbour ki visit karte hue apne value ko update kar rahe honge tab ham apne heap mai pair nhi daal rehe honge. 
2. Ye process karte hue ek node ki multiple entries aa sakti hai hamare heap mai.  So explore marked means ki iska final answer ab update nahi hoga. 

Revisied Steps :-
1. Priority queue or  heaps ko initialize procedure {0, source node} aur dist[node]=0 kar denge. 
2. Jab tak priority queue empty nahi ho jati tab tak
   1. Node ki info nikalenge-> agar wo node already explored hai then ignore that node
   2. if not explored, then mark it explored
3. Loook at unexplored neighbour jo explored nahi hue hai
4. Relex the edges
   if(dist[ node]+weight < dist[ neighbour])  then dist[ neighbour] = dist[ node] + weight
   -> And push the (dist, neighbour) in the priority queue. 

Code Implementation 
```
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int s)
{
    vector<bool> Explored(V, 0);
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p;
    p.push({0,s});
    
    while(!p.empty())
    {
        int node = p.top().second;
        p.pop();
        if(Explored[node]==1)
        continue;
        Explored[node] = 1;

        // Relex the edges
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0]; // First col of 2d vertex represent the vertex.
            int weight = adj[node][j][1];    // Second col of 2d vertex represent the weight.
            // Neighbour should not be explored
            if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
                {
                    dist[neighbour] = dist[node] + weight;
                    p.push({dist[neighbour], neighbour}); // ham make pair ke throgh kar sakte ye naya tarika hai queue mai element daalne ka
                }
        }
    }
    
    return dist;
}

int main()
{
    int V = 4;
    // Adjacency list: adj[u] = {{v1, w1}, {v2, w2}}
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 5});
    adj[0].push_back({2, 8});
    adj[1].push_back({2, 9});
    adj[1].push_back({3, 2});
    adj[2].push_back({3, 6});

    int source = 0;
    vector<int> distances = dijkstra(V, adj, source);

    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << " : " << (distances[i] == INT_MAX ? -1 : distances[i]) << endl;
    }

    return 0;
}
```

Space Complexity :-
Explored array:O(V)
dist array : O(V)
priority queue : Ham priority queue mai uske neighbour ko daal rahe the, kisi ek ko bahar nikalne ke baad.
So ye worst case mai V ke ho sakti ye kar de, nahi kyuki ham queue mai multiple entries kar rahe the. So we can treat the graph as complete graph to analize it.  
So ye nc2 ka formula ke barabar chala ja raha hai jo hota no. edges in complete graph. O(V+E)

Time Complexity :- 
priority queue :- push and pop (hamre graph ke pass jitni bhi edges hai ham unko he toh daal rahe the) So worst case mai sari sari edges PQ ke ander ja rahi hai. push: ElogE + pop ElogE =  ElogE
If complete graph the E = Vsq so O(ElogV).

Compairing The method's
Dense graph-> edge bahut jada hai itna ki lagbhag har har vertex se har ek vertex cover, E= Vsq. So is case mai 1st method ko priority denge . Vice-Verse in case of Sparse Graph. 
Real life mai jayda tar spare method he use ho raha hota hai then is case mai Priority wala he use karte hai.Aur hamko set se bhi implement kar sakte hai.

Dijkstra's Disadvantage:- 
-ve weight par kaam nahi karta hai. 
Ham 3 vertex ka example lekar samajh sakte hai, kaise dijkastra fail ho raha hai. Solution sahi mahi milta hai as ki hamre pass pass explored kar di gai vertex se chhota chhota path mil jata hai tab fail ho jata hai. 

Use case of -ve weight ko search karke dhyan se pado?
