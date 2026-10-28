#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &disc, vector<int> &low, stack<int> &s, vector<bool> &InStack, vector<vector<int>> &ans, int timer)
{
    visited[node] = 1;
    disc[node] = low[node] = timer;
    timer++;
    s.push(node);
    InStack[node] = 1;

    // Visiting neighbour
    for (int j = 0; j < adj[node].size(); j++)
    {
        int neigh = adj[node][j];
        if (!visited[neigh])
        {
            timer++;
            DFS(neigh, adj, visited, disc, low, s, InStack, ans, timer);
            low[node] = min(low[node], low[neigh]);
        }
        else
        {
            // If it is present in the stack or not
            if (InStack[neigh])
                low[node] = min(low[node], disc[neigh]);
        }
    }
    // Wapas jane ka time aa gaya hai
    if (disc[node] == low[node])
    {
        vector<int> temp;
        while (!s.empty() && s.top() != node)
        {
            temp.push_back(s.top());
            InStack[s.top()] = 0;
            s.pop();
        }
        temp.push_back(node);
        InStack[node] = 0;
        s.pop();

        // Sorted temp : so ki data row mai sorted form mai rahe
        sort(temp.begin(), temp.end());

        ans.push_back(temp);
    }
}
vector<vector<int>> tarjans(int v, vector<int> adj[])
{
    vector<vector<int>> ans;
    vector<int> disc(v);
    vector<int> low(v);
    vector<bool> visited(v, 0);
    stack<int> s;
    vector<bool> InStack(v, 0); // stack ke ander kon kon se element present hai
    int timer;

    // DFS Call
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            DFS(i, adj, visited, disc, low, s, InStack, ans, timer);
    }

    sort(ans.begin(), ans.end()); // 2d array ko bhi sort kar diye col wise
    return ans;
}

int main()
{
    int v = 5;
    vector<int> adj[5];
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[0].push_back(3);
    adj[3].push_back(4);

    vector<vector<int>> result = tarjans(v, adj);

    for (auto component : result)
    {
        for (int node : component)
            cout << node << " ";
        cout << endl;
    }
    return 0;
}