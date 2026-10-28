#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> height)
{
    int n = height.size();
    int leftMax = 0, rightMax = 0, maxHeight = height[0], index = 0, water = 0;

    //  Max Height of the building
    for (int i = 1; i < n; i++)
    {
        if (maxHeight < height[i])
        {
            maxHeight = height[i];
            index = i;
        }
    }
    // Left part
    for (int i = 0; i < index; i++)
    {
        if (leftMax > height[i])
            water += leftMax - height[i];
        else
            leftMax = height[i]; // updating leftMax
    }

    //  Right Part
    for (int i = n - 1; i > index; i--)
    {
        if (rightMax > height[i])
            water += rightMax - height[i];
        else
            rightMax = height[i]; // updating rightMax
    }

    return water;
}