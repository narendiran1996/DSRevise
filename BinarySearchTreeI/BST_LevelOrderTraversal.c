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

struct NodeQ
{
    struct NodeBST *data;
    struct NodeQ *next;
};

int isEmpty(struct NodeQ **frontPtr, struct NodeQ **rearPtr)
{
    return (*frontPtr == NULL && *rearPtr == NULL);
}

void EnQueue(struct NodeQ **frontPtr, struct NodeQ **rearPtr, struct NodeBST *el)
{
    struct NodeQ *temp = (struct NodeQ *)malloc(sizeof(struct NodeQ *));
    temp->data = el;
    temp->next = NULL;

    if (isEmpty(frontPtr, rearPtr))
    {
        *rearPtr = temp;
        *frontPtr = temp;
    }
    else
    {
        (*rearPtr)->next = temp;
        *rearPtr = temp;
    }
}

struct NodeBST *DeQueue(struct NodeQ **frontPtr, struct NodeQ **rearPtr)
{
    struct NodeBST *retVal;

    struct NodeQ *temp;
    temp = *frontPtr;
    if (isEmpty(frontPtr, rearPtr))
    {
        printf("QUEUE is EMPTY\n");
        return NULL;
    }
    else if (*frontPtr == *rearPtr) // just one element, make front and rear -1 for empty
    {
        retVal = (*frontPtr)->data;
        *rearPtr = NULL;
        *frontPtr = NULL;
        free(temp);
        return retVal;
    }
    else
    {
        retVal = (*frontPtr)->data;
        *frontPtr = (*frontPtr)->next;
        free(temp);
        return retVal;
    }
}

void LevelOrder(struct NodeBST **rootPtr)
{
    if (*rootPtr == NULL)
        return;

    struct NodeQ *front = NULL;
    struct NodeQ *rear = NULL;

    EnQueue(&front, &rear, *rootPtr);

    while (!isEmpty(&front, &rear))
    {
        struct NodeBST *current = DeQueue(&front, &rear);

        printf("%d\t", current->data);

        if (current->leftC != NULL)
            EnQueue(&front, &rear, current->leftC);
        if (current->rightC != NULL)
            EnQueue(&front, &rear, current->rightC);
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


    LevelOrder(&root);

    return 0;
}


