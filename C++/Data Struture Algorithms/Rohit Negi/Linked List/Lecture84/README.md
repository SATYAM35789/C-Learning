### Circular Linked List :-
Jaise single linked list create karte hai  waise karenge bas last eale node ko starting se point karwa denge. Singly and doubly ka implementaion khud karna hoga.

###  Detect Loop in Linked List :- 
Address are the uniqe in creating link list so we do so on the basis of linked list. 
1. Ek pointer lenge curr naam jo point karega head ke address ko
2. ek vector banayenge visited naam ka, jo Node type jo ki address ko store karega.
3. Ab jab tak curr nall nahi hota tab tak
   1. Ek fun check naam ka with two parameter visited curr, here we check that ki curr is present in visited or not. 
   2. if present then return one means loop exist. if not then
   3. visited mai curr ko daal do
   4. curr ko curr->next se bada do. 
4. Return 0 means lopp not exist

Code Implementation :- 
```
bool check(vector<Node *> &visited, Node *curr)
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == curr)
            return 1;
    }
    return 0;
}

// function to check if the linked list has a loop
bool detectLoop(Node *head)
{
    Node *curr = head;
    vector<Node *> visited;

    while (curr)
    {
        //  Node is already visited or not
        if (check(visited, curr))
            return;

        visited.push_back(curr);
        curr = curr->next;
    }

    return 0;
}
```
Solving Time Limit Exceeded / Time Complexity :-
Approch give us the time error beacuse it take n square time complete the code but we have to solve this in n time. 

### Understanding Unordered Map :-
Stored value in the key-value pair. Key may be address, int, string. Value string, bool. 
Advantages:-  Means ye humo advantaged deta hai ki hum apne index ke type bhi change kar sakte hai. 
syntex:- unordered_map <key/index , Value > mapName ; 
Use unorderedMap in place of vector to do it in O(n). 

code Implementation :-
```
bool detectLoop(Node *head)
{
    Node *curr = head;
    unordered_map<Node *, bool> visited;

    while (curr)
    {
        //  Node is already visited or not
        if (visited[curr] == 1)
            return 1;

        visited[curr] == 1;
        curr = curr->next;
    }

    return 0;
}
```
Now another probelm arises that we have do it in space ko bhi optimize karna padega ki isko space complexity ko O(1) mai karna hoga. 
Solution :- use Slow pointer and fast pointer concept
Agar slow pointer and fast pointer aapas mai mai jate hai then loop exist. 
Isko apne  aap se karo, agar ek ko 1 ke speed aur dusre ko 3 ke speed se bhagayenge to, kya ye tab bhi kaam karega. 
1. do pointer lo slow and fast initially ye dono head ko point karenge. 
2. jab tak fast aur fast->next exist karta tab tak 
   1. Slow ko slow->next se bada do
   2. fast ko fast->next->next se bada do. 
   3. Agar slow fast ke barabar ho jata means loop exist karta hai. 


### Find the length of the loop:- 
1. Use slow and fast pointer to detect the loop, if find then break the loop. 
2. Agar fast ya fast->next null ho jata hai, then return 0, means no loop. 
3. ek variable initailize karo count=0, slow ko fast->next se bada do tab tak
     jab tak slow and faster barabar na ho jaye.
     1. count ko bada do
     2.slowko ko slow->next karte jao.

Return count ye number bata dega. 

Code Implementation :-
```

```

### Detect and remove Loop
Sahi loop ka hatana padega. 

