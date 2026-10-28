#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

// Helper struct to store element and its position
struct Element
{
    int val, r, c;

    // Min-heap banane ke liye 'greater than' operator overload
    bool operator>(const Element &other) const
    {
        return val > other.val;
    }
};

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // Min Heap
    priority_queue<Element, vector<Element>, greater<Element>> pq;

    // Visited array taaki duplicate entries na ho
    bool visited[MAX][MAX] = {false};

    // 1. Sabse chhota element (0,0) push karo
    pq.push({mat[0][0], 0, 0});
    visited[0][0] = true;

    int result = 0;

    // 2. K baar process karo
    for (int i = 0; i < k; i++)
    {
        Element current = pq.top();
        pq.pop();

        result = current.val;
        int r = current.r;
        int c = current.c;

        // 3. Right side wala element check karo
        if (r < n && c + 1 < n && !visited[r][c + 1])
        {
            pq.push({mat[r][c + 1], r, c + 1});
            visited[r][c + 1] = true;
        }

        // 3. Down side wala element check karo
        if (r + 1 < n && c < n && !visited[r + 1][c])
        {
            pq.push({mat[r + 1][c], r + 1, c});
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

    int result = kthSmallest(mat, n, k);
    cout << k << "kth smallest element is: " << result << endl;

    return 0;
}