## Time and space Complexity :- 
Definition :- 
Time Complexity :-  Total time taken by the algorithum to run as a fn of length of the input.  

Why need the time complexity :- 
So ek question ko multiple ways or approch se solve kar sakte hai so jo best hai usme se means jo sabse kam samay lega usko use kar lenge. 

Basic structure :- Problem -> solution exist  {A1, A2, A3, A4}  (diffent algorithum to solve that problem).

So maan lo tumhare ek approch hai, uske tumne ek purane aur ek naye version computer se compute karenge toh purna wala same algorthim ko use karega , lakin ye time jayda lega kyuki iske processor , required register, resources achhe nahi in compairsion to new computer. Jaga new computer kam samay mai solve kar dega same algorithum ka use karke. 
So iske liye ham ek machine lenge jisko idle machine bolenge us par apne algo ko run karwayenge jo bhi answer hoga usko maan lenge answer. 
No of variable change karne se time mai bhi change aa raha hai. So time complexity kisi program ki depend kar rahi hai, no. of i/p par. It may be ki koi algorithum depend he na kare.

understanding to run as a fn of length of the input :- 
so iske liye ek Time vs inputSize(n) ka ek graph banayenge different i/p ke graph mai point karnege, phir in points ko connect karnge aur iske pattern or theta ki value calculate karnege.  
So jab bhi alogorthum ko compairsion kar rahe honge usko ek mathematical fn  ke term mai compairsion kar rahe honge. 

Constant terms ko remove kar denge as A1= n A2 n/2 then we can write n/2 as n. 

Different terminology used :- 
Big(O) :- Worst case
Omega :-  Best case 
Theta :- Avg Case 

Example :- 
for(int i=1 ; i<=n ; i++) 
   cout<<"Satyam";

Count the all the no of steps :- 
1st iteration mai 4 kaam :-
   1. i=1  2. i<=n 3. i++  4.cout<<"Satyam";

2nd iteration :- 
 3 kaam :- 
 1. i<=n 2. i++  3.cout<<"Satyam"; 

 and so till the n 

4+3+3+3+3+3+3....+3
1,2,3,4,5....., n 

3n + 1 = total no of steps. so isme constant terms ko ignore kardo so n so called the O(n). 

While calculating complexity :-
1. Ignore the constant terms 
2. expression mai jo sabse bada hoga wahi le lenge as to represent the worst time complexity.    
 

Different question have been practiced in these lecture , basically learning to derive and finding the complexity. 

Space Complexity :- It is the amount of space taken by an algorithum as a fn of length of i/p. 
-> Auxillary space :- i/p ka space or jo bhi question mai space use hua for storing value usko exclude kar denge
-> Total space complexity :- isme include kar lenge , complexity nikalte waqt. 