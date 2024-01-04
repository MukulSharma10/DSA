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

//insertion function
void insert(struct node*root, int key){
    struct node*prev = NULL;
    //finding the place to insert the key element
    while(root!=NULL){
        prev = root;
        if(key==root->data){
            printf("\nCannot insert an already inserted element in the BST tree: %d", key);
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    //inserting the element
    struct node*new = createnode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
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

    //inserting a new data element
    insert(p,0);
    printf("%d",p->left->left->left->data);

    //trying to insert an already existing data element
    insert(p,1);
    
    return 0;
}