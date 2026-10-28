#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r;
int c;

bool valid(int i, int j)
{
    return i >= 0 && i <= r && j >= 0 && j < c;
}

int helpaterp(vector<vector<int>> hospital)
{
    r = hospital.size();
    c = hospital[0].size();

    queue<pair<int, int>> q;
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (hospital[i][j] == 2)
                    q.push(make_pair(i, j));

        int timer = 0;

        while (q.empty())
        {
            timer++;
            int curr_patient = q.size();
            while (curr_patient--) // jab tak curr_patient 0 ke barabar n ho jaye tab tak chalega
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                // Corona patient le pass 1 hai toh usko 2 banao aur queue mai daalo.
                // To avoid segmentation fault and charo opertion ko ek sath excute karwa sakte hai
                int row[4] = {-1, 1, 0, 0};
                int col[4] = {0, 0, -1, 1};

                for (int k = 0; k < 4; k++)
                {
                    // Normal patient milta hai
                    if (valid(i + row[k], j + col[k]) && hospital[i + row[k]][j + col[k]] == 1)
                    {
                        hospital[i + row[k]][j + col[k]] = 2;
                        q.push(make_pair(i + row[k], j + col[k]));
                    }
                }
            }
        }
        // Checking koi patient bacha toh nahi hai
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (hospital[i][j] == 1)
                    return -1;

        return timer - 1; // last patient kisi ko corana nahi phaila sakta, so uska unit add nahi hoga.
    }
}
// Segmentation fault :- Aise memory ko access karne ki kosis karna jisko hamri range se bahar hai. So hamko
// ensure karna hoga ki jo value ham access kar rahe hai wo, array ke ander rahe. so i-1>=0 &&& i-1 <r