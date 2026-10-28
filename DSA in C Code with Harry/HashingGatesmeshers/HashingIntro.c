/*
Hashing is the method for storing the restoring data form the database in  O(1) time(constant time).
This is also called the mapping technique. because we are trying to map the larger value to smaller value.
Terminology:-
Search key:- In data base we search on any key  basis. like student(roll no, registration no).
Hash Table: Hash table is a data structure which provide a methodology to store the data in proper way and this like 
an array. Indexing is same. (24,52,91,67,48,83)
Hash Function:- kmod10, kmodn, mid square, folding method etc 1st two are mostly used.
using the function 
1.kmod10 -> 24 mod 10 = 4   4 is the hash value. (0 to 9) 
2.Kmodn -> n ki value di hogi waha tak table bana lena from 0 to n. 
3.mid square -> mid value ka sqaure karlo us jagah jake ke data store kardo. 
4.folding data-> bade no ko term mai divuide karne ka baad add karke likh do like 123456 123+456 = 579

*/