#include <iostream>
using namespace std;

int main()
{
    //  Intializing the string
    // string s = "Rohit";
    // cout << s;

    //  Taking String from the user
    // string s1;
    // cin >> s1;
    // cout << s1;

    // // Print the space also
    // string s;
    // getline(cin, s);
    // cout<<s;
    // cout<<endl;
    // s.size(); //  size of s

    // //  Append Operation
    // //  1st Method
    // string s1 = "Rohit", s2 = "mohit";
    // string s3 = s1+s2;
    // cout<<s3;

    // //  2nd Method
    // string s3 = s1.append(s2) ;

    // s1.push_back('p');

    // s2.pop_back();

    // // Another method jisse pichh koi character attach kar sakte hai
    // s1 = s1 + 'p';
    // // s1 = s1 + 'pa' // is tarah nahi j=kar sakte kyuki pa ek string hai character nahi
    // s1 = s1+ "pa";

    // Ecsape Character
    //  Example : "Satyam is "Happy" person "

    string s = " Satyam is \"Happy\" person ";
    cout << s;

    // Printing the Null character
    string s = "\\0"; // HomeWork
    cout << s;
}