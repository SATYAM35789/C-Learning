//  Indian Coin Change Problem
#include <iostream>
#include <vector>
using namespace std;

vector<int> minPartition(int n)
{
    int currency[] = {2000, 500, 100, 50, 20, 10, 5, 2, 1};
    int notes = 0, i = 0;
    vector<int> ans;
    while (n)
    {
        notes = n / currency[i];
        while (notes--)
        {
            ans.push_back(currency[i]);
        }
        n %= currency[i];
        i++;
    }
    return ans;
}

int main()
{
    int amount = 143;
    vector<int> change = minPartition(amount);

    cout << "Minimum notes for " << amount << ": ";
    for (int note : change)
    {
        cout << note << " ";
    }
    return 0;
}