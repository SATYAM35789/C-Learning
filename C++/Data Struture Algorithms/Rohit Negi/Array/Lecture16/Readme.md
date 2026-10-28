## Introduction to Array :- 
Advantages of using the array, naam hamko bar bar n dena pade ex, defining variable for calculating normal addition oprtaion for 1,2,3,4,5,..,n. So the disadvantage of using these method for calculating we need to name every variable means initilalize and the we can perform the operation.  For example for the 1000 vaivale calulation a0, a1, a2, a3, ... a999. Simplify to the 
 for( i=0; i<1000; i++)
  cin>>ai -> cin>>a[i]. 

### Declaration of an array :- 
Declaration means jab ham kisi varaible ko use kar rahe hote hai toh us se pahle ham kahi usko define kiye hote hai ki wo variable kis type ka hai aur means wo kya store karega. Waise he array ko bhi use kar rahe hai toh koi usko definr kiye honge wo kisi type ka hai , konsi value store kar raha hai, kitne size ka hai etc. 

Definition :-  It store the same type of data types , and it store at contigous memory location. By same tupe of data it is because jab ham define kar rahe hote hai tab hamko size batana hota hai nahi toh syntex array aa jata hai. so jab ham size batate aur variable ka type, in dono ke basis par hamko memory allocate hoti hai. 

   Declararion :  int a[1000] ; 
   int : data type 
   a : array name 
   [1000] : size of an array. 

   How to read this :- 
   a ek array hai, jiska size 1000 hai aur wo int type ka data apne ander stor karega. 

Inerting value in the array :- 
  1. int a[5] = {4,5,3,5,6}

  Why indexing is starting from the 0 only ? 
  if the size is 5 then indexing is 0-4 . 
  Initializing means inserting it in the storage system like array, variable, etc. 

  2. int name[] = {3,6,8,6,4,4,8}
   name ek array hai aur ye int type ka varible store karega, hamne ishka size tph bataya he nahi. lakin uske ander kuchh value daal diye jo wo carray karega. so is tarah define or declare kar sakte hai. 


3. User se puchh rahe hai ki usko kitni value daalna array mai , aur uske according array mai value daal dete hai. 
  int arr[10];
  for(int i=0; i<10;i++)
     cin>>arr[i];
    
        OR
  int n ; 
  cin>> n ;  
  int arr[n];
  for(int i=0; i<n;i++)
     cin>>arr[i];

4. int a[5] = {8,6}
Yaha hamare pass, a naam ke array hai jiska size 5 hai jo int type ka data ko store karega, lakin ham yaha pure array ke size itna value ko nahi daal rahe hai. 


5. int arr[5] = {0}; 
   arr naam ke array, jiska size 5 hai jo int type ka value ko store karega uske pure array ke blocks ko 0 se initilize kardo.  Array ko single value se initialize kar rahe hai then it is only valid for the  0 only , other value ke liye not valid hai. 
   

Kisi bhi array ki value ko kaise print karwana hai? 
 int arr[5] = {23,45,6,67,788} ; 
 for(int i=0; i<n;i++)
   cout<<arr[i];

Contigous memory allocation :-  Addressing 
to access the memory (value), and this value may present in multiple times in the memory. so identify the value which we want to update we must have the address of it. 
-> address help in accessing the value faster 

This type addressing is called the byte addressable(addressing).
 1 bit = 1 transisters
 8 bit = 1 byte
 2^10 byte = 1 kb

 Byte addressable :-  Har ek byte ko ek unique  address milega. 

 Why not bit addressable ? 
 As bit is a smallest unit , and in general we need to store any value we need more no of bits so byte is collection of the bits which singlly capable to store the specific value. Real world scenario :- We give the address of the house not the address of the room or kitchen of our home , so using bit meaning less. or it can  be used to uniquely identifying the value. 

It is not necessary ki ye 1 byte addressable he rahe kahi kahi 2 byte addressable bhi hote hai, means ki do byte ko jod ke uniqely identify karega. 

addressing jump of 4 while storing the value then it means the data type is uses will take 32 bits to store the pariticilar type. 

Why used 0 based indexing ? 
1. Finding the any address of the element in an array?
   address of index = arr + indexno*sizeofDataType. arr = address of the arr or starting address of the address. 
   
   Zero based indexing  :- 500 + 2*4 = 508
   One based indexing  :- 500 + (3-2)*4 = 508

   So one based indexing mai no of opertions bad ja rahe hai , And computer wants ki kam no. of resources mai kaam ho jaye . 

   Note :-  You can have the different array of type int, char, float, etc so you you should know the no. of byte assign to the datatype by the compiler.  

We have the 32-bit and 64-bit processor. And 4GB Ram and 8GB/16GB/32GB/2GB/4GB,etc are used repectively.

-> 32-bit processor =  used 4Gb max -> 2^32 byte Ram. Hence we send the 32 bit address to perform a particular instruction. (2^32) 
-> 4 Byte = 2^2Byte. Hence required the 2 bit store the info. 

Where as in the the 8 byte  processor
-> 8 byte = 2^3 . Hence need the 3 bit to store the specific address. 

 
