#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

// Pair ko 'temp' naam de diya hai taaki code simple rahe
typedef pair<int, pair<int, int>> temp;

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // Min Heap banaya
    priority_queue<temp, vector<temp>, greater<temp>> pq;

    // 1. (0,0) index push karo
    pq.push({mat[0][0], {0, 0}});

    int result = 0;
    bool visited[MAX][MAX] = {false};
    visited[0][0] = true;

    // 2. K baar process karo
    while (k--)
    {
        temp top = pq.top(); // Ab 'temp' type ka variable
        pq.pop();

        result = top.first;        // value
        int r = top.second.first;  // row
        int c = top.second.second; // col

        // 3. Right side push karo
        if (c + 1 < n && !visited[r][c + 1])
        {
            pq.push({mat[r][c + 1], {r, c + 1}});
            visited[r][c + 1] = true;
        }

        // 4. Down side push karo
        if (r + 1 < n && !visited[r + 1][c])
        {
            pq.push({mat[r + 1][c], {r + 1, c}});
            visited[r + 1][c] = true;
        }
    }
    return result;
}

int main()
{
    int n = 4;
    int k = 8;

    int mat[MAX][MAX] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50}};

    cout << "Kth smallest element: " << kthSmallest(mat, n, k) << endl;

    return 0;
}