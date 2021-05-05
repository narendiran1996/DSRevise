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

struct NodeBST *FindMin(struct NodeBST **node)
{
    if (*node == NULL) // no root
        return NULL;
    else if ((*node)->leftC == NULL)
        return *node;
    else
        return FindMin(&((*node)->leftC));
}
struct NodeBST *FindMax(struct NodeBST **node)
{
    if (*node == NULL) // no root
        return NULL;
    else if ((*node)->rightC == NULL)
        return *node;
    else
        return FindMax(&((*node)->rightC));
}

void DeleteBST(struct NodeBST **rootPtr, int dataToDelete)
{
    if (*rootPtr == NULL)
    {
        printf("NULLed\n");
        return;
    }

    struct NodeBST *ptr1, *ptr2;
    ptr1 = ptr2 = *rootPtr;

    // Finding the node and it's parent
    while (1)
    {
        if (ptr1->data == dataToDelete)
        {
            break;
        }
        else if (dataToDelete < ptr1->data)
        {
            if (ptr1->leftC != NULL)
            {
                ptr2 = ptr1;
                ptr1 = ptr1->leftC;
            }
            else
            {
                printf("Item Not Found \n");
                return;
            }
        }
        else if (dataToDelete > ptr1->data)
        {
            if (ptr1->rightC != NULL)
            {
                ptr2 = ptr1;
                ptr1 = ptr1->rightC;
            }
            else
            {
                printf("Item Not Found \n");
                return;
            }
        }
    }

    // printf("Parent is %d and current is %d \n", ptr2->data, ptr1->data);
    if (ptr1->leftC == NULL && ptr1->rightC == NULL) // no Child
    {

        if (ptr1 == ptr2) // root
        {
            *rootPtr = NULL;
        }
        else
        {
            if (ptr2->leftC == ptr1)
                ptr2->leftC = NULL;
            else
                ptr2->rightC = NULL;
        }
        free(ptr1);
    }
    else if (ptr1->leftC != NULL && ptr1->rightC == NULL) // only left child
    {
        if (ptr1 == ptr2) // root
        {
            *rootPtr = ptr1->leftC;
        }
        else
        {
            if (ptr2->leftC == ptr1)
                ptr2->leftC = ptr1->leftC;
            else
                ptr2->rightC = ptr1->leftC;
        }
        free(ptr1);
    }
    else if (ptr1->rightC != NULL && ptr1->leftC == NULL) // only right child
    {
        if (ptr1 == ptr2) // root
        {
            *rootPtr = ptr1->rightC;
        }
        else
        {
            if (ptr2->leftC == ptr1)
                ptr2->leftC = ptr1->rightC;
            else
                ptr2->rightC = ptr1->rightC;
        }
        free(ptr1);
    }
    else if (ptr1->rightC != NULL && ptr1->leftC != NULL) // two child
    {
        struct NodeBST *maxValNode = FindMax(&(ptr1->rightC));
        // printf("Maximum Value is %d\n", maxValNode->data);

        int maxVal = maxValNode->data;

        DeleteBST(rootPtr, maxVal);

        ptr1->data = maxVal;
    }
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

    inOrderTraversal(&root);
    printf("\n");
    DeleteBST(&root, 12);
    inOrderTraversal(&root);
    printf("\n");
    return 0;
}
