/* ***** Binary Tree *****
->Recursion is important
->Root is always the first node.
->Data is stored in the node.
->Binary tree has at max two children node.(can be 0,1,2)
->Leaf nodes are at the end of the binary tree.
->Level starts from root node(i.e. 1) and then it goes down.

->Height(from root node) is the total levels of the tree 
->If defined in edges, a tree with just the root has height = 0.
->If defined in nodes, a tree with just the root has height = 1.

->Tree consists of left and right sub tree. 
->Every parent node should have the address of left child and right child.

->Pre-order sequence=> Root,Left,Right
->While constructing the tree first we will select the root node then we will complete the left subtree and then right subtree
*/
#include<stdio.h>
#include<stdlib.h>
// struct Node{
//     int data;
//     struct Node*next;
// };
struct node{
    int data;
    struct node*left,*right;
};

struct node* createNode(int val){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->left=newNode->right=NULL;
    return newNode;
}

// void insert(struct node**head,int val){
//     if(*head==NULL){
//         *head=createNode(val);
//         return;
//     }
//     struct node* newNode=createNode(val);
//     newNode->next=
// }

void preorder(struct node* root){
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
    inorder(root->left);
    inorder(root->right);
    printf("%d ",root->data);
}

void main(){
    struct node*root=createNode(10);
    root->left=createNode(20);
    root->right=createNode(30);
    root->left->left=createNode(40);
    root->right->right=createNode(50);
    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPost-order Traversal: ");
    postorder(root);

}
