// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>

struct Node
{
    char data;
    struct Node *next;
};

void Push(struct Node **topPtr, char el)
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

char Pop(struct Node **topPtr)
{
    if (*topPtr == NULL)
    {
        printf("\n****ERROR****\n-----------UNDERFLOW-----------\n");
        return '\0';
    }
    struct Node *ptr = *topPtr;
    int retVal = ptr->data;

    *topPtr = ptr->next;
    free(ptr);

    return retVal;
}
char Top(struct Node **topPtr)
{
    return (*topPtr)->data;
}
int isEmpty(struct Node **topPtr)
{
    if (*topPtr == NULL)
        return 1;
    else
        return 0;
}

void ReverseString(struct Node **topPtr, char *myStr)
{
    int i = 0;
    while (myStr[i] != '\0')
    {
        Push(topPtr, myStr[i++]);
    }

    i = 0;
    while (!isEmpty(topPtr))
    {
        myStr[i++] = Pop(topPtr);
    }
}

int main()
{
    struct Node *top;
    top = NULL;

    char myStr[50];
    printf("Enter a String \n");
    scanf("%s", myStr);

    ReverseString(&top, myStr);

    printf("Reversed String is %s\n", myStr);

    return 0;
}