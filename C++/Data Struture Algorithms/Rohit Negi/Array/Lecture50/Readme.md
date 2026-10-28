### Dynamic Memory Allocation in the 2d and 3D array :- 
So we are creating the the 2d array in heap having 5 rows and 4 column, so how can we create it?
In general, koi bhi 2d array kaise banta hai, bahut saare 1D array ko jodkar. So if we created a 5 1D array , jinka size 4 ho then hamari problem solve jo sakti hai. 
```cpp
int *ptr1 = new int[4];
int *ptr2 = new int[4];
int *ptr3 = new int[4];
int *ptr4 = new int[4];
int *ptr5 = new int[4];
```
-> Visualize it, by creating the pointer and its 1D array. 
So istarah ham 2d array create kar sakte hai but this is not the best approch to defind the 2d array because if user asked for 100 rows and 4 col then we 100 bar 1d array ko nahi defined kar sakte hai. So code bahut bada aur complex ho jayega. And accessing value is not easy task. 

So ham pahle pade the ki jab 100 variable ko define karna tha toh 100 baar toh variable nahi defined kar sakte so we made the array, similarly we will not created that much ond D array then we created the array which store the address of these 1D array. 
-> So if asked to create an array of 5 size(rows), then 5 size ka ek array banayenge , jiske ander address ko store karwa rahe honge. means ki har ek value of this array will be pointing to another array. 
-> So now we need just a pointer which point's this array which store the addresses.

How to access value in 2d array, when we created it dynamically.
ptr: ptr ek pointer jo  ek array ko point kar raha  hai jo address ko store kiya hua hai
(ptr+2) : us array ke 2 index par chale jao
*(ptr+2) : us index ki value ko read karo -> means ki waha chale jao agar address hai
*(ptr+2)+1 : us address par jao usme , index 1 ki value par jao
*( *(ptr+2)+1) : us index par jo hai usko read ya access karo. 
or directlly is tarah likhenge :-  ptr[2] [1];

Note :- 
*( *(ptr+2)+1) = ptr[2] [1] -> true hota hai
*(ptr+2) =  ptr[2]  -> true hota hai

-> 2D array mai double pointer use hota hai(the pointer which points the array which stores the address)
  Double pointer kyuki ham do * ka use kar rahe hai value ko read karne jo int type ki hai. 

Defining the 2d array Dynamically :- 
[] - a array which we want to create
[n] : array of size n 
*[n] : array which store the address ( *= address)
int *[n] : and the address is pointing to the int type value
new int *[n] : new keyword so that we can have the memory in the heap
= new int *[n] : it return the address
**ptr = new int *[n] : jo address hoga wo store hoga double pointer mai
int **ptr = new int *[int] : double pointer point kar raha hai, ek int type ki value ko. 

Creating 2D array :- 
```cpp
int **ptr = new int*[n];
for(int i=0;i<n;i++)
ptr[i] = new int[m];
```
ptr[i] = *(ptr+i)

Accessing the value :- 
```cpp
for(int i=0;i<k;i++)
for(int j=0;j<m;j++)
cin>>ptr[i][j];
```

-> Releaing 2D array, we allocated in the heap memory :-
So isme ham diectly delete []ptr; nahi kar sakte as ye us array ko release karega jo address store karke rakha hai, aur 1d array jo hamne isme store kiya tha, wo toh waisa ka waisa he pada hua hoga. So pahle inko delete karenge then array ko jo address store karke rakhi thi. 

```cpp
for(int i=0;i<n;i++)
{
  delete [] ptr[i];
}
delete [] ptr[];  // us array ko release kardo jo address store kiya tha or double pointer jisko point kar raha hai usko relase kardo. 
```
delete [] ptr[0]; : ptr 0 par jo address hai waha jao aur usko release kar do and so on. 

Code Implementation :- 
```cpp
#include <iostream>
using namespace std;

int main()
{
    // Array create karna hai, jo store karega ek address ko
    int n, m; // n=rows and m=col
    cin >> n >> m;

    int **ptr = new int *[n];
    // creating 1d array and unki address ko is array mai store karna hai
    for (int i = 0; i < n; i++)
    {
        ptr[i] = new int[m];
    }

    // Inserting value in the 2d array we created
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> ptr[i][j];

    //  Print the inserted value
    for (int i=0; i<n; i++)
    {
        for (int j= 0; j < m; j++)
            cout << ptr[i][j] << " ";
            cout << endl;
    }

    // Release the memory , heap main
    for(int i=0;i<n;i++)
    {
        delete []ptr[i];
    }
    delete [] ptr;
}
```

### 3d array
-> So bahut saare 2d array ko aapas mai connect karenge toh 3d array create ho jayenga, juts like we created the 2D array. Similar way mai, yaha bhi ham ek array banayenge jo address store karega un array ka jo store kiya hua hai ek 1d array ka address. 

=> ptr[2] [1] [2] = *( * ( * (ptr+2)+1)+2) 

Creating the 3d array :- 
int arr[3] [2] [4]; l=3, B= 2 and H=4

[]: create an array
[l] : create an array of size l 
*[l] :  this array store the address
**[l] : and the address is pointing the another address
int **[l] : and that address is point the int type ka value
new int **[l] : Writing new so ki hamko heap mai memory mil jaaye (of the structure we are demanding)
= new int **[l] : ye address return karega array ka jo store karega 2d array ke address ko
*** ptr = new int **[l] : we need triple pointer to store these addresses
int ***ptr = new int **[l] : triple pointer are pointing to the int type ki value

```cpp
int ***ptr = new int **[l];
for(int i=l;i<l;i++)
{
  int **ptr[i] = new int*[B];
  for(int j=0;j<B;j++)
  {
    ptr[i][j] = new int[H];
  }
}
```
Releaing memory Of 3d array ka code -> Homework 
Example :
```cpp
int arr[4][5];
cout<<arr;
cout<<arr[0];
cout<<arr[0][0];
```
Without pointer isko implment karenge toh pahle do ka answ same aayega 3rd ka different but agar pointer ke help se karenge toh tino ka alag answer aayega? aisa kyu? find out reason?