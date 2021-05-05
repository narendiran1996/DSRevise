#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct NodeBST
{
    int data;
    struct NodeBST *leftC, *rightC;
};

void InsertBST(struct NodeBST **node, int el)
{
    if (*node == NULL) // root insertion
    {
        struct NodeBST *temp = (struct NodeBST *)malloc(sizeof(struct NodeBST *));
        temp->data = el;
        temp->leftC = NULL;
        temp->rightC = NULL;
        *node = temp;
    }
    else if (el <= (*node)->data)
    {
        InsertBST(&((*node)->leftC), el);
    }
    else if (el >= (*node)->data)
    {
        InsertBST(&((*node)->rightC), el);
    }
}

int SearchBST(struct NodeBST **node, int dataToSearch)
{
    // printf("SBST %d\n", (*node)->data);
    if (*node == NULL) // not found or root is empty
        return 0;
    else if (((*node)->data) == dataToSearch) // found the element
        return 1;
    else if (dataToSearch < ((*node)->data))
        return SearchBST(&((*node)->leftC), dataToSearch);
    else if (dataToSearch > ((*node)->data))
        return SearchBST(&((*node)->rightC), dataToSearch);
}

int FindMin(struct NodeBST **node)
{
    if (*node == NULL) // no root
        return -9999;
    else if ((*node)->leftC == NULL)
        return (*node)->data;
    else
        return FindMin(&((*node)->leftC));
}
int FindMax(struct NodeBST **node)
{
    if (*node == NULL) // no root
        return -9999;
    else if ((*node)->leftC == NULL)
        return (*node)->data;
    else
        return FindMax(&((*node)->rightC));
}

/* 
Height of a Node - Number of edges in longest path from the node to a leaf node
Height of tree = Height of root
Height of Leaf Node = 0
*/
int FindHeight(struct NodeBST **node)
{
    if (*node == NULL) // edge to NULL left and edge of NULL right
        return -1;

    // Height = max(Heifht_Left_SubTree, Heifht_Right_SubTree) + 1
    int leftHeight = FindHeight(&((*node)->leftC));
    int rightHeight = FindHeight(&((*node)->rightC));

    return MAX(leftHeight, rightHeight) + 1;
}

void inOrderTraversal(struct NodeBST **node)
{
    if (*node != NULL)
    {
        inOrderTraversal(&((*node)->leftC));
        printf("%d \t", (*node)->data);
        inOrderTraversal(&((*node)->rightC));
    }
}
void preOrderTraversal(struct NodeBST **node)
{
    if (*node != NULL)
    {
        preOrderTraversal(&((*node)->leftC));
        preOrderTraversal(&((*node)->rightC));
        printf("%d \t", (*node)->data);
    }
}
void postOrderTraversal(struct NodeBST **node)
{
    if (*node != NULL)
    {
        printf("%d \t", (*node)->data);
        postOrderTraversal(&((*node)->leftC));
        postOrderTraversal(&((*node)->rightC));
    }
}

// Breath - First or Level-order

int main()
{
    struct NodeBST *root = NULL;

    InsertBST(&root, 12);
    InsertBST(&root, 5);
    InsertBST(&root, 15);
    InsertBST(&root, 3);
    InsertBST(&root, 7);
    InsertBST(&root, 13);
    InsertBST(&root, 17);
    InsertBST(&root, 1);
    InsertBST(&root, 9);
    InsertBST(&root, 19);

    // if (SearchBST(&root, 17))
    //     printf("FOUND num\n");
    // else
    //     printf("NOT FOUND num\n");

    printf("The Minimum value of BST is %d\n", FindMin(&root));
    printf("The Maximum value of BST is %d\n", FindMax(&root));
    printf("The Height of BST is %d\n", FindHeight(&root));

    // Depth-first Traversal
    printf("\nIN ORDER TRAVERSAL \n");
    inOrderTraversal(&root);
    printf("\nPRE ORDER TRAVERSAL \n");
    preOrderTraversal(&root);
    printf("\nPOST ORDER TRAVERSAL \n");
    postOrderTraversal(&root);

    // Breath-first or Level-order Traversal

    return 0;
}