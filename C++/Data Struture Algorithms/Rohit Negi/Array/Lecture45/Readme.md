### Pointers
So hamko agar kisi jagah jana hai, Agar hamko uska address pata hai then ham usko asani se aur jaldi ja sakte hai, hamko baar baar puchne ki zarurat nahi padegi. 
-> int a =10; : a ek variable hai int type ka ja store karwa raha hai 10 ko. 
So ye RAM mai kahi store hoga, so ham kaise print opertion kar rahe honge? Hamko kaise pata chalga ki hamara address yahi hai? means (a) hai, wo kaha present hai.  So hamra address lega aur directly waha pahuch jayega. So hamko kaise pata chal raha hai ki hamara memory kis address par present hai? 
-> Symbol table ke help se pata chalta hai, jisme basic detatils store ho rahi hongi. Is table mai variable name and iske corresponding iska address bhi stored hai. 

Deallocating the memory :- 
-> Ab hamko a ko remove karna hai kyuki iski value ko ham b mai store karwa chuke hai, ye janane ke liye hamko konsi memory ko deallocate karna then also need the address. Ki usi particular variable ko remove kare jo ham karna chahte hai. 

conclusion :- So if we have the address of the  variable then only we can access it easily and perform different opation on the variable.

Visualization of the memory :-
Lets say that we are having the 4GB memory and every block is equal to the 1 byte. So there is 2^32 byte. So this is called the byte addressable ki har ek byte ko ek address de dijiye. So hamko 2^32 address dene padenge. Ham Computer address kaise dete hai, So hamare address dena ka size fixed hota hai irrespective of the real life. 
- So 8 byte ka address hota, toh 3 bit mai kaam ho ja raha hai(size) i.e (_ _ _) So hamko kaise pata chala ki 3bit ya 3 space tak he need hai so 8 = 2^3 -> 3 is the size. 
- 2^32 karne ke liye size needed is 32 bit. 
So jo address hoga memory ka wo 32 bit ka hoga and binary form mai hoga. 32 bit if the memory size is 4GB. 
We are listened about 32bit OS, 64bit OS, eo yahi hota hai. 
Note : We need a template of addressing size so ki hamko read karna and samjhna easy ho.
-> Hamne sab like IP address, int, char, etc sab ko hamne 2 ke power mai he liya hai. So ki memory management ho paaye.

While creating a variable it not only ki a variable is created there address allocation will be also done. And we stored that address on symbol table then ham koi operation perform kar pa rahe hote hai. 
So hamko pata hai ki int type variable 4 byte leta hai, to stored the the data like 10 we need the 4 countinous block as one block = 1 byte. And the address will be the start block. Stored in the binary form in 32 bits. 

How to find the address of the variable?
Syntex : addressSymbolVariableName 
Ex int a=10;  address: cout<<&a;

Storing the address:- 
So for that we need the pointerVariable which store the address.
syntex: datatype pointerSymbolVariable = addressOfVariable
datatype : ki kis type ki data ko indicate kar raha hai

ex int *ptr = &a;
Reading : ptr ek pointer hai jo point kar raha hai ek datatype ki value ko. 

Coding Implementation :-
```cpp
int main()
{
    int a=10;

    // Printing the address of a 
    cout<<&a;

    int *ptr = &a;
    cout<<ptr<<endl;

    float m=2.6;
    float *ptr1 = &m;
    cout<<ptr1<<endl;
    
}
```
- so address kisi bhi form print karwa raha hai, ye actuallu mai binary form mai he stored hota hai. Another form mai because yehi uska syntex hai. 

- Why need to mention the dataType and what is the size of the pointer?
It depends on the size of the Ram we have, if the system we using is 4gb then pointer use always 4 bytes irrespective of the datatype like char, int,float,etc
If 4g se jayda RAM then pointer is of the 8 byte.
Then we know the size of pointer then why need to mention the datatype of the pointer? If we not mention the type then it may generate the problem like, so jab ham apne address block ke first wale block par pahchte then hamko pata hona chahiye ki hamko kitna block read karna hai. So hamko kitna block read karna hai iska pata chalta hai uske type se.

How to access the value, jiska hamara pointer point kar raha hai?
means  hamko pata hai ki pointer ke ander address stored hai, so hamko us address par jo value usko directly pointer ke help se access or print karwana chahte hai. 
- For this we use de-reference operator 
  cout<<*ptr;
  Reading: so ptr jisko point kar raha hai us address par jao and us address uske ander or waha jo bhi stored usko wapas kardo. 

- If pointer ke ander kuchh nahi daalte hai then by default uske ander NULL value stored hoti hai. 
  we can use the pointer variable as :- 
  int *p;
  int b=20;
  p=&b; // Yaha pointer lagane ki zarurat nahi hai

  

