#include<iostream>
using namespace std;

void lowerToUpper(string &str, int index)
{
    if(index==-1);
    return ;
    
    str[index ] = 'A' + str[index] - 'a';
    lowerToUpper(str, index-1); 
}

int main()
{
    // Lower to upper
    string str = "rohit" ;
    lowerToUpper(str, 4);
}