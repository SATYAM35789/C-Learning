#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin; // To read the file
    // Open the file
    fin.open("Zoom.txt");
    // Read the file
    char C ;
    C = fin.get() ; // Catching each element one after one
    while(!fin.eof())   // end of file
    {
        cout<<C;
        //fin>>C; // Moving to the next character but treating space not include
        C = fin.get() ;
    };
    fin.close();

}