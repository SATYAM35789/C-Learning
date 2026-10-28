#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
    
};

struct node *createNode(int data){
    struct node *n; // Creating a node pointer
    n = (struct node*)malloc(sizeof(struct node)); // allocating the memory in the heap
    n->data= data;   // setting the data 
    n->left = NULL; // setting the left children to null
    n->right = NULL; // setting the right children to null

    return n;  // Finally returning the created node
}
void Inorder(struct node *root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d\n",root->data);
        Inorder(root->right);
        
    }
}
int IsBST(struct node *root){
    static struct node *prev= NULL;
    if(root!=NULL){
        if(!IsBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data  <=prev->data){
            return 0;
        }
        prev = root;
        return IsBST(root->right);

    }
    else{
        return 1;
    }
}
struct node *searchIter(struct node *root,int key){
    while(root!=NULL){
        if(key==root->data){
            return root;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }

    }
    return NULL;       
}
    


int main(){
    // Constructing the root node  using function
    struct node *p = createNode(12);                        // Tree looks like this
    struct node *p1 = createNode(3);                            //     12
    struct node *p2 = createNode(18);                            //    / \    
    struct node *p3 = createNode(2);                           //    3   18
    struct node *p4 = createNode(4);                           //    \
    //                                                                4 
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    //p1->left = p3;
    p1->right = p4;
    
    struct node *n= searchIter(p,4);
    if(n!=NULL){
        printf("Found : %d",n->data);
    }
    else
    printf("Element not found");
    
    return 0;

}

