// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};

void Push(struct Node **topPtr, int el)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = el;
    temp->next = NULL;

    if (*topPtr == NULL)
    {
        *topPtr = temp;
    }
    else
    {
        temp->next = *topPtr;
        *topPtr = temp;
    }
}

int Pop(struct Node **topPtr)
{
    if (*topPtr == NULL)
    {
        printf("\n****ERROR****\n-----------UNDERFLOW-----------\n");
        return -9999;
    }
    struct Node *ptr = *topPtr;
    int retVal = ptr->data;

    *topPtr = ptr->next;
    free(ptr);

    return retVal;
}
int Top(struct Node **topPtr)
{
    return (*topPtr)->data;
}

int main()
{
    struct Node *top;
    top = NULL;

    Push(&top, 2);
    PrintStack(&top);
    Push(&top, 5);
    PrintStack(&top);
    Push(&top, 10);
    PrintStack(&top);
    Pop(&top);
    PrintStack(&top);
    Push(&top, 12);
    PrintStack(&top);

    return 0;
}