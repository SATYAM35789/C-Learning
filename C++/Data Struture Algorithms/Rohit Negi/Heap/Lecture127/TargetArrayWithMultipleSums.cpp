#include <iostream>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

bool isPossible(vector<int> &target)
{
    // Max Heap : kyuki sabse pahle , badi value ko bahar nikal rahe hai
    priority_queue<int> p;
    int sum = 0;

    for (int i = 0; i < target.size(); i++)
    {
        p.push(target[i]);
        sum += target[i];
    }

    int MaxElement, RemSum, Element;
    while (p.top() != 1) // jaise he top ki value 1 hoti hai means ki vector mai one one present ho
    {
        MaxElement = p.top();
        p.pop();
        RemSum = sum - MaxElement;

        // Edge cases :- MaxElement = RemSum -Element
        if (RemSum <= 0 || RemSum >= MaxElement)
            return 0;

        Element = MaxElement - RemSum;
        // Updating Sum Values
        sum = RemSum + Element;
        p.push(Element);
    }

    return 1;
}