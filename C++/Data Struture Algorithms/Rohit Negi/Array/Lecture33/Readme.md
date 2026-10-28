### Rotate Matrix by 90 Clockwise or Rotate Image
So hamko ek squre matrix diya hoga, so agar usko 90 degree bada de toh, jaisa structure form hoga waisa structure hamara output hoga. Means ki square mai har ek matrix 90 degree ka hota hai so agar usko(side) ek baar clock direction mai ghuma de then it would be the resultant. 

Approch :- 
Analysis :- For the analysis, hamko jo bhi matrix diya hoga uska reslutant or jo bhi output ham expect kar rahe hai usko bhi draw karna hoga, 
- hamari row, col mai change ho gai hai, 1st wali row last col mai, and 2nd wali row last col mai and so on. 
- So agar given and output matrix ke index ko analysis kare tab, hamko pata chalega ki j of of given matrix is equal to the i of resultant matrix and they are changing. and other given matrix ka i aur resultant ka j are constant. 
- In constant ka relation , addition of the constants are equal to n . 
  i+x=n-1, jisme se i: present row and n is the size. (x : output ka index ka col value)
  x = n-1-i .

  - matrix[i][j] => matrix[j][n-1-i];

- For the above matrix, we are using the extra matrx ans of the same size of the given matrix.  

Optimized Solution :- Solving te problem in O(1) space Complexity. 
So ab ye bhi notice kar rahe hai ki, hamara 1st col change ho ja raha hai 1st row mai but in the reverse order mai.  2nd col in 2nd but in the reverse order and similar all col.
Relation : (col -> Reverse) => Row , column ko reverse order mai kardo(given matrix), and this will be the row of resultant matrix. 
Approch :- 
- So pahle apne row ko transpose kar denge ki hamko col mil jaaye row mai
- iske baad usko reverse kar denge we got out resultant matrix

Time and space Complexity : O(nsq) and O(1)
Code Implementation :- 
```cpp
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Ṭranspose
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        swap(matrix[i][j],matrix[j][i]);
    }
    // Reverse each row  
    for(int i=0;i<n;i++)
    {
        int start=0, end=n-1;
        while(start<end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++ ;
            end--;
        }
    }
}
```

Note :-  Keep in mind that agar question se output general page par agar nikal paa rahe than its means ki koi n koi pattern toh exist karta hai, just need to find that pattern.


### Rotate Matrix 180 degree :- 
So ab hamko given matrix ko 180 degree ghumana hai. Given matrix se apna output matrix banayenge jo ham expect kar rahe hai for the analysis karne ke liye. So agar given matrix pahle 90 degree ghumaye and phir 90 degree then hamara kaam ho jayega. You can do this.

Another Approch :-
- 1st row of the given matrix is equal to the last row of the output matrix, 2nd row of the given matrix is equal the last 2nd row of the out matrix. and so on till row exist. 
  - step 1: Column wise reverse kardo :- swap(matrix[start][j],matrix[end][i]) 
  - step 2: Row wise reverse kardo  :- swap(matrix[i][start],matrix[i][end])
Note :- Reverse karne ke liye main logix yehi hai, and all the other code are same we can not from the above.

Time Complexity : O(nsq)

Code Implementation :- 
```cpp
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // ColumnWise Reverse
    for(int j=0;j<n;j++)
    {
        int start=0, end= n-1;
        while(start<end)
        {
            swap(matrix[start][j], matrix[end][j]);
            start++;
            end--;
        }
    }

    //  Rowwise Reverse
    for(int i=0;i<n;i++)
    {
        int start=0, end=n-1;
        while(start<end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++ ;
            end--;
        }
    }
}
```

### Rotate Matrix 90 degree Anti-Clockwise 
So here we rotating the given matrix in 90 degree anti-clockwise. So analysis karne ke liye we need the output matrix we expecting from the given matrix, so ki ham kuchh analysis kar paaye. 
Sare side ko left direction mai ek baar ghama do hamara output matrix taiyaar ho jayega. 

-So Anticlock 90 degree similar to clockwise 270 degree, cover ko hogi. Means hamko 90 degree ka 3 baar chala denge hamko output mil jayega. Ye solution khud se karna hai. 

2nd Approch :- 
1 row hamari answer ke  1st column mai reverse mai aa rahi hai, 2nd row , 2nd column mai reverse order mai aa rahi ans so on. 
Step 1: Transpose kardo given matrix ko , jisse row column mai change ho jeyenge
Step 2: Column-wise reverse 

Code Implementation :- 
```cpp

```

### Rotate Matrix by K time :- 
1 time matlab 90 degree, 2 time means ki 180 degree(do baar 90 degree), and so on similarly. 
- Given matrix ko agar bole ki chaar baar rotate karna hai means ki rotate nahi karna hai. 5 time than it means ki 90 degree, 6 time means ki 180 degree and so on. 
  -k%4 time ghmana, cahahe koi bhi value kyu n ho. 

- Rotate 90 degree naam ek function banao
- int main mai user se input lo k ki value ko
- k%4
- while mai condition, jab k exist kare tab tak chalo,
   - call the rotate90 function

Code Implementation :- 
```cpp
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Ṭranspose
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
}

int main()
{
    vector<vector<int>> matrix(3, vector<int>(3));
    cout<<"Enter the value in 3X3 Matrix :";
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    cin>>matrix[i][j];

    int k;
    cin >> k;

    k = k % 4;
    while (k)
    {
        rotate(matrix);
    }
}
```
  
