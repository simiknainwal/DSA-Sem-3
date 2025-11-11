#include <stdio.h>
#include <stdlib.h>

struct tree_type
{
    int info;
    struct tree_type *left;
    struct tree_type *right;
};

void insert(struct tree_type **ar, int val)
{
    if ((*ar) == NULL)
    {
        *ar = (struct tree_type *)malloc(sizeof(struct tree_type));
        if ((*ar) != NULL)
        {
            (*ar)->info = val;
            (*ar)->left = (*ar)->right = NULL;
        }
        return;
    }
    else if (val < (*ar)->info)
    {
        insert(&(*ar)->left, val);
    }
    else
    {
        insert(&(*ar)->right, val);
    }
}

int countNodes(struct tree_type *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaf(struct tree_type *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeaf(root->left) + countLeaf(root->right);
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
        count = 1;
    }
    return count + countLeft(root->left) + countLeft(root->right);
}

void main()
{
    struct tree_type *root = NULL;

    int x;
    printf("Binary Search Tree MENU\n\n");
    printf("Enter 1 to insert a node:\n");
    printf("Enter 2 to count number of nodes:\n");
    printf("Enter 3 to count number of leaf nodes:\n");
    printf("Enter 4 to count number of nodes which are left children of their parent:\n");
    printf("Enter 5 to exit:\n");
    int val;
    do
    {
        printf("Enter your choice:\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter the value:");
            scanf("%d", &val);
            insert(&root, val);
            break;
        case 2:
            printf("Total number of nodes are %d\n", countNodes(root));
            break;
        case 3:
            printf("Total leaf nodes are %d\n", countLeaf(root));
            break;
        case 4:
            printf("Total left nodes are %d\n", countLeft(root));
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid input");
        }
    } while (x != 5);
}