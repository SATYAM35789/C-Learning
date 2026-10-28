#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
{
    // Adjecency list create karna
    vector<int> adj[N];

    for (int i = 0; i < P; i++)
    {
        adj[prerequisites[i].second].push_back(prerequisites[i].first); // {1,0} :- 0->1   where adj[prerequisites[i].second] =0   and push_back(prerequisites[i].first) :- ->1
    }

    // Kahn's Algorithum :-

    // 1. Indegree find karna :-
    vector<int> inDeg(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int neighbor = adj[i][j];
            inDeg[neighbor]++;
        }
    }

    // 2. Queue
    queue<int> q;
    for (int i = 0; i < N; i++)
        if (inDeg[i] == 0)
            q.push(i);

    // storing size of topological sort
    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        // uske neighbour ko ek ek se kam kardo
        for (int j = 0; j < adj[node].size(); j++)
        {
            inDeg[adj[node][j]]--;
            if (!inDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }
    return count == N; // Then return 1
}

int main()
{
    int N = 4; // 4 Courses (0, 1, 2, 3)
    int P = 3; // 3 Dependencies

    // Prerequisite pairs: {target, source} -> source to target
    // {1, 0} means 0 -> 1
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    if (isPossible(N, P, prerequisites))
        cout << "Success: All courses can be finished!" << endl;
    else
        cout << "Error: Cycle detected! Impossible to finish." << endl;

    return 0;
}