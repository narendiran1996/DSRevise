// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>

struct NodeQ
{
    int data;
    struct NodeQ *next;
};

int isEmpty(struct NodeQ **frontPtr, struct NodeQ **rearPtr)
{
    return (*frontPtr == NULL && *rearPtr == NULL);
}

void EnQueue(struct NodeQ **frontPtr, struct NodeQ **rearPtr, int el)
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

int DeQueue(struct NodeQ **frontPtr, struct NodeQ **rearPtr)
{
    struct NodeQ *temp;
    temp = *frontPtr;
    int retEl = -999;
    if (isEmpty(frontPtr, rearPtr))
    {
        printf("QUEUE is EMPTY\n");
        return retEl;
    }
    else if (*frontPtr == *rearPtr) // just one element, make front and rear -1 for empty
    {
        retEl = (*frontPtr)->data;
        *rearPtr = NULL;
        *frontPtr = NULL;
        free(temp);
        return retEl;
    }
    else
    {
        retEl = (*frontPtr)->data;
        *frontPtr = (*frontPtr)->next;
        free(temp);
        return retEl;
    }
}

int main()
{
    struct NodeQ *front = NULL;
    struct NodeQ *rear = NULL;

    EnQueue(&front, &rear, 2);
    EnQueue(&front, &rear, 5);
    EnQueue(&front, &rear, 7);
    EnQueue(&front, &rear, 3);
    EnQueue(&front, &rear, 1);
    EnQueue(&front, &rear, 9);
    EnQueue(&front, &rear, 10);
    EnQueue(&front, &rear, 4);
    EnQueue(&front, &rear, 6);
    EnQueue(&front, &rear, 21);
    EnQueue(&front, &rear, 37);
    int i;
    for (i = 0; i < 15; i++)
    {
        printf("%d\t", DeQueue(&front, &rear));
    }
    printf("\n");

    EnQueue(&front, &rear, 2);
    EnQueue(&front, &rear, 5);
    EnQueue(&front, &rear, 7);
    EnQueue(&front, &rear, 3);
    EnQueue(&front, &rear, 1);
    EnQueue(&front, &rear, 9);
    EnQueue(&front, &rear, 10);
    for (i = 0; i < 15; i++)
    {
        printf("%d\t", DeQueue(&front, &rear));
    }
    printf("\n");

    return 0;
}