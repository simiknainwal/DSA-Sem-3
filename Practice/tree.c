#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left,* right;
};

struct node* createNode(int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void preorder(struct node*root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    struct node* root=NULL;
    root=createNode(10);
    root->left=createNode(20);
    root->right=createNode(30);
    root->left->left=createNode(40);
    root->right->right=createNode(50);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

}