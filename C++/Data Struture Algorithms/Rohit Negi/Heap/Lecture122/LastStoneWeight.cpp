#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight( vector<int> &stones)
{
    // Max Heap
    priority_queue<int> p;
    for (int i = 0; i < stones.size(); i++)
    {
        p.push(stones[i]);
    }
    while(p.size()>1)
    {
        int weight = p.top();
        p.pop();
        weight-=p.top();
        p.pop();

        if(weight)  // 0 push n ho
        p.push(weight);
    }

    return p.empty()? 0:p.top();
  
}

int main()
{
    vector<int> B2 = {2, 4, 6, 8, 10};
    
    cout << " Last Stone Weight "<< lastStoneWeight(B2) << endl;

    return 0;
}