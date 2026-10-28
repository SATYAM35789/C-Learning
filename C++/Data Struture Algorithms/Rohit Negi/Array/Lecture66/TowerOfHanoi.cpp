#include <iostream>
#include <cmath>
using namespace std;

void tohCal(int n, int source, int helper, int dest)
{
    if(n==1)
    {
        cout<<"Move disk"<<n<<"from rod"<<source<<"to rod "<<dest;
        return ;
    }
    tohCal(n-1,source,dest,helper); // source se helper wale par n-1 disk lakar jao
    cout<<"Move disk"<<n<<"from rod"<<source<<"to rod "<<dest;
    tohCal(n-1,helper,source,dest); // ab disk helper ke uppar aa gaye hai ab helper se dest ke upper bhej do disk ko

}

long long toh(int n, int from, int to, int aux)
{
    tohCal(n,from,aux,to);
    return pow(2,n)-1;
}