/* Why AVL trees? 
  1. Almost all the operations in a binary search tree are of order O(h) where h is the height of the tree.
  2.If we don't plan our tree properly, this height can get as high as  n wheere n is the number of nodes in
   a BST  (skewed tree)
  3. To guarantee an upper bound of O(logn) for all these operations, we use balanced trees. 

  What is an AVL tree?
  1. Height balanced binary search trees.
  2. Height difference between heights of left and right subtrees for every node is less than oe equal to 1.
  3. Balanced factor = Height of right subtree - Height of left subtree
  4. Can be -1 0 or 1 for a node to be balanced in a binary search tree (BF)
  5. Can be -1,0 or 1 for all nodes of an AVL tree. (BF)

If tree is not balanced than you have to balance the that tree by ROTATIONS (using this but not good for the tree)
#2  1.LL rotation in AVL tree?
      Left side (shifting of node to get balance factor) 
   
    2.RR rotation in  an AVL tree?
    Right side (shifting of node to get balance factor)

    3.LR rotation in a AVL tree?
      Ek baar left than ek baar right 
    
    4. RL rotation in a AVL tree.
    Ek baar right than ek baar left. 


    Doing the rotation because ki ek binary tree ko AVL tree bana sake. 

#3 We can perform rotate operations to balance a binary search tree such that newly formed tee satisfies all the 
   properties of a BST. Following are two basic rotate operations:
   1. Left Rotate wrt a node - Node is moved towards the left.
   2. Right Rotate wrt a node - Node is moved towards the Right. 

    Balancing a AVL tree after insertion
    In order to balance an AVL tree after insertion , we can follow the following rules:-
    1. For the left-left insertion-: Right rotate once wrt the first imbalanced node.
    2. For the right-right insertion-: left rotate once wrt the first imbalanced node.
    3. For the left-right insertion-:Left rotate and then right rotate once.
    4. For the right-left insertion-:right rotate and then left rotate once.

    Left- left Insertion:-
    Here we see the how left left insertion is done in Binary tree. 
    FIB(First Imbalanced Node)
    Child of FIB(Jo ki insertion wali path mai hai). 

*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};
int getHeight(struct Node *n){
  if(n==NULL)
     return 0;
  return n->height;
    
}

struct Node*createNode(int key){
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  // Intialize some basic 
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

int max(int a, int b){
  return a>b?a:b;

}
int getBalanceFactor(struct Node *n){
  if(n==NULL){  // return 0 because BF = height of LST- height RST =0
    return 0;
  }
  return getHeight(n->left) - getHeight(n->right);

}

struct Node *rightRotate(struct Node *y){
  struct Node *x = y->left;
  struct Node *T2 = x->left;

  x->right = y;
  y->left = T2;

  y->height = max(getHeight(y->right), getHeight(y->left)) +1;
  x->height = max(getHeight(x->right), getHeight(x->left)) +1;

  return x;
}

struct Node *leftRotate(struct Node *x){
  struct Node *y = x->left;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  y->height = max(getHeight(y->right), getHeight(y->left)) +1;
  x->height = max(getHeight(x->right), getHeight(x->left)) +1;

  return y;
}

struct Node * insert(struct Node *node, int key){
  if(node==NULL){
    return(createNode(key));
  }
  if(key<node->key){
    node->left = insert(node->left,key);
    return node;
  }
  else if(key<node->key){
    node->right = insert(node->right, key);
    return node;
  node->height = 1 + max(getHeight(node->left),getHeight(node->right));
    int bf = getBalanceFactor(node);
    // If unbalance than have 4 case
    // Left Left case
    if(bf>1 && key < node->left->key){
      return rightRotate(node);
    }
    // RightRight case
    if(bf>-1 && key > node->right->key){
      return leftRotate(node);
    }
    // Left Right case
    if(bf>1 && key > node->left->key){
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
    // Right Left case
    if(bf>-1 && key < node->right->key){
      node->right = rightRotate(node->right);
      return rightRotate(node);
    }
    
  }
  return node;
}
int main(){
  struct Node *root = NULL;
  root = insert(root,1);
  root = insert(root,2);
  root = insert(root,3);
  root = insert(root,4);
  root = insert(root,5);
  root = insert(root,6);
  return 0;
}