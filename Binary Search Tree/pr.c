#include<stdio.h>
#include<stdlib.h>

typedef struct tree_type{
    int info;
    struct tree_type*left;
    struct tree_type*right;
}tree_type;

void insert(tree_type**root,int val){
    if(*root==NULL){
        tree_type* temp=(tree_type*)malloc(sizeof(tree_type));
        temp->info=val;
        temp->left=temp->right=NULL;
        return;
    }else if(val<(*root)->info){
        // (*root)->left=(tree_type*)malloc(sizeof(tree_type));
        (*root)=(*root)->left;
        (*root)->info=val;
    }else{
        *root=(*root)->right;
        (*root)->info=val;
    }
}

void inorder(tree_type*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d",root->info);
    inorder(root->right);
}

int main(){
    tree_type* root=NULL;
    insert(&root,20);
    insert(&root,10);
    insert(&root,30);
    inorder(root);
}