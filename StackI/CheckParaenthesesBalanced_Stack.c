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
void PrintStack(struct Node **topPtr)
{
    struct Node *ptr;
    // we deference headPtr to get the head
    ptr = *topPtr;
    while (ptr != NULL)
    {
        printf("%c\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isBalanced(struct Node **topPtr, char *myStr)
{
    int i = 0;
    while (myStr[i] != '\0')
    {
        if (myStr[i] == '(' || myStr[i] == '[' || myStr[i] == '{')
            Push(topPtr, myStr[i]);
        else if (!isEmpty(topPtr) && !(Top(topPtr) == '(' && myStr[i] == ')') && !(Top(topPtr) == '{' && myStr[i] == '}') && !(Top(topPtr) == '[' && myStr[i] == ']'))
        {
            return 0;
        }
        else
        {
            Pop(topPtr);
        }
        i++;
    }
    if (isEmpty(topPtr))
        return 1;
    else
        return 0;
}

int main()
{
    struct Node *top;
    top = NULL;

    char myStr[50];
    printf("Enter a String \n");
    scanf("%s", myStr);

    if (isBalanced(&top, myStr))
        printf("%s is Balanced\n", myStr);
    else
        printf("%s is NOT Balanced\n", myStr);

    return 0;
}