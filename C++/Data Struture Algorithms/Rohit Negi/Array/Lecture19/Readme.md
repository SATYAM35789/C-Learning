### Sorting :-  Arranging in the order (ascending and descending)

Understanding the Sorting :- 
Example : School ke assembly students ko ek proper order mai lagaate hai taaki sabhi bacho ko assembly dikh paaye. 
Example :-  Dictionary : Jisme Saare letters ek order mai hota hai. Order mai rahne se dictionary mai  words ko dhundhna asaan ho jata hai.  

Selection sort :- sabse chhota dekho , phir usko current postion se swap kardo. 
Selection sort mai, kuchh round chalenge, har round bache hue element mai se sabse chhota element mil jayega. jisme mai left element mai se sabse chhota element ko khojenge aur usko swap karenge jo bhi current postition par hoga. And so round chalega n-1 time , where n is the no. of element. 

Code part :- 
Basic Logic :- 
- index naam ka variable lenge jisme current index ka position hoga, so pahle 0 index ko index variable point kar raha hoga, 
- ek for loop chalenge 0 index ko chodkar uske baad mai jo bhi chhota mil rhah hai arr of index se usko swap kar denge arr of i se jaha chhota mila hai. 

Note sabse pahle jo hamara sabse pahla element hai usko, maan lete hai ki sabse chhota hai, aur sabhi bache hue element se compaire karte hai, agar jisko chhota maane hai us se chhota mil jata hai tab usko swap kar dete hai. 

Space Complexity :- 
Auxillary Space :- O(1)
Total space :- O(1)+ O(n)= O(n)

Time Complexity :- 
O(n^2)

Loop kahi break mahi ho raha hai, so toh ye algorithum pura chalega he chahe best case ho ya avereage case. 

Code Implementation :-
```cpp
int main()
{
    int arr[] = {23,43,22,5,45,66};

    for(int i=0;i<5;i++)  // No. of round
    {
        int index =i; 
        for(int j=i+1; j<6;j++)
        {
            if(arr[j]<arr[index])
            index =j;
        }
        swap(arr[i], arr[index]);
    }

    // Print the element to verify the answer
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
}
```

User se input lena chahte hai array mai, then performing the selection sort. 
```cpp
int main()
{
    int arr[1000];
    int n; 
    cout<<" Enter the size of an array ";
    cin>>n;

    cout<<"Enter the element in the array" ;
    //  Taking input from the user
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n-1;i++)  // No. of round
    {
        int index =i; 
        for(int j=i+1; j<n;j++)
        {
            if(arr[j]<arr[index])
            index =j;
        }
        swap(arr[i], arr[index]);
    }

    // Print the element to verify the answer
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
```