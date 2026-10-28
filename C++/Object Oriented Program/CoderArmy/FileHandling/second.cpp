#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
   vector<int>arr(5);
   cout<<"Enter the input\n";
   for(int i=0;i<5;i++)
   
   cin>>arr[i];
     // File ko open karo
    ofstream fout;
    fout.open("zero.txt");
    fout<<"Original data \n";
    for(int i =0; i<5;i++)
    {
        fout<<arr[i]<<" ";
    };
    fout<<"\nSorted data \n";
    
    sort(arr.begin(),arr.end());
    for(int i =0; i<5;i++)
    {
        fout<<arr[i]<<" ";
    };

   
}