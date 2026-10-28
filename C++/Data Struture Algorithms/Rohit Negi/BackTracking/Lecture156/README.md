## Backtracking :-
In tarah ke question ko dekh kar jo bhi approch mind mai aata hai wahi backtracking hota hai. 

### N- queen:-
N*N size ka chess board hoga hamare pass, aur hamare pass N no. of queen present honge. So ab N queen ko chessboard mai rakhana hai is tarah se ki ki bhi do queen same row, same col aur same diagonal mai bhi nahi hona chahiye. Means ki ham isko ghode jaise chalta hai us postion par place par rakh de queens ko toh solution mil jayega. 

So pahle ek queen ko pahle postionpar rakh do, uske baad next queen ko next row mai rakhane ki try karo kyuki unko ham same row nahi rakh sakte , agar same col then avoid row ke next mai jao check karo kya same diagonal toh nahi if yes then check for next in row if no then queen ko rakh do.
So Agar queen ko rakhte samay hamko uske next row mai queen ki position nahi mil raha hai then, hamko next row mai jane ke zarurat nahi hai, phir wapas jayenge iske pahle wali queen ke pass usko check karenge ki next postion present row mai kaha rakh sakte hai, pahle wali queen ko. So ab phir se apni queen ko next row mai rakhane ke liye apni condition ko match karenge, if satisfied then queen ko set kar denge. If set nahi kar pa rahe then uski pahle queen ko jakar check karenge apni condition ko , if not then uske pahle queen ko and so on. 

So if solution found then isko store karke rakh lo, aur next optimal  soltion ko  find karo. So iske jitne bhi solution possible hai unko lakar dena hai. Jab tak sare possibilties khatam nahi ho jati means ki sare queen har jagah rakh ke try kar liya like 1st queen apni puri rows ko travel kar li ab aage nahi bad sakti, then jitna bhi possible solution hamko mila hai wahi answer hoga . 

Finding Solution using Graph :- 
Hamne abhi jo bhi kiya usko graph ke through present kardo. Agar Graph ke through ham apni problem ko try karenge toh ye  visually dekh payenge ki dfs kaise lag raha hai. 
Agar queen ko rakhte samay jitni bar correct position mil ja rahi hai utni baar call kar rahe hai, aur utne no of matrix ko ham graph mai show kr rahe hai. 
So kya har baar call kar rahe toh hamko actually mai chessboard banane ke zarurat hai, so ham apne chess board ko as reference bhej denge. 

Conditions :-
Same row :- Same row's wali problem ko toh ham solve kar denge as another row mai chale jayenge.
Same Col :- Iske liye ham array lenge n size ka , so ye represent karega ki represent kar raha hai ki particukar col mai queen rakhi hui hai so ham ya nahi rakh sakte. 
Same Diagonal :- iske liye hamko manually check karna padega. So hamko uppar diagonal mai check karane ki zarurat hai kyuki niche wale diagonal mai toh koi element hoga he nahi. 

Code Implementation :- 
```
#include <iostream>
#include <vector>
using namespace std;

bool check(int n, vector<string> &Board, int i, int j)
{
    // Upper left Diagonal mai Q, present nahi ho
    int row = i, col = j;
    while (row > -1 && col > -1)
    {
        if (Board[row][col] == 'Q')
            return 0;

        row--, col--;
    }
    // Upper right Diagonal mai Q, present nahi ho
    row = i, col = j;
    while (row > -1 && col < n)
    {
        if (Board[row][col] == 'Q')
            return 0;
        row--, col++;
    }

    return 1;
}

void find(int row, int n, vector<vector<string>> &ans, vector<string> &Board, vector<bool> &column)
{
    // Base Case
    if (row == n)
    {
        ans.push_back(Board);
        return;
    }

    // Put queen at any n position
    for (int j = 0; j < n; j++)
    {
        if (column[j] == 0 && check(n, Board, row, j)) // check():- diagonal same hai ki nahi
        {
            column[j] = 1;
            Board[row][j] = 'Q';
            find(row + 1, n, ans, Board, column);
            // Agar next row mai, queen ko nahi rakh pa rahe then , apni purani quenn ke postion ko phir se set karna hoga so
            column[j] = 0;
            Board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueen(int n)
{
    vector<vector<string>> ans;
    vector<string> Board(n);
    // Itially board dot se  filled hoga
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Board[i].push_back('.');

    vector<bool> column(n, 0);

    find(0, n, ans, Board, column);

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<string>> solutions = solveNQueen(n);

    cout << "Total Solutions for " << n << "-Queen: " << solutions.size() << endl
         << endl;
    for (auto sol : solutions)
    {
        for (string row : sol)
        {
            cout << row << endl;
        }
        cout << "-----------------" << endl;
    }
    return 0;
}
```

Time Complexity :- N! 
Space Complexity :-  N*N Board Size

Optimizing the Code :- 
So diagonal ko ham manually jakar check kar rahe wahi row aur col lo constant time mai check kar le rahe hai. So ab diagonal ko constant time mao karne ke kosis karenge. 

Right Diagonal ke liye :-  row + col kar rahe hai , Is chiz ko karke Apne Board par kar sakte hai, so tab conclude kar pa rahe hai ki is tarah sare diagonal ki value same aa rahi, so agar ek bhi jagah like 4 agar hamne 4 par Q rakh diya then kisi bhi 4 par Q nahi aa sakti. So ab Ek array le lenge agar kisi bhi jagah rakh rahe hai tab uski diagonal value ki postion ko mark 1 kar denge. Jis se chech kar paaye ki ham is postion par value nahi rakh sakte. Aur ye array ka size ? If NN ka array then 2*N-1 size ka hamara array hoga. 
Diagonal ki value same kyu aa rahi? Kyuki jab ham apne diagonal par rahe then row+1 and col -1 ho raha , at the end balance out ho ja raha hai. 

Left Diagonal ke liye:- So agar ham notice kare toh agar apane diagonal ja rahe tab row+1 aur col+1 dono ho rha hai, So ab ham kya kare ki ye jo opertion hai wo contant rahe along the diagonal, iske liye col - row kar denge tab hamko left diagonal mai same value mil jayegi. 
So agar diagonal same ho jati hai then kisi bhi ek postion par queen aati hai then marked it 1 in the array, so ki hamko pata chal jaye ki ham position par value rakh chuke hai.
So hamko yaha value -ve mai bhi mil rahi hai so kaise apne index ko khojenge marked 1 karne ke li liye. So isko positive banane ke liye n-1 ko col aur rows mai add kar denge . 
Note :- N-1 add karne se -ve positive mai badal jayega aur positive mao n-1 add jo jayega. 

Optimized NQueen 
```
#include <iostream>
#include <vector>
using namespace std;

void find(int row, int n, vector<vector<string>> &ans, vector<string> &Board, vector<bool> &column, vector<bool> &LeftDia, vector<bool> &RightDia)
{
    // Base Case
    if (row == n)
    {
        ans.push_back(Board);
        return;
    }

    // Put queen at any n position
    for (int j = 0; j < n; j++)
    {
        if (column[j] == 0 && LeftDia[n - 1 + j - row] == 0 && RightDia[row + j] == 0) //  diagonal same hai ki nahi
        {
            column[j] = 1;
            Board[row][j] = 'Q';
            LeftDia[n - 1 + j - row] = 1;
            RightDia[row + j] = 1;
            find(row + 1, n, ans, Board, column, LeftDia, RightDia);
            // Agar next row mai, queen ko nahi rakh pa rahe then , apni purani quenn ke postion ko phir se set karna hoga so
            column[j] = 0;
            Board[row][j] = '.';
            LeftDia[n - 1 + j - row] = 0;
            RightDia[row + j] = 0;
        }
    }
}

vector<vector<string>> solveNQueen(int n)
{
    vector<vector<string>> ans;
    vector<string> Board(n);
    vector<bool> LeftDia(2 * n - 1, 0);
    vector<bool> RightDia(2 * n - 1, 0);
    // Itially board dot se  filled hoga
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Board[i].push_back('.');

    vector<bool> column(n, 0);

    find(0, n, ans, Board, column, LeftDia, RightDia);

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<string>> solutions = solveNQueen(n);

    cout << "Total Solutions for " << n << "-Queen: " << solutions.size() << endl
         << endl;
    for (auto sol : solutions)
    {
        for (string row : sol)
        {
            cout << row << endl;
        }
        cout << "-----------------" << endl;
    }
    return 0;
}
```

### M Coloring Problem :- 
M ki kuchh value diya hoga aur bolrga ki , jisme condition ye rahega ki adjecent node same color kr nahi ho sakte. So hamre pass graph mai N no. of nodes honge , so kya M no. of color se isko color kar sakte hai ki nahi. 

Basic Approch :- 
So basically nodes ko pakda aur ek color dedo, phir uske neighbour mai  jao different color dedo, uske neighbour mai jao aur manually chack karo aur ensure karo ki yaha kon sa  different color ho uske neighbour se. So agar neighbour  visited or colored node milta hai then wapas aa jao. 
DFS apply karo apne condition ke according color do, agar visited hai ya colored hai then wapas jao until koi aisa node nahi milta jo colored nahi hai, if colored dena possible nahi than uske parent node ke pass jao aur bolo ki change your color I am unable to give the color to my neighbour. So ye bhi apne parent ke pass jayega agar color nahi de paayenge tab. 

Jab  visited mil raha hai then wapas ja rahe tab 1 assign kar de rahe hai ki hamko color mil chuka hai, jab koi bhi colored nahi de pa rahe hai then apne parent ko 0 assign kar de rahe hai which means ki ham color nahi de pa rahe hai. 
Visited kab mil raha jab kisi node ke sare neighbour visited mil ja rahe hai. 

Pseudo code :- 
1. Check each color  there
     1. Particular color assigned when these color is not assigned to any  neighbour. 
     2. Assigned that color to the node
     3. Go to the adjecent/neighbour jo colored/visited nahi hai. 
     4. If all the neighbour of the node are colored then return 1
     5. Check for another color
2. If saare color check karne ke baad Color assined nahi ho pa raha hai then return 0

Code Implementation :- 
```
#include <iostream>
#include <vector>
using namespace std;

bool DFS(int node, vector<int> &color, bool graph[101][101], int m, int n)
{
    //  Try Each Color one by one
    for (int i = 0; i < m; i++)
    {
        // No Adjecent node should have these color
        bool IsPossible = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] == 1 && color[j] == i)
            {
                IsPossible = 0;
                break;
            }
        }

        if (IsPossible == 0)
            continue; // Ab color ko chod kar next color try karo

        color[node] = i; // Assign color to node if IsPossible is 1

        //  Go to the adjecent node, whom color is not assigned
        IsPossible = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] == 1 && color[j] == -1) // Agar adjecnt exist karta hai aur usko color nahi mila hai then
            {
                if (!DFS(j, color, graph, m, n)) // If color not assined to neighbour, then go for next color
                {
                    IsPossible = 0;
                    break;
                }
            }
        }

        //  Agar kisi bhi neighbour ko color assign nahi hua then isPossible 0 hoga aur hamko parent ko color change karna hoga
        if (IsPossible == 1)
            return 1;

        // If not colored then ab apne parent ke pass jao uske dusre color assign karo
        color[node] = -1;
    }

    return 0;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, -1);

    for(int i=0;i<n;i++)
    {
        if(color[i]==-1 && !DFS(i, color, graph, m, n))
        return 0;

        return 1;
    }
}

int main() {
    int n = 4; // Nodes
    int m = 3; // Colors available
    bool graph[101][101] = {0};

    // Example: Square graph (0-1, 1-2, 2-3, 3-0) aur diagonal (0-2)
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;
    graph[0][2] = graph[2][0] = 1;

    if (graphColoring(graph, m, n))
        cout << "Solution Exists: Graph can be colored with " << m << " colors." << endl;
    else
        cout << "Solution does not exist." << endl;

    return 0;
}
```
Time Complexity :- (m*n)^n
Space Complexity :-  Height of tree =  n 

2. 2nd Method :-  M Coloring Problem : Parmutation Combination check karenge.
So isme pahle node (0) ko pakdo so ab hamare pass m option hai isko assign karne ke liye koi ek color de dedo phir 1 ko pakdo aur yaha bhi hamare pass 3 option assign karene ke so isme o jo adjecent mai hai wo color chod kar koi bhi color dedo, phir 2 node par jao and do so on. Jab sare color assign ho jayenge tab return karte jayenge. 
Note : Har node ke pass option hai M no. of color ka. Aur isme se koi ek choose kar le rahe hai. 

Code Implementation :- 
```
#include <iostream>
#include <vector>
using namespace std;

bool find(int node, bool graph[101][101], int n, int m, vector<int> &color)
{
    //  Base condition :- 
    if(node==n)
    return 1;

    // Color the node with M color
    for (int i = 0; i < m; i++)
    {
        // Check if adjecent nodes have not the same color
        bool IsPossible = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] && color[j] == i)
            {
                IsPossible = 0;
                break;
            }
        }

        // We can assign i color to this node
        if (IsPossible == 1)
        {
            color[node] = i;
            if (find(node + 1, graph, n, m, color)) // agar find 1 return karta hai then
                return 1;

            //  Agar find 1 nahi hai then
            color[node] = -1; // Check for another color
        }
    }
    return 0;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, -1);
    return find(0, graph, n, m, color);
}

int main()
{
    int n = 4; // Nodes
    int m = 3; // Colors available
    bool graph[101][101] = {0};

    // Example: Square graph (0-1, 1-2, 2-3, 3-0) aur diagonal (0-2)
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;
    graph[0][2] = graph[2][0] = 1;

    if (graphColoring(graph, m, n))
        cout << "Solution Exists: Graph can be colored with " << m << " colors." << endl;
    else
        cout << "Solution does not exist." << endl;

    return 0;
}
```

### Sodoku Solver 
Hamko ek board diya hoga jiska size 9*9 ka hoga. So hamko 1 to 9 no. ko badna hai is tarike se ki same row mai koi bhi element repeat n kare. and same col mai bhi no. repeat nahi hone chahiye. Same block mai bhi same no. should not reapeat.
Agar hamre conditions match nahi karte aur ham value nahi bhar pa rahe hai that means ki pichhla step mai kahi wrong bhara hai.   

Blocks ko same no present hai ki nahi ye kaise check karenge?  
1. row : 0-8 row diye,row ko ke liye{ 0,1,2} -> 0 ye hamesha O se check karna start karega, similarly {3,4,5}->3 and {6,7,8}-> 6. 
-> Formula :- (i,j) => i = (i/3)*3 , j = (j/3)3   where i and r are the index value of current node.
2. col : iske liye bhi same logic use karenge. 
Note : Block size 3 * 3 ka

Base Case :- 
Apne row ko change karte rahenge hamko kaise pata chale ga ki ab next row mai jana hai. 
1. (i , j+1) -> row ko change kar rahe for the next element 
2. when j==9 then it means ki hamko ab next row mai jana hai so (i+1,0). 
3. Jab i==9 ho jaye means toh ham apne searching ko rok denge aur finally return ho jayenge. i==9 means ki hamne sare node ko cover kar liye hai. 

Return 0 :- ka matalab hai ki change karne ki zarurat hai,
return 1 :- not need to change the value. 

Time Complexity :- 

Code Implementation :- 
```
```