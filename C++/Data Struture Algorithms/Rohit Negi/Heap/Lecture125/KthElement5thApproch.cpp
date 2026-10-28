#include <iostream>
using namespace std;

#define MAX 100

// Helper function: O(N) complexity mein count karta hai
int countElements(int mat[MAX][MAX], int n, int mid)
{
    int count = 0;
    int row = 0, col = n - 1; // Top-right corner se start

    while (row < n && col >= 0)
    {
        if (mat[row][col] <= mid)
        {
            // Agar element chhota hai, toh us column ke saare elements chote honge
            count += (col + 1);
            row++; // Next row check karo
        }
        else
        {
            // Agar bada hai, toh left column mein jao
            col--;
        }
    }
    return count;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Count karo ki mid se chote kitne elements hain
        int count = countElements(mat, n, mid);

        if (count >= k)
        {
            // Possible answer mil gaya, ab chhota search karo
            ans = mid;
            high = mid - 1;
        }
        else
        {
            // mid chhota hai, range badhao
            low = mid + 1;
        }
    }
    return ans;
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

    cout << k << "kth smallest element is: " << kthSmallest(mat, n, k) << endl;

    return 0;
}