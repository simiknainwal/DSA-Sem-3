#include<stdio.h>
#include<stdlib.h>

struct Tree_type{
    int info;
    struct Tree_type* left;
    struct Tree_type* right;
};

void insert(struct Tree_type** ar, int val){
    if(*ar==NULL){
        *ar=(struct Tree_type*)malloc(sizeof(struct Tree_type));
        if(*ar!=NULL){
        (*ar)->left=(*ar)->right=NULL;
        (*ar)->info=val;
        return;
    }
    }else if(val<(*ar)->info){
        insert(&((*ar)->left),val);
        
    }else{
        insert(&((*ar)->right),val);
    }
}

void inorder(struct Tree_type* rt){
    if(rt==NULL){
        return;
    }
    inorder(rt->left);
    printf("%d ",rt->info);
    inorder(rt->right);
}

void preorder(struct Tree_type* rt){
    if(rt==NULL){
        return;
    }
    printf("%d ",rt->info);
    preorder(rt->left);
    preorder(rt->right);
}

void postorder(struct Tree_type* rt){
    if(rt==NULL){
        return;
    }
    postorder(rt->left);
    postorder(rt->right);
    printf("%d ",rt->info);
}

int main(){
    struct Tree_type* root=NULL;
    int num,x;

    printf("***** Binary Search Tree *****\n\n");
    printf("\nEnter 1 for inorder traversal:\n");
    printf("Enter 2 for preorder traversal:\n");
    printf("Enter 3 for postorder traversal:\n");
    printf("Enter 4 for inserting a node:\n");
    printf("Enter 5 to exit:\n");
    do{
        printf("\nEnter your choice:\n");
        scanf("%d",&x);
        switch(x){
            case 1:printf("Inorder traversal is : ");
            inorder(root);
            break;
            case 2:printf("Preorder traversal is : ");
            preorder(root);
            break;
            case 3:printf("Postorder traversal is : ");
            postorder(root);
            break;
            case 4:printf("Enter a number:");
            scanf("%d",&num);
            insert(&root,num);
            break;
            case 5:printf("Exitting..");
            break;
            default:printf("Invalid input\n");
        }
    }while(x!=5);
}