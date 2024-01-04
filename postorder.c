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

void postOrder(struct node*root){
    if (root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n",root->data);
    }
}

int main(){
    //constructing new nodes using createnode function
    struct node*p = createnode(1);
    struct node*p1 = createnode(2);
    struct node*p2 =  createnode(3);
    struct node*p3 = createnode(4);
    struct node*p4 = createnode(5);
    
    //linking nodes with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    postOrder(p);
    
    return 0;
}