#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string findOrder(string dict[], int N, int K) // N : No. of words , K= No. of character from starting alphabates
{
    //  Adjecency list bana bana lo
    vector<int> adj[K]; // without repeating same character k ke barabar he honge
    vector<int> inDeg(K, 0);

    for (int i = 0; i < N - 1; i++) // N words hai, compairison ek kam he hoga
    {
        string str1 = dict[i], str2 = dict[i + 1];
        int j = 0, k = 0; // j: starting index of str1 , k: starting index of str2 ko.

        // Compairsion : Jab tak different character n mile
        while (j < str1.size() && k < str2.size() && str1[j] == str2[k])
            j++, k++;

        // Handling this casse too :- cde cdeb -> cde pahle aana chahiye. So string 1 ke khatam ho jane ke baad compairsion karne koi matlab nahi, hamko nahi pata chalega konsa char pahe hai
        if (j == str1.size())
            continue;
        // Agar different mile, toh ruk jao
        adj[str1[j] - 'a'].push_back(str2[k] - 'a'); // character ko int ke form mai daal rahe jaisa hum discussion kiya tha

        // Indegre
        inDeg[str2[k] - 'a']++; // Jidhar edge ja rahi uski indegree bada rahe hai.
    }

    // Kahn's Algorithum
    // Queue
    queue<int> q;
    for (int i = 0; i < K; i++)
        if (inDeg[i] == 0)
            q.push(i);

    // Storing the character in String
    string ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        char c = 'a' + node;
        ans += c;

        // uske neighbour ko ek ek se kam kardo
        for (int j = 0; j < adj[node].size(); j++)
        {
            inDeg[adj[node][j]]--;
            if (!inDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }
    return ans;
}

int main()
{
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    // Based on dictionary:
    // 'b' comes before 'a' (from baa, abcd)
    // 'd' comes before 'a' (from abcd, abca)
    // 'a' comes before 'c' (from abca, cab)
    // 'b' comes before 'd' (from cab, cad)

    string result = findOrder(dict, N, K);

    cout << "Alien Alphabet Order: " << result << endl;

    return 0;
}
