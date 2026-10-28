#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rotationCount(long long R, long long D)
{
    int ans = 0;
    int first, second;

    while (R)
    {
        //  Last value ko pick kar rahe hai
        first = R % 10;
        second = D % 10;
        R /= 10;
        D /= 10;

        ans += min(abs(first - second), 10 - abs(first - second));
    }
    return ans;
}

int main()
{
    long long current_lock = 1234;
    long long target_lock = 4321;

    cout << "Minimum rotations needed: " << rotationCount(current_lock, target_lock) << endl;

    return 0;
}