/* RTTI( Run Time Type Information) is a mechanism that exposs information about an object's datatype at runtime 
and is available only for the classes which have atleast one virtual function. It allows the type of an object 
to be determined during program excution. 

There are three main c++ language elements to run-time type information:
1. The dynamic_cast types:
   used for conversion of polymorphic types
2. The typeid opertor
   Used for identifying the exact type of an object. 
   In language that supports RTTI, each object is associatedwith unique typeid that identify its type at run type. 
   The type id is usally generated with help of compiler and stored in objects main data along with objects other 
   information such as size and layout.

3. The type_info class
   Used to hold the type information returned by the typeid operator

#2 Runtime cast
batata hai cast is valid or not. 
THe runtime cast, which checks that the cast is valid, is the simplest approach to ascertain the runtime type of an
object using a pointer or reference. this is especially beneficial when we need to cast a pointer from a base class,
to a derived type. When dealing with the inheritance hierachy of classes, the casting of an object is usally required.
There are two type of casting :-
UpCasting:- When a pointer or reference of a derived class object is treated as a base class pointer. 
DownCasting:- When a base class pointeror reference is converted to a derived class pointer. 

*/