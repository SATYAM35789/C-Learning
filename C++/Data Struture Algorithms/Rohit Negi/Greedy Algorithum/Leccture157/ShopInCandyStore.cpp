#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> candyStore(int candies[], int n, int k)
{
    sort(candies, candies + n); // ascending order
    int min_amount = 0, max_amount = 0;
    int i = 0, j = n - 1;

    // Calculating minimum Amount
    while (i <= j)
    {
        min_amount += candies[i];
        i++;
        j -= k;
    }

    //  Calculating Maximum amount
    i = n - 1, j = 0;
    while (i >= j)
    {
        max_amount += candies[i];
        i--;
        j += k; // starting ke k elemnt ko le lo
    }

    vector<int> ans;
    ans.push_back(min_amount);
    ans.push_back(max_amount);
    return ans;
}

int main()
{
    int candies[] = {3, 2, 1, 4};
    int n = 4;
    int k = 2;

    vector<int> result = candyStore(candies, n, k);

    cout << "Minimum amount: " << result[0] << endl;
    cout << "Maximum amount: " << result[1] << endl;

    return 0;
}