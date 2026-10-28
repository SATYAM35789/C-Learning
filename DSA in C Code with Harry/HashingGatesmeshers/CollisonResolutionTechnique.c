/*
#2
How to handle collision in handling? Or Collision Resolution techniques
It is basically when two inputs are gets the same hash value. 
To remove the collision:- 
1.Chaining(Open hashing) :- We have create a external chain. BY creating a link list we can add the that another no.
  And using the extra space.  
2.Open Addressing(Closed hashing):- 
 -> linear Proting :- Next available space ko use karenge. 
 ->Quadratic Proting :- R + isquare(Probe no: kitni bar check kiya)
 ->Double Hashing:- Use two hash function first one enter the data second function se collision ko resolve karte hai

#3
 Chaining(Open hashing):-
 Keys: 42, 19, 10, 12
 kmod5
 Approch to collision
 1. Create a node (singly link list)
 2. One pointer which points the Newnode from the hash value of the entering data. 
 Advantages:-  
  Deletion is easy O(n).
  Insertion in O(1).
 Disadvantage:-
  Searching O(n) 
  Use extra space while having the space. 
Load factor : Total no keys divided by no. of slots. 

#4
Linear Probing:- 
 R(k) = kmod10
 R'(k,i) = (h(k)+i)mod10      When collision occur  i is a probe no. collision no. 
 keys: 43,135,72,23,99,19,82
 Advantage: No Extra space.
 Disadvantages: 
  Search time O(n)
  Deletion Difficult
  Primary clustering:- Increaing the probability of box(space). Searching time will decrease.
  Secondary clustering:- Two or more element are competing for the same probe sequence. 
  While deleting, if one of the space is empty or deleted earliar than give one symbol to that space  of the place.  

#6 
Quadratic probing:-
h(k)= kmod10
h'(k,i): (h(k)+isq)mod10
keys: 42,16,91,33,18,27,36,62
Advantage:-
  No extra space
  primary clustring resolved
Disadvantages:
 Search O(n)
 secondary clustring
 No Gaurentee of finding slot.

#7 
Doble Hashing:-
Using two hash function. 
keys: 20,34,45,70,56.
k is leys/value
h1(k)= kmod11
h1'(k)= 8-(kmod8)
(h(K)+ih2(k))mod11
uper Dono function mai se ek ko prime hona chihiye.
Advantages:- 
-No extra space
- No primary clustring
- No secnodary
Dis:
O(n)
*/