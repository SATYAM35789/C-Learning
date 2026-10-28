### Recursion in array :- 
So we have seen the basic of the recursion, So today we are going to see that how we can use the concept of the recursion with the array. 

### Print array :- 
So we have given a array and we have to print their value with the help of recursion. 
- print() : iska kaam hai ke ye current index par jo bhi value usko print kar dega hamari array ka. So we need to pass the array and index we want to print. 
  - ek instruction jo hmare current value ko print karega i.e cout<< arr[ index]; 
  - ek instruction jo next value ki print karne ke liye -> so we need to call fun jo nex index aur array dene par hamari array ka value print karde i.e :- print(arr, index+1);
  - for the base we need the n , so er have to include n as parameter.

Code part :- 
```cpp
void print(int arr, int index , int n)
{
    if(index== n)
    return;

    cout<<arr[index];
    print(arr,index-1,n);
}
```

=> Create the recursion tree, taking array of size 5. 

=> Is we can able to print the value in the reverse order, with doing some modification in the code. 
```cpp
void print(int arr, int index , int n)
{
    if(index== n)
    return;

    
    print(arr,index-1,n);
    cout<<arr[index];
}
```
- example  3,7,6,2,8  => 8,2,6,7,3

Recursion function working :- 
So pahle mujko print mat karo, jo mujse pahle aaye hai, pahle unko print kardo. 

- Iska bhi recursive tree bana kar ham dekh sakte aur samjh sakte hai ki ye recursion function kaise kaam kar raha hai. Bas dhyaan ye rakhna hai ki jab last time visot kar rahe hai node ko tabhi uski value ko print karenge. 

Variation of the question 
Dekho abhi bhi hame array ko print karwana hai like 3,7,6,2,8  => 8,2,6,7,3 lakin ab last index ko bhej rahe hai apne function mai
recursive function working print():  so ye function jo current value hai usko print kar raha hoga and we need to pass the arr and the index, we want to print.
-cout<< arr[ index ]; 
- print(arr, index-1): iske pahle wale index ko print karne ke liye call kar raha hai. 
- Base case : agar index barabar ho jata hai -1 ke tab return ho jao.

Code part :- 
```cpp
void print(int arr, int index)
{
    if(index==-1)
    return;

    cout<<arr[index];
    print(arr,index-1);
}
```
So If we see the both two code of above they are doing same work but there is a difference no of parameter we pass in the function. Because in first we donot know the ending condtion in second we know ki n kuvhh bhu end fixed hai -1 par function ko next call karne ki zarurat nahi hai. 

Another variation :- 
Array given 3,7,6,2,8  => output 3,7,6,2,8  and we sending the last index of the array then ab ham kaise print karenge. Easy same jaise hamne 2 nd variation mai kiya tha, ab function ko bolenge pahle mere pahle wale ko print karo phir mujko print karna. 
```cpp
void print(int arr, int index)
{
    if(index==-1)
    return;

    print(arr,index-1);
    cout<<arr[index];
}
```

Code Implementation:- 
```cpp
// Pichhe wali index pahle pass kar rahe hai. 
#include <iostream>
using namespace std;

void print(int arr[], int index)
{
    // Base Case
    if (index == -1)
    return;
    print(arr, index + 1);  // 3,4,1,2,8
    cout << arr[index] << " ";
    // print(arr, index + 1);  // 8,2,1,4,3
}

int main()
{
    int arr[] = {3, 4, 1, 2, 8};
    print(arr, 0);
}
```

### Sum of all element
So isme pahle ham ye try karenge ki agar hamko sirf ek element ka sum nikalna hota toh kya karna hota. 
We need a function jiske ander ham apna array pass karte aur index jiske help se particular element ki value pata kar paate so : 
```cpp
int sum(int arr[], int index)
{
    return arr[index]; 
}

int main()
{
    int arr[] = {3,1,4,2,8};
    int total=0;
    for(int i=0;i<5;i++)
    {
        total+=sum(arr,i);
    }
    cout<<total;
}
```
return arr[index]; :Kisi ek element ka sum aise he nikal rahe hote, jo bhi element mai present hai wahi hamara sum hota. We need  to return as jaha se call hua usko index ka sum bhi toh batana hoga. 

- so hamko for loop ka use nahi kar sakte, and we need to calculate sum of all element of a array, So agar first element ki starting mai pass kar rahe , then need to call for the next index to have the sum of that elemet. 

```cpp
int sum(int arr[], int index)
{
    return arr[index] + sum(arr, index+1); 
}
```

-> So kab tak ye function aise he return karta hoga, we need to stop this when the element of an array is completed. So when index is equal to the n it means ki wo saare element par ja chuka hai and we need to stop. So we need n in our function, so we have to pass the n in the function as an parameter. 
```cpp
int sum(int arr[], int index, int n)
{
    if(index==n)
    return 0; 
    return arr[index] + sum(arr, index+1, n); 
}
```
- Recusrion tree
- Mathematical Representation : 
if arr = 3,4,5,8,2

sum(5) = 0
sum(4) = 2+ sum(5) //  2 : value at index 4
sum(3) = 8+ sum(4)
sum(2) = 5+ sum(3)
sum(1) = 4+ sum(2)
sum(0) = 3+ sum(1)

sum(index) = arr[index] + sum(index + 1)

Code Implementation: 
```cpp
#include <iostream>
using namespace std; 

int sum(int arr[], int index, int n)
{
    if(index==n)
    return ;
    return arr[index] + sum(arr, index+1,n);
}

int main()
{
    int arr[] = {3,4,1,2,8};
    cout<<sum(arr,0,5);
}
```

Note : Agar hamko 2 he parameter pass karna hamare fun mai tab hamko, apna pichhla concept use karenge jab apne array ko print kar rahe the 2 parameter ke help se. 

### Find minimum in the array
So we try to find the minimum in the single element, so ki if ham ek liye find kar lenge then sabke liye kar lenge. 
Code part 
```cpp
int minElement(int arr, int index)
{
    return arr[index];
}

int main()
{
    int arr[]= {3,4,1,2,8};
    int num = arr[0];
    for(int i=1;i<5;i++)
    {
        num = min(num,minElement(arr,i));
    }
}
```
- Iske baad hamko next element ke liye call karenge
- Aur in dono element mai se jo sabse chhota hoga wo ans ho jayega usko return kar denge. 

Code part 
```cpp
int minElement(int arr, int index)
{
    //  Base Case 
    if(index==n-1)
    return arr[index];
    return min(arr[index], minElement(arr, index+1))
}
```



