### Binary Search in 2d Array :- 
So agar hamara data sorted form mai hoga toh ham waha Binary Search laga sakte hai. So hamko NXM size ka 2d array diya hoga jisme n = rowSize, M = colsize and X = target. So hamko rowwise sorted form mai data diya hua hai means har ek row sorted form mai hoga. Row i last elemet wo chhota hoga row i+1 ke first element se. If a X present then return 1 else return 0. 

Brute Force Approch :- Linear Search 
Sare element par jao, aur check karo ki wo element, x ke barabar hai ki nahi.
- if(matrix[i][j]==X)
   return 1;
- return 0;

Time Complexity :- O(NXM)

Another Approch :- 
So is approch mai ham, har ek row ki first aur last element search ki help se uski range bankar ye puchh rahe hai ki kya hamara X isme lie kar sakta hai. So if is row mai present hua toh thik hai 1 return kar denge, if not present than hamko, next row mai check  karne ki zarurat nahi hai as jo last element of that row is smaller than the every element of the next row. 
- So simply if we find out that particular row jaha x present ho skata hai waha hamko, Simply Binary Search he laganna hai. 

Code Part :- 
- given n=4, m=5, x=52
- ek for loop chalayenge i=0 zero se laker, i lessthan n tak
  - Agar matrix of [i][0] is lessthan x and x is greaterthan equal to[i][m-1] then
    - Binary Search.
```cpp
       int start = 0, end=m-1;
       while(start<=end)
       {
        mid = (start+end)/2;
        if(matrix[i][mid]==x)
        return;
        else if(matrix[i][mid]<x)
         start = mid+1;
        else
        end = mid-1;
       }
 ```

Time Complexity :- 
O(N+logn)

3rd Approch :- 
Si if converting the the 2d array into the 1d array then Us array par Binary search lagdo and we find the array. So ha yaha pahle 2d array ko copy kar rahe hai and then binary serach laga rahe hai then again change it to the 2d array, So is process mai Timicomplexity pichhle wale se jayda aa jayegi O(nxm).

So we have studied the row measure order and col measure order, So ham start ki index ko end ki index ko store kar lenge, start and end variable mai. then uska mid nikal lenge, so mid par jaane ke liye we need the i and j, so How can we find i and j :- So ham nikal sakte hai , as jo bhi mid ki paricular index aa raha hai
   - row_Index = Index/col
   - col_Index = Index%col
   So ye mid ka row(i) aur col(j), hai jisse ham mid exact postion ko x se compair kar paayenge.

Code Implementation :- 
```cpp
bool serachMatrix(vector<vector<int>> &matrix , int target)
{
    int N = matrix.size(), M= matrix[0].size();
    int row_Index, col_Index, start=0, end= N*M-1, mid;
    while(start<=end)
    {
        mid = start+(end-start)/2;
        row_Index = mid/M;
        col_Index = mid%M;

        if(matrix[row_Index][col_Index]==target)
        return 1;

        else if(matrix[row_Index][col_Index]<target)
        start=mid+1;

        else
        mid -1;

    }
    return 0; 
}
``` 
Time Complexity :- O(log(nxm))

### Search in sorted row col wise Matrix :- 
So given matrix row and col wise, dono taraf se sorted hai. So ye matrix , relateable row wise sorted nahi hai means ki kisi ek row ka last element bada bhi ho sakta hai uske next row ke first element se. So we have given N, M and X. 

Brute Force Approch :- Linear Search 
Ek ek karke search kar liya, if found then return 1 if not then return 0. 

2nd Approch :-
So isme direct bianary search par nahi ja sakte as ki we don't know ki next row ki elemet bada he hoga present row se. 
- So ek approch ki saare row mai jaye, aur check karle kya isme present hai, kya isme present hai, if found then return 1 if not then 0. So har row mai Binary Search laga do. 
- So at strating index(first element), we have the two possibility
  - ki ans row ki direction mil jaye
  - ki ans col ki direction  mil jaaye.
 So hamko yaha decision lena hai, so ham decision kisi factor par karte hai jaise, ek side incresing and ek side decresing ho. So we need find this type of factor. Kyuki binary serach bhi aese he kaam karta hai, wo decision leta left side ki right side kidhar anse milega. 

- So ab ham 1st row ke last element , par same sawal karenge , isdhar ham ye notice kar pa rahe honge ki col side incresing order and row side decrese. If present bada hai target se, then left side (row ke taraf) if chhota hai target se then col side par jao(down).

Code Implementation :- 
```cpp
bool search(vector <vector<int>> matrix,int n, int m, int x)
{
    int i =0, j = m-1;  // i = row and j=col

    while(i<n&&j>=0)
    {
        if(matrix[i][j]==x)
        return 1;
        else if(matrix[i][j]<x)
        i++; // Nich aane ke liye row ++ karna hoga
        else
        j--;  
    }
    return 0;
}
```
Time Complexity : O(n+m) 