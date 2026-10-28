### AVL Tree Deletion :- 
Kisi bhi node ko delete kar rahe toh uske baad hamko check karna padega paricular nodes ko ki wo balance hai ki nahi. 
Different cases of Deletion in the AVL :- 
1. Leaf Node  :- Isko hum direct delete kar sakte hai.  
2. Single Child :- jisko delete kar rahe hai uska left or right child dono exist kar sakte hai
   1. Left Child : Delete that Node and return its left child. 
   2. Right Child : Delete that Node and return its right child.
3. Both Child Exist :- 
  Agar is type ke nodes ko direct delete karte hai then unbalance condition aa sakta then jis node ko delete kar rahe hai usko kon replace karega? Uska left bhi kar sakta hai aur uska right bhi. So left side ka sabse bada element aur right sode ka sabse chhota element he sirf replace kar sakta kyuki tabhi hamri Tree Balance rah sakta hai. 
So we go to the right side ka sabse chhota element:-
   So hum kya karenge ki connection nahi todenge bas apne sabse chhote element ko jisko delete karana un aapas mai exchange kara denge. As resukt ab jisko delete kara hai wo child mai pahuch jayega aur hum asani se delete jar denge. 

Steps :- 
1. Right side ka minimum element find karlo
2. replace it with root(jisko delete karna hai)
3. delete kardo us node ko. 

Note :- Dekho agar Aise situation aati hai ki hamare min ka koi child exist karta hai then hum Single Node Case jaise handle kar lenge. 

Agar Actually delete karna hai node ko then hum BST mai jaise kiye the wise karna padega. 

Unbalancing ke chances Jab hum insert kar rahe the us samay jis part mai insert karte us part mai unbalance ke chance hote the lakin yaha jis part mai delete kar rahe uske opposite part mai unbalance ke chance hai.  So is se hamko pata chal jayega ki Pahle L  ki R  of different cases. or Agar left side ki balancing > 1 hai.
Dusra kya hai kaise pata chalega?
Dusra part mai jo node hai uski balance nikalenge if -1 aati hai or negative mai aati hai then R (LR :  Agar pahle L hai toh) nahi toh L (LL : Agar pahle L hai toh). Agar greter than 0 then (RL) else RR. 
1. Balance Check karo for first L and R
1. Balance Check karo for second L and R

Code Implementation :- 
```
Node *deleteNode(Node *root, int key)
{
    if (!root)
        return NULL;

    if (key < root->data) // Left Side
        root->left = deleteNode(root->left, key);

    else if (key > root->data) // Right side
        root->right = deleteNode(root->right, key);
    else
    {
        // Leaf Node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // Only One Child exist
        else if (root->left && !root->right) // When  Only left child exist
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // Both child exist
        else
        {
            // Right Side Smallest element dhoondhkar lao
            Node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }

            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data); // kyuki ham right side move ho rahe hai so root ke right mai store
        }
    }

    // Update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check the balance
    int balance = getBalance(root);

    // Left Side
    if (balance > 1)
    {
        // LL
        if (getBalance(root->left) >= 0)
            return rightRotation(root);
        // LR
        else // Jab getBlance ki vlue -ve hogi
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    // Right Side
    else if (balance < -1)
    {
        // RR
        if (getBalance(root->right) <= 0)
            return leftRotation(root->right);
        // RL
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    // No Unbalance case
    else
    {
        return root;
    }
}
```

Note :- 
 Is Code mai ham dekh pa rahe honge ki, Jab hum different path pae ja rahe tab hum return nahi karwa rahe hai,
 kyuki hamko balancing and height bhi check karni hoti hai, While deleting node In case of leaf Node and When Olny
 one child exist, When both child exist hum waha return nahi karwa rahe hai.
