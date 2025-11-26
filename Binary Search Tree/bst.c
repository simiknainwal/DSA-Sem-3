#include<stdio.h>
#include<stdlib.h>

struct tree_type{
    int info;
    struct tree_type* left;
    struct tree_type* right;
};

void insert(struct tree_type**temp,int val){
    if(*temp==NULL){
        *temp=(struct tree_type*)malloc(sizeof(struct tree_type));
        (*temp)->info=val;
        (*temp)->left=(*temp)->right=NULL;
        return;
    }else if(val<(*temp)->info){
        insert(&((*temp)->left),val);
    }else{
        insert(&((*temp)->right),val);
    }
}

int max(int a,int b){
    if(a<b)return b;
    return a;
}

int height(struct tree_type*root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}

int count(struct tree_type*root){
    if(root==NULL){
        return 0;
    }
    return 1+count(root->left) + count(root->right);
}

int both(struct tree_type*root){
    if(root==NULL){
        return 0;
    }int count=0;
    if(root->left && root->right){
        count=1;
    }
    return count + both(root->left) + both(root->right);
}

int high_info(struct tree_type*root){
    if(root==NULL){
        return INT_MIN;
    }
    // int maxx=root->info;
    return max(root->info,max(high_info(root->left),high_info(root->right)));
}

int leaf(struct tree_type*root){
    if(root==NULL){
        return 0;
    }
    int count=0;
    if(root->left==NULL && root->right==NULL){
        count=1;
    }
    return count + leaf(root->left) + leaf(root->right);
}

int countLeft(struct tree_type *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    if (root->left != NULL)
    {
        count += 1; 
    }
    // return count + countLeft(root->left) + countLeft(root->right);
    return count + countLeft(root->left) + countLeft(root->right);
}

int countRight(struct tree_type *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    if (root->right != NULL)
    {
        count += 1; 
    }
    // return count + countLeft(root->left) + countLeft(root->right);
    return count + countRight(root->left) + countRight(root->right);
}

int searchBST(struct tree_type* root,int key){
    if(root==NULL){
        return 0;
    }
    if(key==root->info){
        return 1;
    }else if(key<root->info){
        return searchBST(root->left,key);
    }else{
        return searchBST(root->right,key);
    }
}

int countPairsRec(struct tree_type*root1, struct tree_type*root2,int key){
    if(root1==NULL){
        return 0;
    }
    int count=0;
    int needed=key-root1->info;

    if(searchBST(root2,needed)){
        count+=1;
    }

    return count + countPairsRec(root1->left,root2,key) + countPairsRec(root1->right,root2,key);

}

int countPairs(struct tree_type*root1,struct tree_type*root2,int key){
    return countPairsRec(root1,root2,key);
}

void inorder(struct tree_type*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->info);
    inorder(root->right);
}

int main(){
    struct tree_type* root = NULL;
    struct tree_type* root2 = NULL;

    insert(&root,50);
    insert(&root,40);
    insert(&root,60);
    insert(&root,30);
    insert(&root,45);
    insert(&root,70);

    insert(&root2,50);
    insert(&root2,75);
    insert(&root2,25);
    insert(&root2,55);
    insert(&root2,15);
    insert(&root2,85);

    printf("Inorder: ");
    inorder(root);

    printf("\nHeight of BST is %d", height(root));
    printf("\nMaximum info of BST is %d", high_info(root));
    printf("\nLeft nodes of BST is %d", countLeft(root));
    printf("\nRight nodes of BST is %d", countRight(root));

    printf("\nEnter an element to be searched: ");
    int key;
    scanf("%d", &key);

    printf("Found? %d", searchBST(root, key));

    int sumKey;
    printf("\nEnter sum key to count pairs: ");
    scanf("%d", &sumKey);

    printf("\nTotal pairs having sum %d are %d\n",
           sumKey, countPairs(root, root2, sumKey));

    return 0;
}
