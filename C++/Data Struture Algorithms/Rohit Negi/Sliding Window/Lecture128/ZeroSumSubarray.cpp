// You can win a lot in life , if you are the last one to give up.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long int findSubarray(vector<long long int> &arr, int n)
{
    long long int total = 0; // Total no. of subarray , jiska sum 0 hai
    // Map : prifixSum , count
    unordered_map<long long int, long long int> m;
    long long int PrefixSum = 0;

    // Initailize by (0,1) :-  In case agar koi element nahi hai, toh means unka sum 0 hai
    // Value insert in map :- m[0] = 1;
    m[0] = 1;

    for (int i = 0; i < n; i++)
    {
        PrefixSum += arr[i];
        if (m.count(PrefixSum))
        {
            total += m[PrefixSum]; // count of prefixsum ko total mai add kardo
            m[PrefixSum]++;        // prefixSum ke count ko ek se increment kardo.
        }
        else
        {
            m[PrefixSum] = 1;
        }
    }
    return total;
}
// Unorsered Map :- It helps to customised the index means ki ham apne according index set kar sakte hai.

int main()
{
    // Example test case
    vector<long long int> arr = {0, 0, 5, 5, 0, 0};
    int n = arr.size();

    long long int result = findSubarray(arr, n);

    cout << "Total subarrays with sum 0: " << result << endl;

    return 0;
}