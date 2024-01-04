#include <stdio.h>
#include <malloc.h>

//creating the base node structure which other pointers will point to
struct node{
    int data;
    struct node*left;
    struct node*right;
};

//creating node creation function
struct node*createnode(int data){
    struct node*n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

//searching function
struct node*search(struct node*root, int key){
   if(root==NULL){
    return NULL;
   }
   if(key==root->data){
    return root;
   }
   else if(key<root->data){
    return search(root->left,key);
   }
   else{
    return search(root->right,key);
   }
}

int main(){
    //constructing new nodes using createnode function
    struct node*p = createnode(5);
    struct node*p1 = createnode(3);
    struct node*p2 =  createnode(7);
    struct node*p3 = createnode(1);
    struct node*p4 = createnode(4);
    struct node*p5 = createnode(6);
    struct node*p6 = createnode(9);
    
    //linking nodes with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    //searching a key in the BST
    struct node*n = search(p,0);
    if(n!=NULL){
        printf("Found: %d",n->data);
    }
    else{
        printf("Element not found!");
    }

    return 0;
}