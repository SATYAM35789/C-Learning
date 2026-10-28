### Column Major Order :- 
So isme jo bhi 2d array ham visualie karte hai, wo memeory me column wise save hoga. 

How can we find that ki particular index memory mai kaha jakar save hoga? 
-> given index, rowSize and colSize hamko diya hua hai, so toh kya ham find kar sakte hai. 
-> Wea have to find out the formula by self as we studeied in last lecture, and it is the wasy task. 

By default, c++, java,etc follows the Row major Order.
-> And jo hamare pass databases hote hai, so jaha ham bahut saare data ko store karte hai, wha apni application ke according kisi bhi tarike se kar sakte hai. Ye customized kar sakte hai. 
- And hamko pata hai ki, jo 2d array ke data hote hai wo actually mai 1d array ke form mai he store hote hai in contigous location form . 

Real world example to understand RMO and CMO application
- so isme ham example ke help se ye sikh rahe hai ki, RMO nd CMO ko ham kis case mai use kar sakte hai.
- Banking mai account detail sheet 
- Not RMO because, in that case opertion perform like calculation total amount is difficult where as easier and structure or similar data are nearar, so CMO. 
- RMO useCase (facebook user detail)

### 2d vector 
Similar to 2d array hota hai. 
## Creating 2d vector :
syntex : vector<vector <int>> vactorName;

Defining the row and col of the 2d vector, with initializing some value :
Syntex : vector<vector<int>> vectorname(rowsize, vector<int>(colsize, intializingValue)) ; 

## Updating value in the 2d vector :-
vectorName[1][2] = 5;

-> Input in the 2d vector :- 
   cin>>vectorName[2][2] ; 

-> Finding the row and col of the 2d vactor : 
   - row = vactorName.size() ;
   - col - vectorName[0].soze(); :- jo row hai uska size kitna hai, as row mai he toh col change ho raha hota hai. 

```cpp
int main()
{
    //  Creating the vector
    // vector<vector <int>>matrix;
    vector<vector<int>> matrix(3, vector<int>(4, 1));

    //  Print the value of the 2d vector
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            cout << matrix[i][j] << " ";

    cout << "Rows :" << matrix.size() << endl;
    cout << "Col :" << matrix[0].size();
}
```
Taking Input from the user
```cpp
int main()
{

    int n,m;
    cout<<"Enter the rows and cols"<<endl;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m, 1));

    //  Taking input from the user
     for (int i = 0; i < n; i++)
     for (int j = 0; j < m; j++)
        cin>>matrix[i][j];
    
     //  Print the value of the 2d vector
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        cout << matrix[i][j] << " ";
        cout<<endl;
    }
}
```

### Wave Form :- 
So hamko ek matrix given hogi 2d form mai. So hamko isko wave form mai print karwana hai. Like 1st index se start karo pahle niche aao, phir uppar jao,phir nichhe aao phir uppar jao. Is process mai jo bhi element aaye unko bhi print karte jao(jis order mai hamko mil rahe hai). 

Approch :- 
So isme notice karenge toh pata chalega ki actually mai toh hamko col ko he print karna hai, bas unki direction ulta ho ja raha hai. 
- so jab bhi col, even hai tab ham, up to down direction mai value ko print karwa rahe hai. 
- and odd ke case mai down to up direction 
So ab har col par jeyenge, unko print karwa denge(with having some condition)
Condition :- 
- Agar j%2 ==0 hai then (up->down)
    - hamko pata hai ki, row change ho raha hai, in incresing order. 
    - ek loop chalao from i=0 se i< row tak
       - cout<<[i][j];
- else(down->up)
    - ek loop chalega from i lesstahn row-1 se i=0 tak.
      - cout<<[i][j];

Time Complexity : O(row * col)
   
```cpp
void wave(int arr[][4], int row, int col)
{
    for( int j=0;j<col;j++)
    {
        if(j%2==0)
        {
            for(int i=0;i<row;i++)
            cout<<arr[i][j]<<" ";
        }
        else
        {
            for(int i=row-1;i>=0;i--)
            cout<<arr[i][j]<<" ";
        }
    }
}
```

### Spiral form 
Ab given matrix ko hamko spiral form mai print karna hai, See the diagram on the google that spiral visual lization on the 2d array, how the output is dilevered. 

Approch :- 
So isme ham, sabse upperwale ko print karwa do, phir sabse right wale ko, sabse bottom wale ko and then sabse left wale ko and so on karte jao , jab tak exist kare.(Top , Right, Bottom, Left) 
- Top : Top ko print karwane ke liye left se right saare element print karwa do. 
    ```cpp
     for(int j=left; j<=right;j++)
      cout<<matrix[top][j] ;
      top++ ;
    ```
   - Top ko print karwane  ke baad top ++ kardo, ek  se bada do 
- Right : So top ko ek se bada dene ke baad, ab wo niche aa gaya hai iske help se rightmost of 2nd row ko access kar sakte hai. 
  ```cpp
    for(int i=top;i<=butto;i++)
    cout<<matrix[i][right];
    Right--;
  ```
- Bottom : Right se laker left value ko print karna hai.
```cpp
for(int j=right;j>=left;j--)
cout<<matrix[bottom][j];
bottom--;
```
- Left : Bottom se laker top tak print karwa, do
```cpp
for(int i=bottom;i>=top;i++)
cout<<[i][left];
left ++;
```

Edge case :-
Break condition :-  
1. jaise he top, bottom se bada ho gaya, waise he ham ruk jayenge  
2. jaise he left bada ho jaye right se toh ruk jao. 

1.  Bottom wali condition tabhi cahlega jab top chhota ya barabar hai bottom ke. 
2. left wali condition tabhi chalegi, jab left chhota ya equal hai right ke. 

Code Implementation :- 
```cpp
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    int top = 0, bottom = row - 1, left = 0, right = col - 1;

    while (left <= right && top <= bottom)
    {
        //  Print top
        for (int j = left; j <= right; j++)
            ans.push_back(matrix[top][j]);
        top++;
        //  Print right
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        //  Print bottom
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
                ans.push_back(matrix[bottom][j]);
            bottom--;
        }
        
        //  Print left
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }
    return ans;
}
```

### Transpose Matrix :- 
So hamko n x n  ki matrix diya hoga, aur hamko usko transpose karna hoga. Transpose means row ko colmai change kardo or col ko row mai change kardo. 

Approch :- 
- ek same size ka matrix banana hoga. 
- So analysis karne ke liye sabse pahle, apne matrix ki index kardo. aur iska transpose nikal do jo yum output expect kar rahe ho. 
- Ab ham ye find kar pa rahe hai ki Agar i == j hai then uski sahi position pahle wali he hai.
- jab i aur j barabar nahi then 
   - ij ki sahi position ji ho ja rahi hai at every index. 

Note: Agar barabar bhi hai tab bhi , technically i aur j toh same he rahega.means ki us index par bhi agar ij ko ji kar denge toh bhi koi fark nahi padega, hamko check nahi karna padega. 

- inner loop chalo , i and j from 0 to n
  - arr[j][i]= arr[i][j];
Space complexity = O(nsq)

Now We needd to do this in the O(1) space complexity.
- Just go and swap the position of the ij with ji. Lakin ham ye sabke sath nahi kar sakte if sabe sath karenge toh phir se same array mil jayega. 
- So jab bhi j bada hai i se then swap kardo, if not then no need to swap. Above two lines are my anaysis.  OR 

Approch : 
Code Part :- 
- ek for loop lo jo i=0 se chalega aur i lessthan row-1 tak chalega
  - ek for loop lo jo i+1 se chalega aur j lessthan col tak jayega
    - swap(matrix[i][j], matrix[j][i]);

Code Implementation :- 
```cpp
void transpose(vector<vector <int>> &matrix, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        swap(matrix[i][j],matrix[j][i]);
    }
}
```
