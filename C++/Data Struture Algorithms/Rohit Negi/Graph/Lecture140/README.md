### Prerequistite Tasks :- 
We have N=4 , P=3, pre = { {1,0}, {2,1},{3,2}} where,
N = No. of task,
P = No. of prerequest
{1,0} represent :- 1 task ko karne se pahle 0 ko karna hoga. like wise other too.
Order jisme is problem ko solve kar sakte hai :- 0->1->2->3 
Agar ham task kar sakte hai then answer dena hai ki ha solve ho sakta hai, if no then solve nahi ho sakta hai.
 So Agar dhyan se is problem ko soche toh ye similar to topological sort jaisa lag raha hai. So ham conclusion nikal sakte hai ki, agar cycle present hua toh ham is problem ko solve nahi kar sakte hai, if no cycle then problem ko solve ar sakte hai. So ham yaha cycle detection algorithum laga sakte hai(Directed Graph). 
We use  BFS (kanh's algorithum :-)
Advantage : 1. Detect cycle : If Cycle detected then uska toh nahi nikal sakte. 
2. And give the topological sort of DAG. 

Kanh's Algorithum :- 
1. Indegree calculate karlo
2. queue ke ander usko daaldo jiski indegree 0 hai. 
3. queue ke front ko bahar nakalo, jis jis mai edge ja rahi hai usko ek se kam kardo. 

Note  size : no. of element bahar nikale hai queue ke, size == N  hai means DAG hai aur iske ander koi bhi cycle present nahi hai. Ans we can able to complete the task. If not equal then Cycle present hai means ki  kisi ka indegree 0 nahi hua hai aur wo bach gaya hai.

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
{
    // Adjecency list create karna
    vector<int> adj[N];

    for (int i = 0; i < P; i++)
    {
        adj[prerequisites[i].second].push_back(prerequisites[i].first); // {1,0} :- 0->1   where adj[prerequisites[i].second] =0   and push_back(prerequisites[i].first) :- ->1
    }

    // Kahn's Algorithum :-

    // 1. Indegree find karna :-
    vector<int> inDeg(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int neighbor = adj[i][j];
            inDeg[neighbor]++;
        }
    }

    // 2. Queue
    queue<int> q;
    for (int i = 0; i < N; i++)
        if (inDeg[i] == 0)
            q.push(i);

    // storing size of topological sort
    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        // uske neighbour ko ek ek se kam kardo
        for (int j = 0; j< adj[node].size(); j++)
        {
            inDeg[adj[node][j]]--;
            if (!inDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }
    return count == N; // Then return 1
}

int main()
{
    int N = 4; // 4 Courses (0, 1, 2, 3)
    int P = 3; // 3 Dependencies
    
    // Prerequisite pairs: {target, source} -> source to target
    // {1, 0} means 0 -> 1
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    if (isPossible(N, P, prerequisites))
        cout << "Success: All courses can be finished!" << endl;
    else
        cout << "Error: Cycle detected! Impossible to finish." << endl;

    return 0;
}
```

### Course Schdule :-
Isme hamre pass N task diya gaya hai aur hamko pick karna hai N task from O to -1 mai se, Yaha prerequest ka khel hai so isme 0 task ko karne se pahle 1 task ko karna hoga. So hamko diya gaya hai ki :- 
n : total n task hai hamare pass
m : m prerequestic pair's diye gaye hai. 
So hamko order ko print karna hai. if not order possible, then print empty {}. 

Code Implementation :-
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int N, int P, vector<vector<int>> &prerequisites)
{
    // Adjecency list create karna
    vector<int> adj[N];
    vector<int> inDeg(N, 0);

    for (int i = 0; i < P; i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]); // {1,0} :- 0->1   where adj[prerequisites[i].second] =0   and push_back(prerequisites[i].first) :- ->1
        inDeg[prerequisites[i][0]]++;
    }

    // Kahn's Algorithum :-

    // 2. Queue
    queue<int> q;
    for (int i = 0; i < N; i++)
        if (inDeg[i] == 0)
            q.push(i);

    // Storing the order
    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // uske neighbour ko ek ek se kam kardo
        for (int j = 0; j < adj[node].size(); j++)
        {
            inDeg[adj[node][j]]--;
            if (!inDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }

    vector<int> temp;
    return ans.size() == N ? ans : temp;
}

int main()
{
    int N = 4; 
    int P = 4; 
    
    // Test Case: 1->0, 2->0, 3->1, 3->2
    // Expected Order: 0 1 2 3 OR 0 2 1 3
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> order = findOrder(N, P, prerequisites);

    if (order.empty()) {
        cout << "No valid order possible (Cycle detected)!" << endl;
    } else {
        cout << "Valid Course Order: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### Alien Dictionary :- 
So Hamko dictionary diya hua jisme kuchh words present hai. So jo hamare pass dictionary hoti hai wo sorted Aplphabatical order mai hoti hai. So jo alian ki dictionary hai usme jo words hai wo kis order ko follow kar rahe hai. Isme K diya hai, which means ki k no. of english character ko use kar rahe hai from starting. So in character ke ordering ko hamko dena hai. 
Ex if k=3 then it use a,b,c (while making it's words.)

Dictionary= {{baa},{abcd},{abca},{cab},{cad}}
so isme baa aur abcd mai baa pahle aaya hai which means b aur a mai se pahle b aayega i.e, b->a
similarly abcd aur abca mai pahke abcd aaya which means ki d aur a mai d pahle aayega a se i.e d->a and do similarly if aur bhi element exist karte hai tab. a->c , b->d.

Phir iske help se DAG graph bana lo vision clear ho jayega. 
So ab ye ensure kar  sakte hai ko topo;ogical sort laga sakte, jisse hamko hamara order mil jayenga. 
Steps :- 
1. Indegree nikalo
2. 0 wale ko queue ke ander daalo
3. bahar nikalo, neighbour ki indgree ko ek ek se kam karo
4. phir jinka indegree 0 ho gaya unko phir queue mai daalo nikaalo and so on. 

Note:- Jaise he different character mile, waise he hamko pata chal jayega ki konsa character pahle aayega, jo word pahle pahle uska character pahle aayega. 

1. So abhi tak ham jitne bhi problem ko face kiye hai, usme vertex/node 0,1,2 ke form mai le rahe the so yaha kaise store karenge character as node ? Iske liye ham let kar lenge jitne bhi character hai like a=0,
b=1, c=2 and so on. 

1. Adjecency List create karna
2. Kanh's algorithum laga lo

Note :- Ham sare words ko dictionary mai compair ke liye nahi use  kar rahe hai, taaki extra edges na aaye aur hamko complex n banaye apne compairsion ko. Ham isko check kar sakte DAG bana kar sare words se compairsion karke edge form kar sakte hai.

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string findOrder(string dict[], int N, int K) // N : No. of words , K= No. of character from starting alphabates
{
    //  Adjecency list bana bana lo
    vector<int> adj[K]; // without repeating same character k ke barabar he honge
    vector<int> inDeg(K, 0);

    for (int i = 0; i < N - 1; i++) // N words hai, compairison ek kam he hoga
    {
        string str1 = dict[i], str2 = dict[i + 1];
        int j = 0, k = 0; // j: starting index of str1 , k: starting index of str2 ko.

        // Compairsion : Jab tak different character n mile
        while (j < str1.size() && k < str2.size() && str1[j] == str2[k])
            j++, k++;

        // Handling this casse too :- cde cdeb -> cde pahle aana chahiye. So string 1 ke khatam ho jane ke baad compairsion karne koi matlab nahi, hamko nahi pata chalega konsa char pahe hai
        if (j == str1.size())
            continue;
        // Agar different mile, toh ruk jao
        adj[str1[j] - 'a'].push_back(str2[k] - 'a'); // character ko int ke form mai daal rahe jaisa hum discussion kiya tha

        // Indegre
        inDeg[str2[k] - 'a']++; // Jidhar edge ja rahi uski indegree bada rahe hai.
    }

    // Kahn's Algorithum
    // Queue
    queue<int> q;
    for (int i = 0; i < K; i++)
        if (inDeg[i] == 0)
            q.push(i);

    // Storing the character in String
    string ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        char c = 'a' + node;
        ans += c;

        // uske neighbour ko ek ek se kam kardo
        for (int j = 0; j < adj[node].size(); j++)
        {
            inDeg[adj[node][j]]--;
            if (!inDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }
    return ans;
}

int main()
{
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    // Based on dictionary:
    // 'b' comes before 'a' (from baa, abcd)
    // 'd' comes before 'a' (from abcd, abca)
    // 'a' comes before 'c' (from abca, cab)
    // 'b' comes before 'd' (from cab, cad)

    string result = findOrder(dict, N, K);

    cout << "Alien Alphabet Order: " << result << endl;

    return 0;
}

```

### Parallel Course :- 
Hamko ek graph diya hai, jisme node present hai jo represent kar rahe hai Courses aur uske sath hamko unki timing diya hua hai ki wo kitne mahine mai khtam honge. So hamko sare ke sare courses ko complete karna hai, so minimum kitna samay lagega ki hum sare ke sare courses ko khatm kar pate. So ham ek sath kitne bhi course kar sakte hai. 
so hamko relation bhi diya hai like [[ 1,3],[ 2,3]]. where [ 1,3] : represent ki 3 course ko karne se pahle 1 course complete hona chahiye. Aur Time diya gaya hai, jo represent kar raha hai timing of the vertex in the incresing Order of nodes we have. 
Node/ Vertex :- Ki indexing 0 based he rakhenge taaki complexity kam ho.     
So Ham yaha bhi topoogical order he laga rahe hai kyuki course dependant hai, so ye ek type se prerequstics jaisa he hai , topological type ka lag raha hai, Here we apply kahn's algorithum. 

Steps :- 
1. Indegree  calculate karlo 
2. Queue mai 0 wale ko daal do
3. Queue se bahar nikalo aur jis par edge ja rahi hai isse usko ek se kam kardo 
and do so until queue is empty. 

Maximum time to complete previous courses. CourseTime naam ka array le lo Initially isme sabko 0 bana do. 
so ab jo bhi maximum hai usko compair karke update karte jayenge. Compairsion hoga Course Time aur Previous Time mai. 

Code Implemtation :- 
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
{
    // Create Adjencency list
    vector<int> adj[n];

    for (int i = 0; i < relations.size(); i++)
    {
        // Convert them into 0 based indexing -1
        adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
    }
    vector<int> InDeg(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < adj[i].size(); j++)
            InDeg[adj[i][j]]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (InDeg[i] == 0)
            q.push(i);

    // CourseTime :- Maximum Time to complete privous course ko store karta
    vector<int> CourseTime(n, 0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;

            if (!InDeg[adj[node][j]])
                q.push(adj[node][j]);

            // Maximum Time To Complete Previous course and present Course Time
            CourseTime[adj[node][j]] = max(CourseTime[adj[node][j]], (CourseTime[node] + time[node]));
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, CourseTime[i] + time[i]); // CourseTime[i] :- Maximum Time To Complete Previous course  , time[i] :- present Course Time
    }
    return ans;
}


int main()
{
    int n = 3;
    vector<vector<int>> relations = {{1, 3}, {2, 3}};
    vector<int> time = {3, 2, 5};

    /*
       Logic: 
       Course 1 (3 months) and Course 2 (2 months) can run in parallel.
       Course 3 (5 months) depends on both.
       Max time to reach Course 3 = max(3, 2) = 3 months.
       Total time = 3 (reach) + 5 (Course 3 itself) = 8 months.
    */

    cout << "Minimum time to complete all courses: " << minimumTime(n, relations, time) << endl;

    return 0;
}
```
 