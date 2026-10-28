### Kth Element in a matrix :- 
Hamko ek matrix diya hua hai, with N * N rows and columns, ye rows and columns dono tarah se sorted hai. Hamko ek value diya gaya k , aur puchh raha hai k smallest value kon sa hai. 

Approch 1st :- Hamara pahla approch ho sakta hai ki ham apne is 2d array ko copy karlo 1d array mai, it take O(nsq). Phir is array ko sort kardo,O(NsqlogNsq). 
Time Complexity : Nsq + NsqlogNsq + 1 = NsqlogNsq = 2NsqlogN = NsqlogN

Approch 2nd :- Is given matrix ka Min Heap bana lo :- 
1. Ek 1d array lo usme sare element copy kardo.
2. Ab is 1d array ko min heap mai convert kardo. Nsq
3. Kth element ko bahara nikalo. klogNsq = klogn
Time Complexity :- Nsq + klogn

Approch 3rd :- Dekho hamko diya hai ki hamra matrix sorted hai, abhi tak hamne sorted hone ka fayda uthya he nahi means last wala hamara optimized approch nahi ho sakta. 
1. Pahle 1st column ko apne heap mai daal do
2. Usme se jo bhi chhota hai uske next row element ko daal do. 
and do so on until tumko kth element n mil jaye. 

Time Complexity :- 
1. Build min heap : 
   Ab hum dekhenge ki O(n) time mai min/max heap priority queue ke help se kaise bana sakte hai, tab hamko In Case of max heap :- 
   Syntex :- priority_queue<int>p(v.begin(),v.end()); where v is the vector. 
2. Insertion and deletion for single :- log(n) + log(n) = 2logn

Note :-  Hamko kaise pata chalega ki next element konsa hai, so iskle liye hamko apne value ke index ko bhi store karna padega taki hamko pata chal paye. means data, row, column ye tin info daal na padega. In tin parameter ko toh haam sath mai priority queue ke ander nahi daal sakte so we use pair here. Dekho pair itna smart hai ki, ye auto matically apne pahle value ke base par compair kar dega, if 1st value same then ye second ke base par compair karega agar aur bhi karte unke basis par kar lega. 

Code Implementation :- 
```
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define MAX 100
using namespace std;

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    vector<pair<int, pair<int, int>>> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back(make_pair(mat[i][0], make_pair(i, 0)));
    }
    // Create Min Heap priority_queue<int , vector<int> , greater<int>>p(temp.begin(),temp.end());
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

    int ans;
    pair<int, pair<int, int>> Element;
    int i, j;

    while (k--)
    {
        Element = p.top();
        p.pop();
        ans = Element.first;       // value
        i = Element.second.first;  // row
        j = Element.second.second; // col num

        if (j + 1 < n)
            p.push(make_pair(mat[i][j + 1], make_pair(i, j + 1)));
    }

    return ans;
}

int main()
{
    int n = 4;
    int k = 8;

    // Sample matrix
    int mat[MAX][MAX] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50}};

    cout << "Matrix ka " << k << "-th smallest element hai: "
         << kthSmallest(mat, n, k) << endl;

    return 0;
}
```

Approch 4th :- 
1. Ye toh hamko pata hai sabse chhota elemnt 00 index par milega, so pahle isko daal do.
2. Phir isko bahar nikal do heap se, ab is attach dono element jo possible chances hai chhota hone ka unko daal do. 
3. phir un mai se jo chhota hai unko nikalo and so on till kth element found. 
Note :-  Duplicate element ki entry nahi honi chahiye heap mai. 

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

// Pair ko 'temp' naam de diya hai taaki code simple rahe
typedef pair<int, pair<int, int>> temp;

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // Min Heap banaya
    priority_queue<temp, vector<temp>, greater<temp>> pq;

    // 1. (0,0) index push karo
    pq.push({mat[0][0], {0, 0}});

    int result = 0;
    bool visited[MAX][MAX] = {false};
    visited[0][0] = true;

    // 2. K baar process karo
    while(k--)
    {
        temp top = pq.top(); // Ab 'temp' type ka variable
        pq.pop();

        result = top.first;          // value
        int r = top.second.first;    // row
        int c = top.second.second;   // col

        // 3. Right side push karo
        if (c + 1 < n && !visited[r][c + 1]) {
            pq.push({mat[r][c + 1], {r, c + 1}});
            visited[r][c + 1] = true;
        }

        // 4. Down side push karo
        if (r + 1 < n && !visited[r + 1][c]) {
            pq.push({mat[r + 1][c], {r + 1, c}});
            visited[r + 1][c] = true;
        }
    }
    return result;
}

int main()
{
    int n = 4;
    int k = 8;
    
    int mat[MAX][MAX] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50}
    };

    cout << "Kth smallest element: " << kthSmallest(mat, n, k) << endl;

    return 0;
}
```

Approch 5th :- if k=6
1. Start aur end ko pakdo, aur inke summation ko 2 se divide kardo 
2. phir count karo ki kya ye kth smallest, count the element jo ki hamare division se chhote hai. 
3. Agar ans count bada hai hamare kth se then start ko same position par rakho aur end ko shift kardo division karne ke baad(mid) aaya tha us se 1 minus karke, 
4. Phir 1 step ko karo.
5. Agar kth or count barabar mil jate hai, then hamko apne solution ko declare karne ke liye apne optimized solution ko dekhna padega, chhoti se chhoti value ko khojne ki kosis karenge, jaise he hamara end chhota ho jaye start se hamko solution khojna band karna hoga, kyuki hamko ans mil chuka hai. (Apne search area ko kam karna hai)

Code Implementaion :- 
```
#include <iostream>
using namespace std;

#define MAX 100

// Helper function: O(N) complexity mein count karta hai
int countElements(int mat[MAX][MAX], int n, int mid) {
    int count = 0;
    int row = 0, col = n - 1; // Top-right corner se start
    
    while (row < n && col >= 0) {
        if (mat[row][col] <= mid) {
            // Agar element chhota hai, toh us column ke saare elements chote honge
            count += (col + 1);
            row++; // Next row check karo
        } else {
            // Agar bada hai, toh left column mein jao
            col--;
        }
    }
    return count;
}

int kthSmallest(int mat[MAX][MAX], int n, int k) {
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Count karo ki mid se chote kitne elements hain
        int count = countElements(mat, n, mid);

        if (count >= k) {
            // Possible answer mil gaya, ab chhota search karo
            ans = mid;
            high = mid - 1;
        } else {
            // mid chhota hai, range badhao
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n = 4;
    int k = 8;
    
    int mat[MAX][MAX] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50}
    };

    cout << k << "-th smallest element is: " << kthSmallest(mat, n, k) << endl;

    return 0;
}
```

Note :- Yeh approach tab bahut powerful hoti hai jab aapko matrix ko poora traverse nahi karna hota, balki range ke basis par answer predict karna hota hai.Is approach ki sabse badi khasiyat ye hai ki isme extra memory (visited array) ki zaroorat nahi padti, isliye space complexity O(1) ho jati hai.

### Find Median in a stream :- 
Median : Nikalne ke liye pahle sorted form mai kar lena. 
1. Odd :- Uske mid index par jo value hai wo median hota hai
2. Even :- Isko do mid nikate hai dono mid ko sum karo uska jo half hoga wo median hoga. 

Approch :-
Hamko ko array diya hoga, aur hamko apne array ko traverse karo aur har index par jao aur calculate karo,
ki uska median kya hai and do so on jab tak array khatm nahi ho jata. aur unki value ko store karlo aur ans de do. 
Isme hamko ye ensure karna hoga ki hamara array sorted rahe so ki jab hum median lagaye toh hamko apna solution mil jaye. So hum median check karne se pahle sorted / element ko shift karte jaynege. 

Time Complexity :- O(nsq)

Approch 2 :-  Jab bhi hum median nikal rahe hai, tab umko sirf bich mai jo value sirf us se he matalab hai, agar hum notice kare ke even ke case jab ek mid ko se start tak ko max heap jaisa so ho raha hai aur dusre mid se end tak ka min heap jaisa structure form kar raha hai. 
Odd case :-  Jis bhi heap ka size bada hoga uksa top median hoga. 
Note: Agar kisi bhi heap ka size dusre heap se 2 jayda aa raha hai, tab us heap se ek item nikal kar dusre heap mai transfer kar dena hai. 

Diiferent Case :- 
1. left Side(Max Heap) == Right Side (Min Heap) : (Top + top)/2
2. Left Side - 1 == Right Side (Agar left side 1 se bada hai) : left side Top
2. Right Side - 1 == Left Side (Agar Right side 1 se bada hai) : left side Top

Code Implementation :-
```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> RightMinHeap;
    // Function to insert heap
    void insertHeap(int &x)
    {
        // Base Case
        if (leftMaxHeap.empty())
        {
            leftMaxHeap.push(x);
            return;
        }

        if (x > leftMaxHeap.top())
            RightMinHeap.push(x);
        else
            leftMaxHeap.push(x);

        balanceHeaps(); // question ki demand hai
    }

    // Function to balance heaps
    void balanceHeaps()
    {
        // MinHeap size (right side) should not be greater than maxHeap(left Side)
        if (RightMinHeap.size() > leftMaxHeap.size())
        {
            leftMaxHeap.push(RightMinHeap.top());
            RightMinHeap.pop();
        }

        else
        {
            // Difference blw heaps should not be greater then 1
            if (RightMinHeap.size() < leftMaxHeap.size() - 1)
            {
                RightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();
            }
        }
    }

    // Function to return median
    double getMedian()
    {
        // left > right
        if (leftMaxHeap.size() > RightMinHeap.size())
            return leftMaxHeap.top();
        else
        {
            double ans = leftMaxHeap.top() + RightMinHeap.top();
            ans /= 2;
            return ans;
        }
    }
};

int main()
{
    // Aapki Solution class ka object banaya
    Solution sol;

    // Test cases: Data stream
    vector<int> stream = {5, 15, 1, 3, 2};

    cout << "Data Stream Processing:" << endl;
    for (int i = 0; i < stream.size(); i++)
    {
        sol.insertHeap(stream[i]);
        cout << "Inserted: " << stream[i] << " | Current Median: " << sol.getMedian() << endl;
    }

    return 0;
}

``` 
