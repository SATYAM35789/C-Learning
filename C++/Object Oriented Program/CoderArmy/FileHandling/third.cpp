#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
   ofstream fout;
   fout.open("z1.txt");
   fout<<" Hello India \n";
   fout<<" Hello Satyam \n";
   fout<<" Hello brother \n";
   fout.close();
   ifstream fin;
   fin.open("z1.txt");
   string line;
   while(getline(fin,line)) // work of getline fun, read the line , and line ke ander dal do
   {
      cout<<line<<endl;
   }
   fin.close();
}