### Shortest source to destination path :- 
Source se destination ke liye shortest path batana hai. So hamko ek 2d matrix diya hua hai jo 0 aur 1 se sirf bhada hua hai, usme source hamesha (00) wala hoga aur koi bhi destination ho sakta hai hamre matrix mai. 
Condition ye hai ki ham left-right, up-down sirf move kar sakte hai.  Ham sirf waha ja sakte hai jaha 1 hai, 0 jaha filled waha nahi ja sakte. 

Note :- Hamko minimum steps batane hai ki kam se kam kitne step mai destination par pahuch sakte hai. 
So vector wale problem hai, so hamko kaise pata chalega ki ye Graph se hoga. This is observation that ki if vector is filled with less num 0,1 or 0,1,-1 and ye repeatly present hai hamre vector mai then we can think of the graph. or ham apne space ko jo filled question ke according as node treat kar sakte hai. So if we do this to this problem then we can come to know that this problem is shortest path in undirected waited graph. 

Approched :- BFS (v+e) , Dijkstra ElogV -> Time complexity Dijkstra se jayda ho ja rahi hai. 

So BFS mai pahle neighbour ko traverse karta hai pir wo pane neighbour ko and so on aisa he karta jata hai. So jab destination milega  tab ham return ho jayenge. And isme jinko visit kar lenge usko 0 marke karte chale jayenge so ki usko dobara visit n kare. or we can use visited array , jaha jaha ja rahe honge waha waha 1 mark karte chale jayenge.  
So stack ke ander hamko tin chij ko store karenge row, col and step, jaha hai uska row aur col kya hai aur wo kitna step chal chuka hai. 

Pair syntex :-  pair<int,pair<int,int>> (row(col,step))

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

bool valid(int i, int j, int n, int m)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int shortestDestination(int N, int M, vector<vector<int>> A, int X, int Y) // N : no. of rows, M: No of col , X and Y are the coordinates of destination
{
    if(X==0 && Y==0)  // Jab source aur destination same hai. 
    return 0;

    if(A[0][0]==0)
    return -1; // Answer not possible

    // row , col, step
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});

    vector<vector<bool>> visited(N, vector<bool>(M, 0));
    visited[0][0] = 1;

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second.first;
        int step = q.front().second.second;

        q.pop();

        // Up down left right
        for (int k = 0; k < 4; k++)
        {
            int new_i = i + row[k];
            int new_j = j + col[k];

            if (valid(new_i, new_j, N, M) && A[new_i][new_j] && !visited[new_i][new_j]) // A[new_i][new_j] next node jaha ja rahe hai wo 1 hai ki nahi, !visited[new_i][new_j]: aur visited nahi hona chahiye.
            {
                if (new_i == X && new_j == Y)
                    return step + 1; // Found answer

                visited[new_i][new_j] = 1;
                q.push({new_i, {new_j, step + 1}});
            }
        }
    }
    return -1; // ans not found.
}

int main()
{
    vector<vector<int>> A = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 1, 1, 0}};
    
    int N = 4, M = 5;
    int X = 3, Y = 1; // Destination coordinates

    int steps = shortestDestination(N, M, A, X, Y);

    if (steps != -1)
        cout << "Shortest path is " << steps << " steps." << endl;
    else
        cout << "Destination not reachable." << endl;

    return 0;
}

```

Optmizing  the solution :- 
1. Visited Array :- Without using visited array we can solve the problem, So if jinko visited kar liye unko 0 banate chale jayenge , so ki hamko pata chalte jayega ki jinko ek bar visit kar chuka hu unko dobara visit n kare. 
2. Step :-  Step ko daalne ki zarurat he nahi hai queue mai, And we know ki BFS levek wise traverse karta hai. So iske liye ek count variable le lenge aur isme q.size ko daal denge jab tak count exist karega tab kaam karte jayenge, khatam hone ke baad count phir se calculate ho jayega, phir se uske ander queue ka naya size aa jayega. 

Time Complexity :- n*m
Space Complexity :-  Queue data structure . So Queue kitna data le sakta hai, min(N,M) wo iski space Complexity ho jayega. 
Note : Agar same no ho toh waha bfs lagana useful hota hai. 

### Knight Walk :- N*N
8*8 ka chess board diya hua hai hamko jisme ek source node jaha ghoda khada hai aur hamko target diya gaya hai jaha ghoda ko pahuchna hai, so kitne minmum step mai pahuch jayega. So ghoda 2.5 kadam chalta hai.
#### Note :- Agar hamko minimum step bole batane ke liye toh hamesha BFS ko he prefer karte hai.

So isko samjhne ke liye ham apne pass 8*8 ka matrix jaha source hai waha se sari possibility ke liye try karenge, ghoda ki chaal ki aur usko mark kisi ek color ya symbol se kar lenge taaki hamko pata chal jaye ki yaha hai single step mai pahuch ja rahe hai, and un sari possiblity se aage bhi ghode ke next kadam ko mark karenge with some another sign until we got the destination. 

Dfs would be not a good approch as it traverse in each neghbour and neugbour as go in depth utill all the node of that neighbour is visited so we need there mat may chances that ki wo right path he choose kare so ki we got a optumized ans or it may increse the time complexity of the program.
Whereas in bfs we visit all the neighbour of first node than neighbour of thier and so on.

Row[8]-{2,-2,-2,-2,1,-1,1,-1}  
Col[8]-{1,-1,1-1,2,2,-2,-2}

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int col[8] = {1, -1, 1, -1, 2, 2, -2, -2};

bool valid(int i, int j, int n)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}

int minStepToReachTarget(vector<int> &knightPos, vector<int> &TargetPos, int N)
{

    // Questtion mai 1 based indexing hai, so
    knightPos[0]--;
    knightPos[1]--;
    TargetPos[0]--;
    TargetPos[1]--;

    // Agar source node he target node ho toh
    if (TargetPos[0] == knightPos[0] && TargetPos[1] == knightPos[1])
        return 0;

    queue<pair<int, int>> q;
    // Chessboard
    vector<vector<bool>> chess(N, vector<bool>(N, 0));
    q.push({knightPos[0], knightPos[1]}); // Jaha hai uski position
    chess[knightPos[0]][knightPos[1]] = 1;

    int step = 0;

    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 8; k++)
            {
                int New_i = i + row[k];
                int New_j = j + col[k];

                if (valid(New_i, New_j, N) && !chess[New_i][New_j])
                {
                    if (New_i == TargetPos[0] && New_j == TargetPos[1])
                        return step + 1;
                    chess[New_i][New_j] = 1;
                    q.push({New_i, New_j});
                }
            }
        }
        step++;
    }
    return -1; // answer not found
}

int main()
{
    int N = 30;
    vector<int> knightPos = {1, 1};
    vector<int> targetPos = {30, 30};

    cout << "Minimum steps: " << minStepToReachTarget(knightPos, targetPos, N) << endl;
    return 0;
}
```

Time and space Complexity :- Nsq

### Find Whether Path exist :- 
Ek 2d matrix diya gaya hoga , and we have different no in it 0,1,2,3. Where 0= source, 2=dest, 3=Blank, 0=Wall. So hamko 1 se 2 par jana hai aur ham sirf 3 ke through he travel kar sakte hai. 
So kya ham dest par pahuch sakte hai, ues or no. 
We can use both BFS and DFs. 
Condition to move :-  left-right up-down

BFS :- 
While traversing jisko traverse kar lenge usko 0 bana denge so ki dobara traverse karne ke zarurat n pade. 

Code Implementation
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Charon directions (Up, Down, Left, Right)
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

bool isValid(int r, int c, int N, int M) {
    return (r >= 0 && r < N && c >= 0 && c < M);
}

bool isPathPossible(vector<vector<int>>& grid) {
    int N = grid.size();
    int M = grid[0].size();
    
    queue<pair<int, int>> q;
    
    // 1. Pehle Source (1) aur Destination (2) ki position dhoondhte hain
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1) { // Source mil gaya
                q.push({i, j});
                grid[i][j] = 0; // Mark visited by making it a wall
            }
        }
    }

    // 2. BFS Start
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // Charon taraf check karo
        for (int i = 0; i < 4; i++) {
            int nr = r + rowDir[i];
            int nc = c + colDir[i];

            if (isValid(nr, nc, N, M)) {
                // Agar Destination (2) mil gaya
                if (grid[nr][nc] == 2) return true;

                // Agar Blank path (3) hai, toh wahan jao
                if (grid[nr][nc] == 3) {
                    grid[nr][nc] = 0; // Mark visited (make it wall)
                    q.push({nr, nc});
                }
            }
        }
    }
    
    return false; // Sab explore kar liya par 2 nahi mila
}

int main() {
    // 1: Source, 2: Destination, 3: Path, 0: Wall
    vector<vector<int>> matrix = {
        {3, 3, 0, 2},
        {1, 3, 0, 3},
        {0, 3, 3, 3},
        {0, 0, 0, 0}
    };

    if (isPathPossible(matrix)) 
        cout << "Path Exists (Yes)" << endl;
    else 
        cout << "Path Does Not Exist (No)" << endl;

    return 0;
}
```