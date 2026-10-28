### Double Pointer :- 
So abhi tak ham ye kar rahe hai ki, hamare pass ek normal variable tha aur usme kuchh value hoti thi, so hamne sochh ki agar is variable ka address tore karwana hai tab ham kaise karwa sakte hai, so we made the pointer : a variable capable to store the address of variable, So ab hamko is poinet ka bhi address store karwana hai then we need the double pointer. 
```cpp
int n=10;
int *p = &n;  // So hamne ek pointer banaya hai ho point kar raha hai int type ke value ko
int **ptr = &p; // ptr ek pointer hai jo point kar raha hai, ek pointer ko jo store kiya hai int type ke value ko
```

Example :-
*p = *p+4   -> 10 + 4= 14 (ab n ke ander 14 hoga )
 
*p : p ke ander ek address hai waha jao, aur uske ander value ko read or access karlo
*p = : p ke ander ek address hai waha jao, aur uske ander iske right side wali value store kardo

Example 2: **ptr = **ptr +10   -> 14 + 10 = 24  (ab n ke ander 24 hai)
* : jo bhi address stored hai waha jao, aur value ko read karlo 
Note : agar kisi ke address ke help se kuchh changes kar raha hu toh changes sabko dikhta hai. 

<!--Homework : Reference variable and reference pointer : hamko ek pointer ki address ko update karna hai aur usko print karwana hai (using funcyion calling )  -->

### Triple pointer :- 
Ek aisa pointer jo store kar raha hai, double pointer ki address ko. 
Note : n pointer store's the (n-1)pointer address. 

Code Implementation :- 
```cpp
// Fundamentals : Double pointer
int main()
{
    int n=10;
    int *p = &n; // Single Pointer
    cout<<p<<endl;
    int **p2 = &p; // Double Pointer
    cout<<p2<<endl;
    int ***p3 = &p2; // Triplet pointer
    cout<<p3<<endl;

    // Modifying the value jo n mai rakhi hai
    *p = *p+5;  // 15 using single pointer
    cout<<n<<endl;

    **p2 = **p2 + 5;  // 20 using double pointer
    cout<<n<<endl;

    **p3 = **p3 + 5; // 25 using triple pointer
    cout<<p3<<endl;

    // So ham kisi bhi pointer ke help se apne value ko modify kar sakte hai
}
```
Example 
```cpp
void fun(int *p)
{
    *p = *p + 10;
}

int main()
{
    int n=10;
    int *p = &n; // Single Pointer
    int **p2 = &p; // Double Pointer

    fun(p);
    cout<<n<<" "; // 20

}
```

Example : Change the address
```cpp
void fun(int *p1)
{
    p1++; // p1 point kiha hai ek address ko jiske ander ek value, address nahi so ye same address dega
}

int main()
{
    int n = 10;
    int *p = &n;   // Single Pointer
    int **p2 = &p; // Double Pointer

    cout<<p<<"Old Address"<<endl;
    fun(p);
    cout << p <<"New Address"<< " ";
}

// So is se address ko change nahi kar pa rahe as we donot have the p1 address , to modify it we must have p1 address

void fun(int **p1)
{
    *p1 = *p1+1; 
}

int main()
{
    int n = 10;
    int *p = &n;   // Single Pointer
    int **p2 = &p; // Double Pointer

    cout<<p<<"Old Address"<<endl;
    fun(p2);
    cout << p <<"New Address"<< " ";
}

//  So ham kisi bhi pointer ka data change kar sakte for that we must have the address of the that. 
```

Another Example :- 
```cpp
int main()
{
    char c[] = "GATE2024";
    char *p = c;
    cout<<p+p[3]-p[1];
}
```
char c[] : Showing the array and having some address
char *p = c :  array ke address ko hold kiya hai
p : ek pointer jo c jo ek array usko point kiye hue hai, So p=100;
p[3] : E
P[0] : A
Difference b/w character is substracted on the basis of ascii value so E-A => 69 - 65 = 4
Hence p+p[3]-p[1] : 100 +69 -65 = 104 , ab ye 104 ko poinnt karega. 

Note: Jab bhi address mai koi integer add hota hai then wo calculation ke liye datatype dekhta hai, so 4 * 1(char: datatype) = 4

output : 104 ke baad sab print jo jayega : 2024 answer hoga. 
If we do the cout<< c;  then it will print all the value in c like GATE2024.

Another Example :-
```cpp
void second(int *p1, int *p2)
{
    p1=p2; 
    *p1=2;  // p1 jisko point kar raha hai, waha jao aur uske ander ki value ko 2 kar do.
}

int main()
{
    int i=0,j=1;
    second(&i,&j);
    cout<<i<<j; // output : 0 2
}
```

Another Example :
```cpp
int *ptr;
int x=0;
ptr = &x;
int y = *ptr;
*ptr = 1;
cout<<x<<y; // x =1 and y = 0
```

Another Example :- 
```cpp
int a=5, b=10;
int &name =a;  // name aur a dono ek he address ke do naam hai
int *ptr = &a;
(*ptr)++
ptr = &b;
*ptr = *ptr + 5;
name+=5;
cout<<a<<b<<endl; // a =11 , b=10
```
 
Another Example :-
```cpp
int four(int x, int *py, int ***ppz)
{
    int y,z;
    **ppz +=1, z = **ppz;
    *py +=2 , y=*py;
    x+= 3;
    return x+y+z;
}
int main() {
int c, *b, **a;
c=4, b=&c, a=&b;
cout<<four(c,b,a); // 19
} 
```

Another problem :- string copy code
```cpp
void five(char *str1, char *str2)
{
    while(str1=*str2)
    {
        str1++, str2++;
    }
}
int main()
{
    char first[] = "mohit";
    char second[] = "Rohan";
    five(first, second)
    cout<<first;  // Rohan
}
// isme jab string ke last mai pahuch jayenge tab while loop nahi chalega as jab while mai condion x=1 daalte hai then iska matlab hota hai ki jab tak while true hai tab tak chale and if x=0 ho toh means while false aur loop nahi chalega ek bhi kadam same wise null charater ko as 0 treat karta hai means ki loop nahi chalega jab string null ho jayega. 
```