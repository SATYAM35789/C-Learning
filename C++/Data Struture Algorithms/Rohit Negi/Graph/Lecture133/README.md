### Graph Representation :- 
Representation :- We have two method represent the Graph graph data :- 
1. Adjacency Matrix :- 
   - undirected unweighted graph is given to us to understand it, Whenever we said for graph we have been given some of infomation :- 
   1. vertices : {1,2,3,4,5} =5  
   2. Edges : in {u,v} where u is starting of edges and v is the end of the edges. It may also consider as the u to v direction in case of directed graph. and in undirected graph you may take any of as u and v. 
   Ex :- { {0,1},{1,3},{3,4}, {2,4}, {0,2}}

   - Name Matrix suggest that something which is going to stored the data in the 2d form. 
   - Adjecency matrix : Undirected-unweighted Graph :- 
      1. jitne bhi no. vertices given hai graph mai usko ustne size ka matrix bana lo. If vertices v is given then size of matices is v*v. 
      2. So if edges exist then fill that one by 1 else with 0. So if undirected then value are get filed in both u-v or v-u. 

      So jo bhi information ab is matrics mai us se ham apne graph ko bana sakte hai, apne system mai. 

      Weighted graph ko kaise show karenge Matrix mai? 
    - Adjecency matrix : Undirected-weighted Graph :-
       1. jitne bhi no. vertices given hai graph mai usko ustne size ka matrix bana lo. If vertices v is given then size of matices is v*v. 
       2. Edges ke case mai jitna weight diya hoga  usko note kar lenge 1 ke jagah par, if not edges then fill it with 0. 

    - Adjecency matrix : directed-unweighted Graph :-
      1. jitne bhi no. vertices given hai graph mai usko ustne size ka matrix bana lo. If vertices v is    given then size of matices is v*v. 
      2. So if edges exist then fill that one by 1 else with 0. So if directed then value are get filed in both u-v .(so jis direction mai edge ja rahi us direction mai store kar lenge 1) 
    
    - Adjecency matrix : directed-weighted Graph :-
       1. jitne bhi no. vertices given hai graph mai usko ustne size ka matrix bana lo. If vertices v is given then size of matices is v*v. 
       2. Edges ke case mai jitna weight diya hoga  usko note kar lenge us index ki ke jagah par, if not edges then fill it with 0. (so jis direction mai edge ja rahi us direction mai store kar lenge weight ko)

Code Implementation :- 
// Adjacency matrics :- undirected- unweighted graph

```
#include <iostream>
#include <vector>
using namespace std;
 

int main()
{
    int vertex, edges;
    cin>>vertex>>edges;

    // Creating matrix
    vector<vector<bool> >AdjMatrices(vertex,vector<bool>(vertex,0));  // (vertex,vector<bool>(vertex,0)) :- vertex: size or row , vector<bool>(vertex,0) : col ka size vertex ke barabar aur intialize them with 0.

    int u,v;
    // Ab hamko ek ek karke batao
    for(int i=0;i<edges;i++)
    {
        // User batayega ki kaha se kaha ke liye edges given hai hamko
        cin>>u>>v;  // u : start, v : end
        AdjMatrices[u][v] = 1; 
        AdjMatrices[v][u] = 1; 
    }

    // Printing the matrics 
    for(int i=0;i<vertex;i++)
    {
        for( int j=0;j<vertex;j++)
        cout<<AdjMatrices[i][j]<<" "; 
    }
}
```
Space Complexity :- 
It cover the space v*v so O(vsq)
Time Complexity :- To create the graph with this matrics we have go to all the value so it take O(vsq)

2. Adjacency List :- 
Hamare pass ek undirected unweighted graph hoga , and we have asked to draw the graph with help of Adjecency list. 
1. So pahle sare vertices ko stored karlo (Array)
2. Phir kisi ek vertex se jaha jaha edge ja rahi hai(jis bhi vertex par) uske aage likh do, aise sare verices par jakar karlo.
(linked list ke help se) 
We can use vector(2nd) , so we preferred vector here it as it dynamic in nature. 

Note :- This method used less memory as it store info about only exist edges.

vector<int> AdjList[5]: ek array jai Adjlist naam ka jiska size 5 hai aur ye vector<int> int type ka value store karke rakhta hai. 
Adjlist[0].push_back(1) :- Adjlist naam ki jo array usme 0 index par jao aur 1 ko uske ander push_back kardo.
Accesing value :- Adjlist[0] [1] :- Adjlist array mai jao 0 index par usme vector ke 1 par jo value rakhi hai usko wapas kardo. 

Weighted Graph:- Adjecency List mai jab weight bhi include ho jayega tab kya karenge. 
Is case mai hamko do information  store karna hoga 1.aJis vertex par ja raha 2. uska weight kya hai, so we can use pair in this case.
creating the structure to store :-  
vector< pair< int,int>> Adjlist[5] :- Adjlist naam ka array jiska size 5 hoga, jo store karega vector type ke data ko, vector store karega pair type ka data jo store karega integer values ko. 

Time Complexity :- 
1. Creating array of size V O(v)
2. Undirected ka case mai 2 * Edges dalne honge  O(2E)
O(V +2E) -> O(V+E)
Worst case mai jo Edges hai wo vsq ke barabar ho sakti hai then . O(vsq) in case of Complete Graph

Spcace Complexity :- 
O(v+E) or O(vsq) : E = vsq O(vsq) in case of Complete Graph. 

Code Implementation :-
Undirected Unweighted Graph :- 
```
#include <iostream>
#include <vector>
using namespace std;

// Undirected Unweighted graph
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<int> Adjlist[vertex];

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        Adjlist[u].push_back(v);
        Adjlist[v].push_back(u);
    }

    // Print the list :-
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " ->";
        for (int j = 0; j < Adjlist[1].size(); j++)
            cout << Adjlist[i][j] << " ";

        cout << endl;
    }
}

```

### Compairing which method of representation is better :- 
1. Adjecency Matrix:- 
   1. Add edges :- O(1)
   2. Remove Edges : O(1)
   3. Edges exist : O(1)
   space Complexity :- O(vsq)
   Dense Graph(jisme edges bahut jayda hai similar to complete graph) :-  Then this is preferred. 
2. Adjecency List : Real world mai jyda ye use hoti hai
   1. Add edges :- O(1)
   2. Remove Edges : O(V) :- Removing and shifting in the vector
   3. Edges exist : O(v) :- vector ko traverse karna hoga (worst case mai list v size ka ho saktahai)
   space Complexity :- O(V+E) -> worst case O(vsq)
   Sparse Graph(no. of edges bahut he kam hai) : Then we preferred this. 

   Example :- FB: 1 Billion user :- Ue sparse type ka hoga kyuki aisa toh nahi hoga ki mere sare 1 billion friend honge jayda se jyada 4000, ho sakte hai. 

Agar STL ke through agar ham Adjlist banate hai toh wo sabko O(1) mai la dengi. 

Tree vs Graph :- 
Tree :- 
  - Agar hamre pass n node hai toh edge exactly n -1 hongi. 
  - loop exist nahi karta
  - collection of only nodes ko bhi tree kah sakte hai :- ye heirarchial form mai hota hai
  - start with root
  - ek child ka ek parent hota hai
 Graph :- 
    - loop nahi hota
    - collection of only nodes/vertex ko bhi graph kah sakte hai
       Ex jab at start mai jab bana hoga tab koi kisika frienf nahi raha hoga n. us case mai hota hai. 
       At starting of company jab koi user n ho. 
    - root exist nahi karta
    - ek child ka ka multiple parent ho sakte hai hai , chahe parent he n ho ye bhi ho sakta hai. 

    Spamers ko pahchanna :- Agar kisi ke pass followers bahut jayda hai lakin following kam hai. 
    OutGoing edges jayda ho incoming edges se tab pata kar sakte. 
    Degree of node :- 
      In case of undirected :- jitne no of other nodes directly connected hai
      InCase of directed : - 
      1. Incoming edges  2. Out-going edges
