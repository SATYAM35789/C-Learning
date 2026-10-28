/*
cin<<variable;
cout<<variable;
cin and cout : Object
<<  >> : Operator ( Arrow shows the flow of the data)
variable variable : User defined variable
c++ streams:- I/O operations in c++ perform in strams , which means we have some sequence of bytes which are called streams
In input operation the input is flow from keyboard to main memory. Or in Output the  out \put is flow from the the
device display,printer.etc from main memory. 
point: cin is connected with keyboard.etc and cout is connected with main memory. 
Bytes could represent:- char, rowdata, graphices, digital speech, digital video or any other info. 

Low level IO:- the IO is unformatted, due to the unformatted IO the transfer is high speed and high vol but not 
very convinient.Work on each byte.Portable issues.  
High level IO :- the IO us formatted, this is sufficient in high volume and high processing. Work on group of byte.
meaningful inputs such as int, char, any other iser defined data types. Mostly used. 

Class vs standard streams in C++
In past in standard streams libraary in input and output of the characters.
Charcater normally occupied 1 byte : ASCII can represents this.
charcters which are more than one byte:- Unicode this are basically 16 bits characters. C++ includes standard 
streams libraies which enables devlopers to buld system capable of performing IO opertions with unicode operations. 
and for this perpose c++ includes additional charcter  types wchar_t. 

IO
*/