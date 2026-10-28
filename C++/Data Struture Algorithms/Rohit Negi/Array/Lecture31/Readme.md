### Introduction to 2D Arrays :- 
So hamne excel shhet dekhi hai, usme data hai, so we have been asked to store this data in the RAM for the processing so ham kaise data ko store karenge, because jo excel sheet hai bahut badi hai aur usme bahut saari rows hai. Toh ham kaise store kar sakte hai. 
-> So har row ke liye array banate jate hai 
   - so jo ye tarika hai isme, kitni 1 array banate jayenge store karne ke liye, so jitni banayenge utni baar array ka naam dena hoga, hamko array ka naam yaad karna usko access karne ke liye, kaafu complicated ho jayega. 
   -> baar baar arrau ko create karna hoga, so usme bhi bahut jayda time waste hoga. 

   Syntex of 2d Array :- 
    DataType arrayName[rowNumber][colNumber];
    ex 1. int arr[4][3];

    Real WorldExample :- 
    1. ChessBoard    2. Tic-Tac-Toe 

    Memory Allocation of the 2D array :- 
    - jis tarah ham visualy represent karte hai 2D array ko memory mai store nahi karte hai, as hamko pata hai ki array store the value in the contigous memory. 
    So store karnw ke do tarike hai :- 
    1. Row Major
    2. Col Major 

    Row Major :- 
    So ye bolte hai ki row wise memory mai store honge, so pahle 1st row then next row and so on. 
    example: int arr[4][3] :00,01,02,10,11,12,20,21,22,30,31,32
    - so internally ye single array ke tarah he store ho rahe hote hai. 

    So ab maan lo hamko row index aur col index pata hai kisi 2d array ke kisi element ka aur hamko ye bhi pata hai ki 2d array ka rowsize = 4 and colsize= 3 hai. 
    
    Element[10] : 1 ko kaise read kar sakte or ye ke show kar raha hai
    - ki ye second row hai or
    - ki iske pahle ek row khatam ho chuki hai. 

    21 ka current location janne ke liye?
    - sirf 2 ko dekh kar ye bol sakte hai ki iske pahle 2 row khatam ho chki hai. 
    - so pata karne ke liye uske pahle kitni row fill ho chuki hai , rowindex* colSize of the array .
    - 1 ka matlab hai ki utani no of element store karwa chuke ab present row mai uski position kaha hogi and 1 means ki present row mai utani value aa chki hai. 

    Conclusion formul : Index = row_Index * ColSize + col_Index
    ex 21 : 2 * 3 + 1 = 7 
    - so ye show kar raha hai ki uske pahle 7 element aa chuke hai , lakin we use 0 based indexing so ab ye batayega uski(21) current location.

    So ab hamko current location pata hai aur row and col bhi pata then ab kaise pata karenge ki ye kis index ki baat kar raha hai :- 
    If given index, row and col.
    row_Index : Index/col ;
    col_Index : Index%col ; 

- So hamko pata hai ki memory byte addressable hota hai, so arrka address means ki uski 1st  value ki address so if wo 500 hai toh uske baad 504, 508 .., etc honge. Agar int type ka address store kar rahe hai toh. 
- jab bhi ham computer ko arr[3] dete hai toh, computer isko kaise simplyfy karta hai, So computer isko simplyfy karta hai, ek address ka bal par karta hai. Agar kisi ko letter dena hai toh hamko uska address pata hona chahiye.  
arr[3] = base Address + index * size of datatype
       = 500 + 3*4 = 512 . 

arr[i][j] = base Adress + Index * size of element
          = bassAddress + rowIndex*col+ colIndex * size of element
arr[2][1] = 500 + (2 * 3 +1)4
          = 500 + 7*4
          = 528 

2D array ke element Ram kaise access karta hai?
arr[i][j] = baseAddress + (i * col+ j) * size of an element. 

### Creating an array :- 
int arr[4][3];

### Intializing the 2D array : 
Means ki 2d array ke ander kuchh daalna ho toh kaise daalenge. 
 1. int arr[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12} ;
    - so isme hamko pata hai ki total is array mai kitni value aane wali hai i.e 4 *3 = 12 
 2. Updating  
    ex on above array :- 
      arr[3][0] = 15 ; 
 3. taking input from the user :- 
    Ab array mai, user se directly input le lenge aur 2d array mai kisi element mai daal denge.
    cin>>arr[1][2]
    - ab user kuchh bhi input de, ab wo arr[1][2]. par store ho jayega. 

 4. Printing the all element of 2d array 
    ``` cpp
    for(int i=0;i<row;i++)
    {
        for(int j=0;i<col;j++)
        cout<<arr[i][j];
    }
    ```

### Search An Element in Array :- 
So hamko 2d array diya hai, usme hamko koi element diya hoga usko search karna hai. 
```cpp
int main()
{
    int arr[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int x =7;
    for(int i=0;i<4;i++)
    {
        for(int j=0;i<3;j++)
        if(arr[i][j]==x)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}
```
### Passing the 2d array in the function :- 
So jaise 1d array ko pass karte hai, waise he pass karenge. 
arr[][col]
- yaha ki hamko column ka size batana padega. 
- so col isiliye pass kyuki bassAddress + rowIndex*col+ colIndex * size of element ,
   -> is formula mai, jo col use kar rahe hai, iske liye pass kar rahe hai 2d array mai. 

1d mai nahi pass karte the, kyuki iske address ko directly print karwa sakta hai. Kyuki waha formula mai use nahi padta tha. 

### Summary till now :- 

```cpp
void printCol(int arr[][3], int row, int col) // arr[][4]: need to mention the col size
{
    // Column Wise 
    for(int j=0;j<col;j++)
    for(int i=0;i<row;i++)
    cout<<arr[i][j]<<" ";
}

int main()
{
    // Creating 2D array
    // int arr[4][3];

    //  Initializing the 2d array
    int arr[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    //  Printing the all value in the array(default : rowWise)
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; i < 3; j++)
            cout << arr[i][j];
    }

    // Print all the value in array colWise, function call
    printCol(arr, 4, 3);

    // Find element in the array
    int x =7;
    for(int i=0;i<4;i++)
    {
        for(int j=0;i<3;j++)
        if(arr[i][j]==x)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}

```

### Add 2 Mattrix
So hamko do matrix diya hua hai, of different size. So hamko inko add karna hai. Aur usko store karna hai new matrix mai. 
- Do array ko hamko mila haiwo hai arr1[3][4] and arr2[3][4] hai so hamko ek ans array banana hoga jisme iska addition ko store karke rakhenge. 
   ans[0][0] = arr1[0][0] + arr2[0][0];

   general Form :-  ans[i][j] = arr1[i][j] + arr2[i][j];

Time Complexity and space:- O(row*col)

Code Imlementation :-
```cpp
int main()
{
    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr2[3][4] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int ans[3][4];

    // Add 2 Matrix
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
        {
            ans[i][j] = arr1[i][j] + arr2[i][j];
        }

    //  Printing the answer array
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            cout << ans[i][j] << " ";
}
```

Note :- So Addition and substraction ke case mai no of row and col dono barabar hone chahiye. means ki arr1=arr2=ans , tino matrix ka size same hona chahiye. 

### Print Row index with Max Sum :- 
So ek 2D array diya gaya hoga, jiska hamko saare rows ka sum nikalna hai. Inme se jiska sum sabse bada hoga uske index ko print karna hai. 

Approch :- 
So sare rows ke sum ko  Store kar lenge, And jo inme se maximum hoga uske index print kar denge. So hamko pata kaise chalega. 

```cpp 
void printRowIndexMax(int arr[][4], int row, int col)
{
    int index =-1, sum = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        int total =0; 
        for (int j = 0; j < 4; j++)
        total+=arr[i][j];

        if(total>sum)
        {
            sum = total;
            index = i ; //  store the row
        }
    }
    cout<<index;
}
```

### Print the Sum of Diagonal Element :- 
So ab ek matrix diya hoga aur hamko iska diagonal element ka sum print karna hai. 
To matrix which have the same no of rows and column then us matrix ke diagonal uske case mai he diagonal exist karta hai. 

Approch :- 
-> Apne matrics mai diagonal ko mark karlo, ab ham try karenge logic or generalized formula nikalna for the diagonal taaki ham apne matrics Sum ko nikal paaye. 
-> Pahla diagonal mai four four ki matrics hai then hamko three three tak jana hai. So iske liye  loop chalayenge o se n tak jisme firstDia = arr[i][j] kar denge. 
-> Second diagonal ke analysis karenge toh hamko pata chalega ki, diagonal ki jo elements hai usme row increse ho raha hai and col decrese ho raha hai ye pattern milega.
  - so i=row and j=col then int i =0, j = col-1;
  - so is case mai, jab tak j bada hai aur barabar hai 0 ke tabtak secondDia += arr[i][j] karte jayenge. 

Code Implementation :- 
```cpp
void printSumDiagonal(int arr[][3], int row, int col)
{
    int firstDia = 0;
    int secondDia = 0;

    // First diagonal sum :-
    int i = 0;
    while (i < row)
    {
        firstDia += arr[i][i];
        i++;
    }
    // Second diagonal Sum
    int j=col-1;
    i=0;
    while(j>=0)
    {
        secondDia+=arr[i][j];
        i++;
        j--;
    }
    cout<<firstDia<<" "<<secondDia<<" ";
}
```

### Reverse each row of a Matrics : 
So hamko ek  matric diya gaya hoga uske saare rows ki element reverse karke likhna hai, as if 1,2,3,4 then 4,3,2,1 (single row). 

Normal array mai reverse karne ke liye ham do pointer lete hai hai ek start mai, aur ek end mai. Similar approch use karenge row wise. 
-> so col change ho raha hai, if you analize the array, so we need to take pointer and change according the col. 

code part:
```cpp
for(int i=0;i<row;i++)
{
    int start=0, end=col-1;
    while(start<end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
```