#include <iostream>
#include <vector>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int start = 0, end = 0, mid, ans, n = piles.size();
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += piles[i];
        end = max(end, piles[i]);
    }
    start = sum / h;
    if (start == 0)
        start = 1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        // Mid amount of bananna to consume in one hours

        // Calculating time , mid amount time need in one hours, then sabko khane mai kitna time?
        int total_time = 0;
        for (int i = 0; i < n; i++)
        {
            total_time += piles[i] / mid;
            if (piles[i] % mid) // point mai answer aayega toh ek se bada do
                total_time++;
        }

        if (total_time > h)
        {
            // then ki hamko aur kela khana hai, so right side move karo
            // Jayda time lag raha hai means ki ham kam kela kha rahe hai, no of kela khanna badana hoga
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}