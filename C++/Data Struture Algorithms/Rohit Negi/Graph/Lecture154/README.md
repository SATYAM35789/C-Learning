### Hamiltonian Path :- 
Hamko ek graph diya hoga aur bolega, har node traverse karna hai exactly one time. So if we are able to visit every node exactly one time then we call it hamiltonian path. And kisi bhi edge ko ek se jayda baar traverse nahi kar sakta. Agar sari edges graph ki traverse nahi hoti then it's ok. 

Note : Agar koi graph disconnected hai, then wo kabhi bhi hamiltonian path nahi ho sakta. 

So hamko agar kisi bhi graph mai dhoondna hai, ki hamiltonian path exist karta hai ki nahi so iske liye ham brute force methodhe used karte hai. So yaha ham sari combination try karte hai. So agar traverse karte samay hamko sari neighbour visited milta hai aur ham sari node visited nahi hai then ek kadam pichhe jate aur dusra side select karte hai for right and do on all explored and visited then we can say that ki hamiltonian path mil chuka hai. 

So yaha hamare pass koi formula nahi mila abhi tak to find the hamiltonian path, So jo ham yaha kar rahe hai ki sare possible path ko explore kar rahe aur answer nahi mil raha hai toh wapas aa ja rahe uske pichhle node phir all possible solution jo optimized ho usko find krne ki kosis kar rahe hai, so is Approch ko bolte back- tracking Approch. 

So agar ham jaha se start kiye the waha wapas ja sakte hai , then we call it a hamiltonian cycle. 

Real World Example :- Delivering item, ek city mai ek baar jana hai, taaki samay bache. 
1. Travel Sell's Man Problem :- Har ek city ek baar he jaaye. 
Time Complexity : Exponential N!

When we apply Dp here then we got the solution in Nsq2N time mai. 
Note :- Hamiltonian path nikalne ke liye hamko apna starting point bhi carefully choose karna hoga. 

1. Hamiltonianpath exist karta hai then hamiltonian cycle will exist cannot be true. 
2. Hamiltonian Cycle exist then hamiltonian path exist.

Note : Agar eular path mai agar hamse actual path puchh liya then yaha bhi exponential path mai jayega. 