// InOrderTraversal :- Left-> root->Right
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

int main(){
    // Constructing the root node  using function
    struct node *p = createNode(4);                        // Tree looks like this
    struct node *p1 = createNode(1);                            //     4
    struct node *p2 = createNode(3);                            //    / \    
    struct node *p3 = createNode(12);                           //   1  3
    struct node *p4 = createNode(2);                           //   / \
    //                                                           //  12 2
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    //p1->left = p3;
    p1->right = p4;
    Inorder(p);

    return 0;

}