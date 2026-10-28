/* File Handling:- Meaning of manually and Automatic
Manually:- file bhejo>download karo> open> manupulate> normally jo nhi hum normally karte hai
Automatic:- Direct reading the file
Modifying file:
1.Sorting->I/P->O/P(mannualy)
2. Direct read->write->Send. (Automatic)
 To permanently storing the file in the secondary storage. 
We know hum koi bhi task karte hai, wo kuchh he der ke liye hamare memory mai rahta hai, kyuki hamare jo bhi program 
hote hai wo Ram mai karte hai. 
Whenever the task is complete, the data will be released. The Data will not stored, permanently. So that baad mai bhi  
use kar pau. 
We can manupulate the file with help of predefined classes. 
Ofstream: is class. If we create an object of this class, we can able to craete,write etc the file,etc  in the hard disk. 
ifstream:- is class. By creating the object of this class we can able to read the file. 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    // Opening the file
    ofstream fout;  // fout is the Object, and open is the fun of this class. 
    fout.open("Zoon.txt");  // If this file is not present, then this create that file. and than open . 
    //Writing in the file
    fout<<"Hello India\n";

    // Closing the file
    fout.close(); // to realease the resources. 
}