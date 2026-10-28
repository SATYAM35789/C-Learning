#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    //  agar order sahi hai then waise return kardo, warna swap karke de dega
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    //  Sort it on the basis of end time ascending order
    vector<pair<int, int>> timer;
    for (int i = 0; i < n; i++)
        timer.push_back({start[i], end[i]});

    //  Sorting timer based on  end value
    sort(timer.begin(), timer.end(), comp);

    int total = 0; // kitni meeting karwa sakte hai

    int ending = -1; // end time of meeting ko store karke rakhega

    for (int i = 0; i < n; i++)
    {
        if (timer[i].first > ending) // Privious meeting end time should be less than starting of next meeting
        {
            total++;
            ending = timer[i].second;
        }
    }
    return total;
}
int main()
{
    // Example test case
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    int result = maxMeetings(start, end, n);

    cout << "Maximum number of meetings possible: " << result << endl;

    return 0;
}
// Bahut important concept yaha use kiye do different array hai unme se ek array ke basis par sorting karna hai, uske
//  according one array dusra array bhi sort hoga .