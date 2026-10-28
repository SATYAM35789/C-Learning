#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &array, int n)
{
    // Sum of all element in a array
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        sum += array[i];
    //  Sum of n element
    int sum1 = 0;
    sum1 = n * (n - 1) / 2;

    int missingTerm = sum1 - sum;

    return missingTerm;
}