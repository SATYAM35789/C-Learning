### Covid Spread :- 
So isme hamko diya hua hai 2d form mai data, jisme block represent karta hai hai single room ko,isme value 0,1,2 diya hua hai, where 0 means ki us room mai koi nahi hai, 1 means normal patient present hai us room, mai, 2 represent ki waha koi covid patient present hai. Problem mai bol raha hai ki jo covid patient hai corona phailayega, corona wala up-down, right left corna phailayega inko phaila ne mai isko 1 unit of time.Agale unit time wo pne agal bagal wale  ko corona phaileyenge. 
So corona phailne mai purre hospital mai kitna time lagega, if ye possible nahi toh -1 return karna hai. 

So isme ham pahle starting ke agal bagal uske agal bagal corona phaila rahe the , so ye BFS approch use ho raha hai, ki ham tab tak corona phailte rahega jab tak pura na phail jaye ya phailne ka chances he n ho. 
Isme jisko corona hua hai pahle usko daalenge queue ke ander daalenge in (row,col) order mai, agar iske aas paas koi 1 or patient present hai, then usko queue mai daalo and nikalo, do so on. Karte jao jab tak queue khali n ho jaye, agar iske baad bhi 1 present hua array or hospital mai then -1 return kar denge. 
Note :- Jab corona phail raha hoga tabhi ham kisi corona patient ke dwara tabhi unit of time ko calculate karenge. or jisko last mai corona hua hai wo kisi ko corona toh nahi phailayega. 

Step :- 
1. Initially jinko corona hua hai unko queue ke ander daal do. Ek timer lelenge.
2. Left right up down agar koi patient(1) hai toh usko corona ho jayega, then usko bhi queue mai daal denge
3. Aur queue ke front ko pop kar denge. and do so on until queue is empty. 
timer :-Ye calculate karega ki 1 phase of corona mai jitne patient hai, wo sabhi next patient tak corona phaila de tabhi ek unit count karega. 


                // up
                if (hospital[i-1][j]==1 && i-1)
                {
                }
                // down
                if (hospital[i + 1][j] == 1)
                {
                }
                // left
                if (hospital[i][j - 1] == 1)
                {
                }
                // right
                if (hospital[i][j + 1] == 1)
                {
                }

  // To avoid segmentation fault and charo opertion ko ek sath excute karwa sakte hai
                int row[4] = {-1,1,0,0};
                int col[4] = {0,0,-1,1};

                for(int k=0;k<4;k++)
                {
                    if(hospital[i+row[k]][j+col[k]]==1)
                }

Note :- Is for loop mai ek ek karke sari conidtion satisfy kar sakti hai. So codemai nahi likhenge.


Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int r;
int c;

bool valid(int i, int j)
{
   return i>=0&&i<=r&&j>=0&&j<c;
}

int helpaterp(vector<vector<int>> hospital)
{
     r = hospital.size();
     c = hospital[0].size();

    queue<pair<int, int>> q;
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (hospital[i][j] == 2)
                    q.push(make_pair(i, j));

        int timer = 0;

        while (q.empty())
        {
            timer++;
            int curr_patient = q.size();
            while (curr_patient--) // jab tak curr_patient 0 ke barabar n ho jaye tab tak chalega
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                // Corona patient le pass 1 hai toh usko 2 banao aur queue mai daalo.
                // To avoid segmentation fault and charo opertion ko ek sath excute karwa sakte hai
                int row[4] = {-1, 1, 0, 0};
                int col[4] = {0, 0, -1, 1};

                for (int k = 0; k < 4; k++)
                {
                    // Normal patient milta hai
                    if (valid(i + row[k], j + col[k]) && hospital[i + row[k]][j + col[k]] == 1)
                    {
                        hospital[i + row[k]][j + col[k]] =2;
                        q.push(make_pair(i+row[k],j+col[k]));
                    }
                }
            }
        }
        // Checking koi patient bacha toh nahi hai
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(hospital[i][j]==1)
        return -1;

        return timer-1 ;   
    }
}

```
Time Complexity O(nm) :-  size of 2d array ka aa sakti hai worst case mai. 
space Complexity :- O(nm)  :- taking queue


### Find the number of Islands :- 
So yaha hamko 2d array diya hoga aur hamko puchhega ki isme no of islands kitne hai. Jisme 0 and 1 hai, 0 means water and 1 means land. 
Island formation condition :-  land ghera hua hoga pani or grid or boundary of 2d array ke. Iski connectivity left right,up down , diagonal se ho sakta hai. 
So generally 1 ko pakdo aur uske neighbour ko check karo kya wo island bana sakta hai or means kya uski value 1 hai then usko connect karlo karte jao jab tak exist karta hai(1 or land) 
Note : Yaha par BFS lag raha hai kyuki ham sari neighbour ki pahle visit kar rahe hau phir next visit karne ja rahe, Lakin def mai toh ek pakdte hai aur tab tak jate jate hau jab tak land khatam n ho jaye , phie wapas aate hue duri node ko visit karte hai.

Steps :-
1. Apne 2d array mai check karo, Agar 1 hai aur kisi aur island ka part hai then usko chod do 
2. Agar wo 1 hai aur kisi aur island ka part nahi hai then, BFDs/dfs mai karna start kardo
3. so  BFS lagate apne node ko pakdo pahle uske neighbour then uska neighbour jab tak possible hai land ko connect karna. 
4. Agar land connectivity khatam or land khatam then uske baad apne no of count ko bada do. isko starting bada denge. 

Note :- if one mila then usko queue mai daalo, queue ke bahar nikalo uske neighbour waale and do so on bahar nikalo , unke neighbour ko daalo.
Visited array :- Ye ensure karega ki jis neighbour ko ham queue ko ander daal chuke hai usko n daale. 
2. Queue khatm hone ke baad jaise he naya 1  mile then island ko ek se bada do. 

Without visited array ke ham kaise solve kar sakte hai?
So hamko pata hai ki 1 ke bagal agar koi 0 hai then ham us case ko ignore kar de rahe hai so ab ham yehi karenge jinko visit kar liye hai usko 0 bana denge ki ab hamko isko visit nahi karna hai.

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r;
int c;

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < r && j < c;
}

int numIslands(vector<vector<char>> &grid)
{
    r = grid.size();
    c = grid[0].size();

    queue<pair<int, int>> q;
    int count = 0;

    // check the character 1 in the grid
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                // Make 1 to 0 after visiting
                q.push(make_pair(i, j));
                grid[i][j] = 0;

                while (!q.empty())
                {
                    // row aur colume ko bahar nikalte hai, taki uski neighbour ko visit kar paye
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    q.pop();
                    // 8 Direction: 3 uppar, 3 niche aur 2 bagal mai check karna hai 1 hai ki nahi
                    int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
                    int col[8] = {-1, 0, +1, -1, 0, +1, -1. + 1};

                    // Moving in the direction
                    for (int k = 0; k < 8; k++)
                    {
                        // Valid :- Ensure ki ham 2d array ke , to segmentation fault.
                        if (valid(new_i + row[k], new_j + col[k]) && grid[new_i + row[k]][new_j + col[k]] == '1')
                        {
                            grid[new_i + row[k]][new_j + col[k]] = '0';
                            q.push(make_pair(new_i + row[k], new_j + col[k]));
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    // Test Case: Grid with 2 Islands (8-direction logic)
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '1'},
        {'1', '0', '0', '1', '1'},
        {'0', '0', '0', '0', '0'},
        {'1', '0', '1', '0', '1'}};

    int result = numIslands(grid);
    cout << "Total Number of Islands: " << result << endl;

    return 0;
}

```

### REplace O's With X's 
So us O ko replace karna hai , jo charo tarh se X se ghere honge, aur usko hamre ans mai return kardo. Agar Single O  nahi mil raha hai then set of O , surrounded by X haithen ham uslo bhi replace kar sakte hai.
1. Boundary O cannot be repllace by X. 
2. Jab bhi ham Set bana rahe hai, toh maximum ka set banana hai kyuki agar aisa nahi karte then O bagal mai he hoga means proper surrounded by X nahi hoga phir ham usko replace nahi kar payenge. 
3. Set mai agar ek bhi 0 boundary par hoga, then wo kabhi bhi replace nahi honge, X se. 

Approch :-  Boundary Traversal Only :-
Ham boundary se traverse karenge, check karenge ki kya Element 0 hai ya X , if X then Chod do, else if, 0 hai toh , usse related maximum of set kabhi bhi Replace nahi hoga. So Ab is information ko store krne ke liye ki ab Boundary O ko replace nahi kar sakte , ham ek 2d array lenge. So BFS lagayenge, node ke bagal check karo aur usko visited mark karo, agar aage bhi BFS possible hai then go on, if not then Phir boundary par traverse karte jao, ab agar o aaya toh check karo kya ye pahle se visited hai if yes then go for another if not then BFS apply karo. Jab boundary par ghum liye then Boundary par jo mile the unko chod ke sabko 1 bana do. 

Bina 2D array liye kya ham is problem ko solve kar sakte hai. 
Boundary wale O ko traverse karne ke baad is O ko change kaedo kisi aur character mai like T. Puri Boundary traverse karne ke baad, Sare O ko X mai convert kardo, aur sare T ko O mai. 

Code Implementation :- 
```#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r;
int c;

// 4 direction mai move karna hai
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

bool valid(int i, int j)
{
    return i >=0 && j >=0 && i < r && j < c;
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    r = n;
    c = m;

    // Apply BFS operator from border where 0 is present and replace with T

    queue<pair<int, int>> q;
    // First Row
    for (int j = 0; j < c; j++)
    {
        if (mat[0][j] == 'O')
        {
            q.push(make_pair(0, j));
            mat[0][j] = 'T';
        }
    }
    // First Col
    for (int i = 0; i < r; i++)
    {
        if (mat[i][0] == 'O')
        {
            q.push(make_pair(i, 0));
            mat[i][0] = 'T';
        }
    }
    // last row (Corner ko chhode traverse kar rahe hai)
    for (int j = 1; j < c; j++)
    {
        if (mat[r - 1][j] == 'O')
        {
            q.push(make_pair(r - 1, j));
            mat[r - 1][j] = 'T';
        }
    }
    //  last col
    for (int i = 1; i < r - 1; i++) // upper se ek aur nichhe ek ko chhod kar traverse kar rahe hai
    {
        if (mat[i][c - 1] == 'O')
        {
            q.push(make_pair(i, c - 1));
            mat[i][c - 1] = 'T';
        }
    }

    while (q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;

        q.pop();

        // 0 ke charo taraf dekh rahe hai kon kon se element present hai
        for (int k = 0; k < 4; k++)
        {
            if (valid(i + row[k], j + col[k]) && mat[i + row[k]][j + col[k]] == 'O')
            {
                mat[i + row[k]][j + col[k]] == 'T';
                q.push(make_pair(i + row[k], j + col[k]));
            }
        }
    }

    // Replace All 'O' with 'X' and all T with 'O'
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 'O')
                mat[i][j] = 'X';
            else if (mat[i][j] == 'T')
                mat[i][j] = 'O';
        }
    return mat;
}


int main() {
    int n = 4, m = 4;
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    vector<vector<char>> result = fill(n, m, mat);

    cout << "Resulting Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

```
