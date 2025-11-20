// Create a BST and perform:
// 1) count total number of nodes.
// 2) count leaf nodes in a BST.
// 3) count nodes having both left and right child
// 4) count nodes having only left child.
// 5) count nodes havin only right child.
// 6) find height of BST.
// 7) create a mirror BST.(left is greater and right is smaller.)

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node*left;
    struct node*right;
};

void insert(struct node**ar,int val){
    if(*ar==NULL){
        *ar=(struct node*)malloc(sizeof(struct node));
        (*ar)->info=val;
        (*ar)->left=(*ar)->right=NULL;
        return;
    }else if((*ar)->info<val){
        insert(&(*ar)->right,val);
    }else{
        insert(&(*ar)->left,val);
    }
}

int countNodes(struct node*ar){
    if(ar==NULL){
        return 0;
    }
    return 1 + countNodes(ar->left) + countNodes(ar->right);
}

int countLeaf(struct node*ar){
    if(ar==NULL){
        return 0;
    }
    if(ar->left==NULL && ar->right==NULL){
        return 1;
    }
    return countLeaf(ar->left) + countLeaf(ar->right);
}

int leftNodes(struct node*root){
    if(root==NULL){
        return 0;
    }
    int count=0;
    if(root->left!=NULL){
        count=1;
    }
    return count+leftNodes(root->left)+countNodes(root->right);
}
int rightNodes(struct node*root){
    if(root==NULL){
        return 0;
    }
    int count=0;
    if(root->right!=NULL){
        count=1;
    }
    return count+leftNodes(root->left)+countNodes(root->right);
}

int both(struct node*ar){
    if(ar==NULL){
        return 0;
    }
    if(ar->left && ar->right){
        return 1;
    }
    return both(ar->left) + both(ar->right);
}
int max(int a,int b){
    if(a>b)return a;
    return b;
}
int height(struct node*root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}

void mirror(struct node**root){
    if(*root==NULL){
        return;
    }
    struct node* temp=(*root)->left;
    (*root)->left=(*root)->right;
    (*root)->right=temp;
    mirror(&(*root)->left);
    mirror(&(*root)->right);

}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->info);
    inorder(root->right);
}

void main(){
struct node* root=NULL;
printf("Enter 1 to insert a node:\n");
printf("Enter 2 to count  nodes:\n");
int val;
char ch;
do{
    // getchar();
    printf("\nEnter choice:");
    scanf("%c",&ch);
    switch(ch){
        case '1':
        printf("Enter value:");
        scanf("%d",&val);
        // getchar();
        insert(&root,val);
        break;
        case '2':printf("%d ",countNodes(root));
        break;
        case '3':printf("%d ",countLeaf(root));
        break;
        case '4':printf("%d ",both(root));
        break;
        case '5':printf("%d ",height(root));
        break;
        case '6':printf("%d ",rightNodes(root));
        break;
        case '7':printf("Mirroring...\n");
        mirror(&root);
        break;
        case '8':inorder(root);
        break;
        case 'e':printf("Exiting...");
        break;
        default:printf("Invalid choice\n");
    }
    getchar();
}while(ch!='e');
}

