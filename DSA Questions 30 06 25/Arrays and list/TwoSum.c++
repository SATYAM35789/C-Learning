//  All Power is within You, You can do Anything and Everything.
/* .Is problrm mai ek target value hoti hai , aur ek array mai kisi do value ka sum target value ke equal aana 
chahiye. so hume jo do value array ke ander milengi uski index value return karenge.
Assumption :- Exactly ek solution hoga. same element ko do baar nahi le sakte. 
Approach: 1. Brute or Basic : Adding all pairs and checj with the target. 
*/
#include <vector>
#include <unordered_map>
class Solution {

  public :
  vector <int> twoSum (vector <int> & arr, int tar)
{
    unordered_map <int, int> m;
    vector<int> ans;

    for(int i=0 ; i<arr.size(); i++)
    {
        int first = arr[i];
        int sec = tar - first;

        if(m.find(sec) != m.end()) 
        {
          ans.push_back(i);
          ans.push_back(m[sec]);
          break;
      
          
        }
        m[first] = 1;
    }
    return ans;
}

}