### Reverse Array
Approch: direct element ko stack ke ander dalo, phir wapas ek ek kar ke store karlo array mai , hamara array reverse ho chuka hoga. 
Code part
1. sabse pahle ek stack create karenge jo store karega value , jis type ka array/vector mai value stored hai.
2. vector ke size itna ek, for loop chalayenge
   1. vector ke ander push kardo elements ko
3. jab tak stack empty n ho jaye tab tak
   1. s[i] ke andar st[top] ko dal do. 
   2. i++
   3. st.pop()

Space and Time Complexity :- O(n)
Code Implementation :-
```
// Recerse Array or String
void reverseString(vector<char> &s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }

    int i = 0;
    while (!st.empty())
    {
        s[i] = st.top();
        st.pop();
        i++;
    }
}
```
### Insert at Bottom :- 
jo bhi value humko mil rahi hai usko hamko sabse nichhe or bottom mai store karna hai. Ye karne ke liye hamko sara element bahar nikalna padega phir ander dalna hoga , means kahi store karna hoga. Let take it another temporary stack. 
Approch steps :
1. Pahle apne stack ko khali karo phir 
2. element bottom mai insert karo
3. jaha khali kiye waha se phir se restore karo.

Code Steps:-
1. ek temp naam ka stack create karo
2. jab tak st.empty khali na ho jaye tab tak,
   1. temp ke ander st.top ko dal do
   2. st ko pop kar do
3. Restoring back to original stack
   1. jab tak temp.empty khali na ho jaye tab tak,
     1. st ke ander temp.top ko dal do
     2. temp ko pop kar do

Time and Space Complexity :- O(n)

Code Implementation :-
```
// Insert At Bottom :-
stack<int> insertAtBottom(stack<int> st, int x)
{
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }

    st.push(x);

    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    return st;
}

```
### Make the array beautifil :-
Hamko karna kya hai, hamare pass ek array hogi integer ki, jisme condition -ve +ve no. sath mai nahi rah sakte. 
Approch steps :-
1. Jis array ko beautiful banana hai, wo humko di hogi, hum ek stack banayege usme neighbour element ko dalte jayenge condition ke according, agar present element array ki condition ko match karti hai toh, array ko aage bado denge, stack se pop karwa denge. Last mai jo bhi value stack mai hogi usko arr may store karwa kar bhej denge. 

code Step:-
1. ek stack bana lo 
2. ek for loop chalega , array ke size ka
   1. Agar stack empty hoga , toh pahle elemeny ko stack mai push kardo. 
   2. Agar arr[i] hai wo bada ya barbar hai 0 ke , tab
      1. Agar s.top hai wo bhi bada ya barabar hai 0 ke, tab
         1. push the arr[i] in the stack
      2. Agar s.top chhota hai, tab
         1. s.pop() remove the element from the stack.
   3. agar s.top chhota hai , 
       1. s.push(arr[i]) the elemnt in the stack
      else: mai pop kar do elemet from the stack
3. Storing the stack element in the vector ans mai
   jab tak stack khali n ho tab tak ans[i] mai value dalte raho. 

Code Implementaion :-
```
vector<int> makeBeautiful(vector<int> arr)
{
    stack<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        // Stack Can be element
        if (s.empty())
            s.push(arr[i]);
        // non negative number in arr
        else if (arr[i] >= 0)
        {
            // Element present is stack is non negative
            if (s.top() >= 0)
                s.push(arr[i]);
            // Element present is stack is  negative
            else
                s.pop();
        }
        // negative number in arr
        else
        {
            // Element present is stack is  negative
            if (s.top() < 0)
                s.push(arr[i]);
            // Element present is stack is non negative
            else
                s.pop();
        }
    }

    vector<int> ans(s.size());
    int i = s.size() - 1;
    while (!s.empty())
    {
        ans[i] = s.top();
        i--;
        s.pop();
    }

    return ans;
}
```

### String Manipulation :- 
Agar array ke string mai same element present hai toh dono ko hata dijiye. Ye karne ke baad jitna bhi array ka size hoga usko return karke dena hai ans mai.
1. Ek stack create kar lo. 
2. first element ko daal do  array ki, uske baad array ki value ko stack ke top se compaire kar lo jo is same then remove the element from the stack and array ke next element ko check kar.
3. stack ke size ko return kardo wahi answer hoga. 

Code Implementation :-
```
// String Manipulation
int removeConsecutiveSame(vector<string> v)
{
    stack<string> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
            s.push(v[i]);
        else if (s.top() == v[i])
            s.pop();
        else
            s.push(v[i]);
    }
    return s.size();
}

```

### Parenthesis is valid or not :-
Type of problem we can solve using stack ,  Agar kisi question humko puchhta hai ki past ke data ke basis tab humko usko store karwana padta hai , for storing the best we have is stack , answer aa raha tab jaise is question mai , hum check kar rahe on close bracket ki pahle kahi open bracket hai ki nahi. 

1. stack create karenge string type ka
2. for loop chalenge str ke size tak
3. if :- Agar str[i] barabar hai 'C' ke tab
4. tab stack mai str[i] lo push kar do
5. else :- 
    if :Agar stack empty hai tab 0 return kar do
    else : stack ko pop kardo. 
6. return s.empty() tab return 1 hoga. 

Code Implementation:- 
```
//  Check parenthesis is valid or not
bool check(string str)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        // Opening bracket
        if (str[i] == '(')
            s.push(str[i]);
        // Closing bracket
        else
        {
            //  Kahi stack khali toh nahi hai
            if (s.empty())
                return 0;
            else
                s.pop();
        }
    }
    return s.empty();
}
```
Time and space Complexity :- O(n)

Optimizing the above Approch:- 
1. ek interger defind karlo left naam ka
2. for loop ko str.size tak chalayenge
3. if: Agar str[i] hai wo barabar hai openBracket ke '(' tab left ko ++ kar do
4. else:
   if: Agar left ki value, 0 ke barabar hai, toh return 0 kardo
   else: left ki ek se decrement kar do
5. return agar left==0 :- agar left 0 hua toh return mai 1 jayega.

Code Implementation:-
```
//  Check parenthesis is valid or not
bool check(string str)
{
    int left = 0;

    for (int i = 0; i < str.size(); i++)
    {
        // Opening bracket
        if (str[i] == '(')
            left++;
        // Closing bracket
        else
        {
            if (left==0)
            return 0;
            else
            left--;    
        }
    }
    return left==0;
}
```

### Minimum add to make parenthesis valid
 Agar koi invalid string hamko milta hai , tab hamko batana hai ki, kitna string ki zarurat hai us string ko valid banaya ja sake. 
 1. ek stack lenge char type ka
 2. ek variable lenge count naam ko jo count dega parenthesis ka jab closing ka
 3. for : ek loop string ke size ke itna chalega. 
 4. if: string[i] barabar hai '(' ke tab, stack mai string[i] ko push kardo
 5. else
      if: Agar stack khali hai, tab count++ kar do
      else: stack mai pop operation.

Code Implementaion :-
```
// Minimum add to make Parenthesis valid :-
int minAddToMakeValid(string s)
{
    stack<char> st;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        // Opening Bracket
        if (s[i] == '(')
            st.push(s[i]);
        //  Closing Bracket
        else
        {
            if (st.empty())
                count++;
            else
                st.pop();
        }
    }
    return count + st.size();
}
```
### Valid Parenthesis :-  
yaad ye rakhana hai ki, pichhle wale ko he check karna hai.  Apne priveous, adjecent se match karna . 
Procedure:-
1. ek stack bana lo,  jo char type ka value store karega. 
2. ek for loop jo string ke size ke itna chalega
3. if: agar string ka value barabar hai '(' ya '{' ya '[' iske toh, stack mai string ka value push kar do.
4. else:
     if: Agar String empty hai toh  return 0 kardo. 
     else if : Agar s[i] barabar hai ')'
       if: agar st.[top] barabar nahi hai '(' , toh return 0 kardo
       else : stack ko pop kardo
     else if : Agar s[i] barabar hai '}'
       if: agar st.[top] barabar nahi hai '{' , toh return 0 kardo
       else : stack ko pop kardo
     else  : Agar s[i] barabar hai ']'
       if: agar st.[top] barabar nahi hai '[' , toh return 0 kardo
       else : stack ko pop kardo
5. return st.empty() : agar empty hai 1 hoga. 

Code Implementaion :- 
```
// Valid Parentheses
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        // Opening
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        // Closing
        else
        {
            // empty hai ya nahi
            if (st.empty())
                return 0;
            // Check for this )
            else if (s[i] == ')')
            {
                if (st.top() != '(')
                    return 0;
                else
                    st.pop();
            }
            // Check for this }
            else if (s[i] == '}')
            {
                if (st.top() != '{')
                    return 0;
                else
                    st.pop();
            }
            // Check for this ]
            else
            {
                if (st.top() != '[')
                    return 0;
                else
                    st.pop();
            }
        }
    }
    return st.empty();
}
```

### Background String Compare 
S = ab#c t = ad#c  # :- #(Backspace) iske pahle wale ko hata do. then s=ac and t = ac Ab ye dono answer equal hai, toh iska answer dena hai 1.

### Print Bracket Number
Hamko print karna hai, ki bracket ka number kitna hai given string mai.

Code Imlementation:-
```

vector<int> bracketNumbers(string s)
{
    int count = 0;
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < s.size(); i++)
    {
        //  Opening
        if (s[i] == '(')
        {
            count++;
            st.push(count);
            ans.push_back(count);
        }
        // Closing
        else if (s[i] == ')')
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
}
```

### Get Minimum At pop
Pop karte samay , hum stack ke sabse chhota element ko print karwana hai.
1st Approch :- ki hum do stack le le aur ek dusre mai dalte rahe aur pop karte rahe, dalte samay check kar lenge ki konsa chhota hai. 
2. Optimized Approch :- Stack mai push karte samye , arr[i] aur stack ke top mai se jo bhi element   sabse chhota hai usko dalna hai.
Code Implementation :
```
// Function to push the elment in the stack
stack<int> push(int arr[] , int n)
{
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        st.push(arr[i]);
        else
        st.push(min(arr[i],st.top()));
    }
    return st;

}

// Fun to print the minimum value  while poping
void getMinAtPop(stack<int> s)
{
     while(!s.empty())
     {
        cout<<s.top()<<" ";
        s.pop();
     }
}
```
