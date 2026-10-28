### Remove duplicate element from list 
Basic Approch:- Ek array lo apne list ko traverse karo aur ki agar naya number usko array mai add kardo agar nu present hai array mai toh usko chod do. 
1. ek vector integer ans naam ka le lo
2. apna data vector mai daal do ans.push_back(head->data)
3. ek pointer jo point karega head->next ko. 
4. jab tak curr exist karta hai, tab tak
   -Agar ans ka last element barbar nahi hai curr->data ke
     - ans mai curr->data daal do. 
   curr = curr->next;
   Note :- Ab tak hum duplicates ko remove and store kar chuke hai ans mai . Ab jo bhi data ans mai usko linked list mai dalna hai.

5. curr ko phir se head ko point karwa di.
6. int index = 0;
7. Jab tak index chhota hai ans.size() se
   -curr->data mai ans[index] daal do
   - curr = curr->next se bada do. 
   // Data store karne ke baad remaining list ko remove karna
8. int size = ans.size() -1;
9. curr mai head daal do
10 curr->next mai NULL dal do
11 return head

Code Implementaion:-
```
vector<int> ans;
ans.push_back(head->data);
Node * curr = head->next;
while(curr)
{
    if(ans[ans.size()-1]!= curr->data)
    {
        ans.push_back(curr->data);
    }
    curr = curr->data;
    int index = 0;
    while(index< ans.size())
    {
        curr->data = ans[index];
        index++;
        curr = curr->data;
    }

    int size = ans.size() -1 ;
    curr = head;
    while(size--)
    {
        curr=curr->next;
    }
    curr>next = NULL;
    return head; 

}
```
### 2nd Method 
1. ek pointer lenge curr naam jo point karega head->next ko and ek pointer prev jo point karega jisko head point kar raha hai. 
2. Jab tak hamara null na ho jaye tab rak,
   - agar curr->data barbar ho jata hai prev->data ke toh
     -prev->next mai curr->next dal do.
     - delete curr
     - curr mai prev->next daal do
  - Agar dono barabar nahi hai, toh
    -prev ko prev->next se bada do
    -curr ko curr->next se bada do
  - return head

  Code Implementation
  ```
  ```
  ### Merge two sorted list 
  Approch 1st :- dono sorted array mai, ek pointer lagao head1 and head2 naam ko jo ki starting koi point karega, unke compairsion ke according dusre linked-list mai, value update karte jayenge. Here we using the extra memory.
  Approch 2nd :- Extra memory nahi use karna hai. 
  In dono linked list mai jo bhi chhota hai usko point karwa denge so on yahi karta jayenge. 
  1. Ek extra node bana lenge kisi bhi value daal kar, jisko head point kar raha.
  2. tail naam  ka pointer jo head  daal do.
  3. Jab tak head1 aur head2 exist karta hai
    - Agar head1->data hai wo head2->data se chhota hai ya barabar hai, 
     - Tail->next mai head1 daal do. 
     - head1 mai head1->next daal do
     - tai mai tail->next se increse kar do. 
     - tail->next mai NULL daal so
    - Agar aisa nahi hota hai, 
     -tail->next mai head2
     -head2 mai head2->next daal do
     -tail mai tail->next se bada do
     -tail->next mai NULL  de do. 
  4. Agar head1 exist karta hai :-
      -tail->next mai head1 daal do
     Agar head2 exist karta hai
      -head2 mai head2->next daal do
  5. Extra jo jode usko remove karna hai
      -Tail mai head ko daal do
      - head mai head->next daal do
      - delete tail
      - return head;

Code Implementaion :- 
```

```

### Sort a List which contain 0 1 2
 Without using extra memory:-
  - Initalize the three count variable count1, count2, count3 . In tini numbers ko count karlo in variavle ke help se. 
1. ek pointer banayenge, curr naam isme head daal denge. 
2. initialize varaible count0 = 0, count1=1, count2=0
3. jab tak curr exist karta hai, tab tak
   - Agar curr->data barabar hai 0 ke
      - count0++
   - Agar curr->data barabar hai 1 ke
     -count1++
   -else
     count2++
4. curr mai head daal 
  Iseke simple Update according to this varible in linked list

Code Implementaion :
```

```
Enhancing Problem:-
 - Maan same question mai, data ko change nahi kar sakte toh same question kaise karte. 
 Appeoch:- Initialize three pointer head0, head1 and head2 , jis bhi type ka value us type ke pointer se connect kardo , baad mai inko aapas mai connext kardo.  

