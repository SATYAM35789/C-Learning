### Introduction to Tree :- 
It is a type of Data Structure that represent a hierarchial relationship between data elements called Nodes. Example :-
 1.  Creating Folders in your pc, the full structure of your floders is the tree type of data structure. Relationship :- Child apne parents se relatioship mai rahta hai. 
 2. Family Parential architecture
 3. Movies selection in online Apps like hotstar, netflix,etc. 

### Different Terminology in Tree Data Structure :- 
1. Node :- Jaha Data stored hota hai , usko node kahte hai. 
2. Root :- Jis bhi node mai data stored hota hai sabse pahle.
3. Parent :-  Particular node ke just uppar wala uska parent hoga. 
4. Child :-  Particular node ke just nichhe wala uska child hoga. 
5. Edges :-  Jo bhi coonection establish hai child aur parent ke bich usko edge bolte hai. 
6. Leaf :- Leaf located at the end of the tree, and jiska koi child nahi nahi hota wo leaf node hota hai.
7. Ancestor :- Hamare purwavaj, particular node ke uppar wale node till the root node, ye sab paricular node ke Ancestor hai. 
8. Descendent :- Paricular node ke niche wale jo bhi usse connected hai till leaf nodes , all are Descendent.
9. Level :- Different stages of Life like hamara papa aur uncle sab same level hai, aur mai aur mere chaha ke larke sab ek level par. 
10. Sibling :- Jinka parents same hota hai. Wo sibling hote hai. 
11. Degree :-  Particular nide ke kitne bachhe hai. 
12. Height :- Distance between root and leaf node. 

### Binary Tree :- 
It is defined as a Tree Data Structure where each node has  at most 2 children.So hamare pass 0,1 aur 2 child ho sakte hai. Jo is property ko follow karega wo Binary tree hoga. 
If have n nodes then there will  be n-1 Edges in the tree. 

### Creating A Node :- 
Node Structure :- Contains three three part:-
1. left pointer:- Which point to the left Node of the tree structure.
2. Data :- Jaha value stored karenge 
3. Right Pointer :- Jo point karta hai, right node of the tree structure. 

### How to create Binary tree :- 
1. Given data mai jo sabse pahle hai wo root node ho jayega.
2. uske baad ke data ko pahle left side bhado aur phir right side and go so on. 
3. Agar -1 dikhta hai means next mai jis bhi pointer ke help se data banane wale usko nahi bhadna hai uske next pointer se bhado data or -1 means skip it fill to next one.

note : Ham data ko level wise daal rahe hai, pahle left and phir right.  Following the rules of the tree type structure. 

Implementation Structure : Queue:- data daal rahe hai pichhe se aur remove kar rahe hai aage se. 

Code Part :- 
Class Node :
1. Public mai ek int type ka data aur two node type ka pointer bana lenege 
2. constructor() parameter value :-  values initialize kar lenge. 

1. Ek queue banayenge q naam ka , jiska type Node hoga means ye Node ka address ko  store karega. 
2. Ek root naam ka pointer banayenge jiske ander new Node create kar denge. or root node ka address ye store kar lega
3. Queue ke ander root ko daal do
4. Agar meri queue khali nahi hai tab tak,
   1. Ek Node type ka temp pointer banayenge jisme queue ka front daal denge. 
   2. queue ko pop kardo
   3. left child ki value ko user se input karwa lenge (first int type variable)
   4. Check :- Agar left child ki value -1 nahi hoti hai tabhi left node value mai dalenge,
      1. temp ke left mai new Node mai value daal do
      2. queue ke ander push kardo temp ke left ko.
   5. Right child ki value ko user se input karwa lenge (Second int type variable)
   6. Check :- Agar right child ki value -1 nahi hoti hai tabhi right node value mai dalenge,
      1. temp ke right mai new Node mai value daal do
      2. queue ke ander push kardo temp ke right ko.


