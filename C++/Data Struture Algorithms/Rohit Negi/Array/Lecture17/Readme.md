## Master Arrays By Solving Problems :- 
### Search Element in the array :- 
  So is question mai agar rlrmrnt presemt hai then uska index wapas karna hai nahi present hua toh -1 dena hai. 
Approch :- 
- hamare pass ek array hoga, jisme kuchh values hogi , ham ek key varaible banayenge aur usme us varaible ko rakhenge jo value hamko apne array mai find karna hai. If present then return index value if not then then -1. 

Code Implementation :- 
given hai int type ka ek array, ek size of an array and the value we need to find in the array.
- ek int type ka fun(), parameter: int type ka array, size of array and value need to find. 
  - ek for loop jo i=0 se i=n tak chalega. 
    - Agar arrofi barabar hai value need to find ke tab 
      return index kardo
    - if barabar nahi hai then for loop ke bahar jao aur return -1 kardo

Code Part :- 
``` cpp
int search(int arr[], int N, int key)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}
```

### Reverse Array :- 
So is problem mai hamko ek array diya hoga, jisme kuchh value present hogi so yaha hamko arrar ke sare element ko reverse karna , print  nahi reverse karna hai, reverse means ki last element starting, last secend element- starting second mai and so on. 

Approch :- Brute Force Approch
1st part : Array ke element ko pichh se for loop ke help se, ek  array mai store karnge.
2nd part : Ab naye element ke array ko as it is copy karnege purani wali array mai. 

Code Implementation :- 
Part 1 :
- ek apne gievn array size ka, ek temp array banayenge
- i  ko given array ke pichhe se start karnege aur j ko temp ke starting se 
- while ko jab tak chalayenge tabtak i, 0 ke barabar nahi ho jata 
  - temp of j mai arr of i daal denge
  - j++ kardo
  - i-- kardo 

Part 2 : Copy the array in the previious array
- so ab i=0 se start karenge aur tab tak copy hote rahega jab tak j end tak nahi pahuchta at temp

Approch 2nd :- 
Ab same array mai do varaible lenge i jo starting of array ko point  karega and j jo end of an array ko point karega initially. i ko badao and j ko gatao ek se and swap procedure lagao. 
So jab tak i aur j mil nahi jate tab ham ye kaam karte rahenge.

Code Implementation :- 
- Intially i =0 (starting) and j= n-1(ending).
- Ek while loop lenge, jo tab tak chalega tab i chhota hai j se. 
  - swap(arr[i], arr[j])
  - i++, i ko ek se bada do
  - j--. j ko ek se ghata do

Break condition is important to identify, so ki kab tak hamko apna kaam karna hai taaki jaldi se output mil jaye. 

Code part
``` cpp
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int start = 0, end = 5;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    // Printing the value :-
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
}  
```

### Second Max :- 
EK array given hoga, jsme se hamko second maximum element ko wapas karna hai. 

Approch :-  So sabse pahle sabse bada no. ko find kar lenge, phir us no. ko chodkar jo sabse bada hoga usko choose karlenge wo hmara ans hoga. 

Code part :- 
- ans aur secondMix variable lenge jisme Intmin se initialize kar denge, 
- ek for loop lenge jo i=0 se chalega aur i=n-1(end) chalega.
  - Agar arr of i bada hai ans se then ans mai arr of i ko daal do. 
- ek aur for loop chalayenge from startin to end
  - Agar ans barabar nahi hai arr of i ke tab 
    - ans mai daal do wo value jo ans, aur arr of i mai se maximum ho. 

Code Implementation :- 
```cpp
int print2Largest(int arr[], int n)
{
    int ans = INT_MIN;
    //  largest element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > ans)
            ans = arr[i];
    }

    // Second Largest element
    int secondMax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != ans)
        {
            secondMax = max(ans, arr[i]);
        }
    }

    return secondMax;
}
```

### Missing Number :- 
So is problem mai N diya hoga , aur ek array kiska size N-1 hoga aur us array mai 1 to N no honge, so hamko batana hai ki konsa no, present nahi hai as array ka size ek kam toh purra 1 to N no array mai nahi jayega. Aur har ek element ek he baar aayega.

Approch :- Brute Force
Starting se ek ek element ko uthao aur check karte jao ki present hai ki nahi like 1 ki uatho check karo, then 2 ko uthao check karo and so on karte jao. Ye tab tak karenge tab missing element n mil jaye. 

Approch 2nd :- 
step1 : 1 to N element ka sum nikal lo
step2 : array mai jitne element present hai, unka sum nikal lo
step3 =  step1 - step 2 (we found the answer)

Code implementation :- 
``` cpp
int missingNumber(vector <int> &array, int n)
{
    // Sum of all element in a array
    int sum =0;
    for(int i=0; i<n-1;i++)
    sum+=array[i];
    //  Sum of n element
    int sum1 =0; 
    sum1 = n*(n-1)/2 ;

    int missingTerm = sum1 - sum ;

    return missingTerm;
    
}
```

### Fibonacci series :-  (Fibonacci ka konsa term tujko chahiye)
In a fibinacci series, 1st two element are 0 and 1 repectively, and the next element is summation of previous two element and so on til the n number. 
So problem ye hai ki hamko bol raha hai ki ek specific position ka fibonacci kya return karo or like 7th fibonacci batao? 

Logic :-  arr[i] = arr[i-1] + arr[i-2]

Code Implementation :- 
```cpp 
int main()
{
    int n; 
    cout<<"Enter the number: ";
    cin>>n;

    int arr[1000]; 

    arr[0] =0; 
    arr[1]= 1;

    for(int i=2;i<=n-1;i++)
    arr[i]= arr[i-1] + arr[i-2];

    cout<<arr[n-1];
}
```

### Rotate array by 1 :- 
Rotate by one se matlab hai ki array sare element ko ek se shift kardo right side end wale ko aage la do. 

Approch :- Brute Force 
1st part :- 
ek new array banao, aur i and j varaible lo jaha i given array ke 1st index ko point karega aur j new array ke i+1 index par hoga.
Iske baad i and j ke help se given array ko new array mai copy karo tab tak j exist kar raha hai.
Phir manually last element of given array ko new array ke starting mai copy kardo 
2nd part
new array ko copy kardo purane array mai. Phir hamko result mil jayega. 

Approch 2nd :-
1. Array ke last element ko store karlo kisi variable mai like temp. 
2. Phir array last -1 se start karo  starting tak aao, current element ko uske postion ke next mai daal do
3. Last mai jab loop khatam ho jayega tab temp wale ko update kardo o index par. 

Code Implementation :- 
```cpp
void rotate(int arr[], int n)
{
    int last = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    arr[i+1] = arr[i]; 

    arr[0] = last; 
}
```

### Passing array in the function  :- 
Code part :- 
```cpp
#include <iostream> 
using namespace std; 

void fun(int a[], int n)
{
    cout<<sizeof(a)<<endl;
    for(int i=0;i<=n;i++)
    cout<<a[i]<<" ";
}

int main()
{
    int arr[] = {22,223,4,33,444,};
    fun(arr,5);
    cout<<sizeof(arr)<<endl;
}
```

To verify that a[] jo ham array mai pass kar rahe hai ye ek pointer hota hai ham sizeof() ka use kar sakte hai above code show that a[] is the address which is where the arr[] is stored in the ram. 

