/* 
Generic programming :- Coding aproach in which we can use that code in various condition mai use kar sake. we 
donot need to write more coding. 
Reduce the time. We are generalizing the code. 

Passing the datatype as a parameter in fun. With this concept  can able implement the generic programming. 
The genic programming concept is 1stly used by the meta language in 1973. Influenced by this concept, in other 
language it may have different name. 

*/
#include<iostream>
using namespace std;
int big( int a, int b)
{
    if(a>b)
       return a;

    else
       return b;
}

float big( float a, float b)
{
    if(a>b)
       return a;

    else
       return b;
}