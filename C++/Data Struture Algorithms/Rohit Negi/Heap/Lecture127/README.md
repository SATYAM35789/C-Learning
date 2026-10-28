### Smallest Range Covering all elements from k lists
Hamko smallest range find karna jisme sare given list ke kam se kam ek list present ho. Hamare pass bahiut sari possibility ke answer ho sakte hai hamare pass means bahut sare ranges exist kar skte jo ek answer ho sakta hai lakin hamra answer wo hoga jis range ka differenece sabse kam hoga. 
Note :- It is possible answer ki do ranges ka difference same aa jaye then usme jo smallest as in no. hoga usko select karenge. 

Brute Force approch :- Is approch ka lagane se pahle ham sare list ko ek single list mai copy kar lenge then starting ke do element ko pakdenge aur check karenge kya is range mai tin list element exist karte hai ki nahi, if yes thon note it down and now ab 1st element aur 3rd element, then 1st and 4th element and aise he sabko check kar lenge. 
Time Complexity :- Assuming there is k list exist and in each list there is n element. so there nk element in the copy array. O(kn)
2. And creating range with each and every element , take (nk)sq
3. and checking ki ranges mai list ki exist karta hai ki nahi O(nk)
Time complexity = O(kn) + (nk)sq*nk.

2. Using Min heap :- 
Sare list ke pahle element ko daal do heap mai , usme se min aur max nikal lo. phir uska range bana lo, then outcome may be the possible ans. Hamre ans ko optimized ans banane ke liye hamko chahiye ki range ka difference kam se kam ho. Uske liye range ke 1st element ko increse karna hoga, aur 2nd value decrese. We are doing incresing in these question. 
Range mai se min ko hata do aur uske next element se range create karne ke kosis karo like pahle ja create kiye the. 
Example:- 
1. 4,0,5 :- range [0, 5]  
2. range:- [ , 5] -> 4,9,5 -> range [4, 9] and so on choote ko hatao aur uske next ko dalo aur new range defined kar lo. 
Note :-  Check karte jayenge ki kya ye range ans ho sakta hai, means uske difference kam dusre range se jo ham pahele nikal chuke hai. 
1. Agar jaise koi list khatam ho jati hai then wo mera termination step hoga uske baad hum range defind karme ka process chod denge. 
Ham 2nd term kyu nahi decrese kar rahe hai, kyu agar 2nd term ko remove karte hai aur uske next ko daalte hai toh hamari range badegi kyuki list ke element sorted hai. 

min updation :- Min heap ke through ham apne list ko update kar denge.
max updation :- min heap mai dalne se pahle hum check kar lenge kya jo element ham daal rahe wo max se bada hai, if yes then update the max. 
1. ab ham heap se value ka bahr nikal rahe tab hamko ye bhi pata hona chahiye ki , jisko bahar nikale hai uska next element konsa hai. means ki konsa list ka , konsa element hai. 

Code Implementation :- 
```
#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

vector<int> smallestRange(vector<vector<int>> &nums)
{
    // min heap
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;

    int minimum, maximum = INT_MIN;
    // Insert first element of each roe int heap
    for (int i = 0; i < nums.size(); i++)
    {
        p.push(make_pair(nums[i][0], make_pair(i, 0)));
        maximum = max(maximum, nums[i][0]); // compairing present element with the max
    }

    minimum = p.top().first;
    vector<int> ans(2);
    ans[0] = minimum;
    ans[1] = maximum;

    pair<int, pair<int, int>> temp;
    int row, col, element;

    while (p.size() == nums.size())
    {
        temp = p.top();
        p.pop();

        element = temp.first;
        row = temp.second.first;
        col = temp.second.second;

        // next element ko daal if exist
        if (col + 1 < nums[row].size()) // ek list mai kitne col hone wale hai, no of col = nums[row].size()
        {
            col++;
            p.push(make_pair(nums[row][col], make_pair(row, col)));
            maximum = max(maximum, nums[row][col]);
            minimum = p.top().first;

            // Checking ki differnce pahle wale range difference se kam hai.
            if (maximum - minimum < ans[1] - ans[0])
            {
                ans[0] = minimum;
                ans[1] = maximum;
            }
        }
    }
    return ans;
}
int main()
{
    // Example Input: 3 sorted lists
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> result = smallestRange(nums);

    cout << "Smallest Range is: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
```

### Construct target with multiple sum :-
Hamko ek array achieve karna hai, so starting mai same size ka arr hoga hamre pass jisme pahle se 1 initialize hoga. Kya hum is one one ko convert kar sakte hai target array mai. 
Conversion ke techniques :- 
1. Ham purre array ka sum nikal sakte hai aur us sum ko kisi bhi index par update kar sakte hai. Ham aisa karte jayenge jab tak hamko hamara array nahi mil jata. 
Konse type ke array ko acheive nahi kar sakte  :- Jab koi aisa element present hai array mai jo hamre 1st sum means jab initize case ka sum se chhota element hai then usko achieve nahi kar payenge. 

Summation ka update kaha aur kaise kare?
Jab ham is problem ko solve karne ki kosis kar rahe honge tab problem aayegi ki konsi index par jakar apne sum ko rakhe taaki ham apne solution ko achive kar paye kyuki agar ek bhi galat jagah update hota hai then apne soluion lo pana impossible ho sakta hai. 
Agar hum reverse order mai kaam kare toh possible ho sakta hai. So hamko pata hai ki summation ka change ek he jagah hona hai, so hamko pata karna hoga ki konsa change ho hua hai, isko ham easily find kar sakte hai ki, step par jo sabse maximum element hai wahi change hua hoga. Kyuki ham iske pahle step mai sabka sum kar rahe hai, jo ki sabse bada hoga. 

Jab ham reverse or back step par  ja rahe honge then hamko kaise pata chalega ki maximum ke jagah par kon sa Element hoga?
Iske liye ham jis bhi step par hai pahle uska remaning sum nikalna hoga. 
1. RemSum = sum - maxElement  (of present step)
2. Element + RemSum = MaxElement -> Element = MaxElement - RemSum

MaxElement : Present state ka maximum element
Sum : present state ka total sum
Element : MaxElement jo present ka hai uske pahle wale step  ki value 
RemSum : present state mai maxElement chodkar kar, unka sum

Note :- Direct maxElement ke jagah konsa element hai uski value nikalne ke liye  MaxElement of present state - remSum of present element.

Is process ka Base case kya ho sakta hai, means sabka solution exist kare zaruri toh nahi so when to stop searching for the solution:- 
1. Agar remaining sum ki value less than equal to zero ho jaye tab hamara ans nahi nikalega or remaining sum ki value grater than equal to sum ho jaye tab ans hamara nahi nikal sakta. 

Code Implementation :- 
```
#include <iostream>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

bool isPossible(vector<int> &target)
{
    // Max Heap : kyuki sabse pahle , badi value ko bahar nikal rahe hai
    priority_queue<int> p;
    int sum = 0;

    for (int i = 0; i < target.size(); i++)
    {
        p.push(target[i]);
        sum += target[i];
    }

    int MaxElement, RemSum, Element;
    while (p.top() != 1) // jaise he top ki value 1 hoti hai means ki vector mai one one present ho
    {
        MaxElement = p.top();
        p.pop();
        RemSum = sum - MaxElement;

        // Edge cases :- MaxElement = RemSum -Element
        if (RemSum <= 0 || RemSum >= MaxElement)
            return 0;

        Element = MaxElement - RemSum;
        // Updating Sum Values
        sum = RemSum + Element;
        p.push(Element);
    }

    return 1;
}
```

Above implementation code has give the time exceed error, se we need optimized our ans. 
Jaha par ek he index barbar change ho raha hai, then is case ko ham kaise handle kar sakte hai, jiske wajah se hamre time complexity bad ja rahi hai. 
We can write these instead of calculating Element like this
Element - MaxElement - RemSum
to this :-  Element = MaxElement%RemSum. 
So modulas nikalte samay Value 0 bhi aa sakta hai so is case ko kaise handle karenge ?
Agar Element%RemSum = 0 aa jata hai aur RemSum barabar nahi hota 1 ke tab hamara solution exist nahi kar sakta. 

```

```

