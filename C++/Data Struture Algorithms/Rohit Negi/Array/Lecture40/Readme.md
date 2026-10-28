### Roman To Integer :- 
So hamko ek Roman number diya gaya hoga, aur hamko usko simply Integer mai convert karke dena hoga. Constraints ye hai ki hamara jo bhi answer hoga wo 1-3999 tak he lie karega. 

Roman No :- Ham ye consider karte hai ki agar next number us se bada hai , then pahle wale ko negative no. consider karte hai. like IV -> V bada hai I se then V=5, I=1 so 5-1 = 4. Agar next no. chhota hai then usko positive maanenge like VI, I chhota hai V se then 5 + 1 = 6.

So mere nnext wala mujse bada hai then khude ko -ve consider kar lenge and if chhota hua or barabar hua then +ve he consider karege apne aapko. 

Code Part :- 
- string s diya hoga jisme Roman no diya hoga. 
- do int type ka variable lenge sum=0 and index=0
- ek while loop lenge jo tab tak chalega tab tak index chhota hai s.size-1 kyuki last wale ke baad koi     character hai he nahi compair karne ke liye.
  - So compiler ko toh pata nahi hai X = 10 and L=50 hota hai so hamko pahle islo number mai convert karna hoga with help of num(). if num(s[index]) is lessthan num(s[index+1]) se then
    - sum -= num[s[index]]
  - else
     - sum += num(s[index])
  - index++
-sum + = num(s[s.size()]-1);

int num():- We easy we will se direct on the code Implementation 

Code Implementation :- 
```cpp
int num(char c)
{
    if(c=='I')
    return 1;
    else if(c=='V')
    return 5;
    else if(c=='X')
    return 10;
    else if(c=='L')
    return 50;
    else if(c=='C')
    return 100;
    else if(c=='D')
    return 500;
    else
    return 1000;
}

int romanToInteger(string s)
{
    int sum=0, index=0;
    while(index<s.size()-1)
    {
        if(num(s[index]) < num(s[index]+1))
        sum-=num(s[index]);
        else
        sum+=num(s[index]);
        index++;
    }
    sum+=num(s[s.size()-1]);

    return sum;
}
```

### Integer to Roman
So yaha hamko integer diya hoga aur hamko Roman mai change karna hoga. Ex 1248 -> 1000+200+40+8 -> M+CC+XL+VIII => MCCXLVIII.
Note: 1000 + 200+40+8  So hamko 1000 ka directly matlab pata hai so uska nikal sakte hai but 200 ka kace nikalenge so hamko ye pata karna hoga us particular position par kya kya aa sakta hai once position par 1/2/3/4/5/6/7/8/9/10 aa sakte tha or tens position par 10/20/30/40/50/60/70/80/90/ and so on the at different position. Different position par different possibility aa sakte hai aur ham saari possibility ko chahe ek ek karke define kare.
And Then try to bulid the logic.

### Factorial of a Number :- 
So pahle jab ham factorial number nikal rahe the tab hamko ineger overflow ka error aa raha tha. Means ki jitna capacity store karne ki integer us se jayda aa raha hai integer store karne ke liye. Int type size 4 bytes = 32 bit but isse jayda aa ja raha value store karne ke liye. Integer that can be stored by int type of variable is 2^-31 to 2^31-1.

So Isme ham ek string lenge jisme ham 1 by default value rakha hua hoga, let n=8 then 8,7,6,5,4,3,2,1 sabko ek karke us string se multiply karnge then we got the answer. 
- String se digit ko bahar nikalna hoga as an character
  - character ko number change karenge as 'char'-'0'
  - then multiply operation perform karenge

So is better option hai hamare pass jaha hamko conversion ka zarurat he na pade. So hamko pata hai ki string ek array hota hai so ek array le sakte int type ka. So intilly is array ke ander koi ek he digit aa sakta hai in range of 0-9. So is tarah ham directly multiply kar sakte hai-
- Ab jab multiply karenge, us case agar agar do digit value aayega then answer ko revere order mai value ko store karenge like 8 * 7 = 56, lakin ham store karenge array mai 65. 
- Reverse order mai hone ke wajah se ham directly array starting index se he multiply karna start kar sakte hai if carry aata hai then isko directly last of array mai add kar denge. and so on karte jayenge till n exist.

Code Part :- 
- ek int type ka vector banayenge ans naam ka 1 size ka jisme initially 1 value hoga. 
- ek while loop chalayenge, jab tak n bada hai 1 se tabtak
  - int carry=0, result, size = ans.size()
  - ek for loop chalao, i=0 se i<size tak
      result = ans[i]*N + carry
      carry = result/10;
      ans[i]= result%10;
  - while: jab tak carry exist karega
    - ans.pushback(carry%10)
    - carry/=10
  - N-- kardo
- reverse()

Code Implementation :- 
```cpp
vector<int> factorial(int N)
{
    vector<int> ans(1,1);

    while(N>1)
    {
        int carry =0, res, size= ans.size();
        for(int i=0;i<size;i++)
        {
            res = ans[i]*N+carry;
            ans[i]=res%10;
            carry = res/10;
        }

        while(carry)
        {
            ans.push_back(carry%10);
            carry/=10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
```
