#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
{
    // Create Adjencency list
    vector<int> adj[n];

    for (int i = 0; i < relations.size(); i++)
    {
        // Convert them into 0 based indexing -1
        adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
    }
    vector<int> InDeg(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < adj[i].size(); j++)
            InDeg[adj[i][j]]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (InDeg[i] == 0)
            q.push(i);

    // CourseTime :- Maximum Time to complete privous course ko store karta
    vector<int> CourseTime(n, 0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;

            if (!InDeg[adj[node][j]])
                q.push(adj[node][j]);

            // Maximum Time To Complete Previous course and present Course Time
            CourseTime[adj[node][j]] = max(CourseTime[adj[node][j]], (CourseTime[node] + time[node]));
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, CourseTime[i] + time[i]); // CourseTime[i] :- Maximum Time To Complete Previous course  , time[i] :- present Course Time
    }
    return ans;
}

int main()
{
    int n = 3;
    vector<vector<int>> relations = {{1, 3}, {2, 3}};
    vector<int> time = {3, 2, 5};

    /*
       Logic:
       Course 1 (3 months) and Course 2 (2 months) can run in parallel.
       Course 3 (5 months) depends on both.
       Max time to reach Course 3 = max(3, 2) = 3 months.
       Total time = 3 (reach) + 5 (Course 3 itself) = 8 months.
    */

    cout << "Minimum time to complete all courses: " << minimumTime(n, relations, time) << endl;

    return 0;
}