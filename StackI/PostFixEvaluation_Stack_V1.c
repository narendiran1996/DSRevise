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
int Evaluate(char *myStr)
{
    int resultTemp = 0;
    struct Node *top;
    top = NULL;
    int i = 0;
    while (myStr[i] != '\0')
    {
        if (myStr[i] >= 48 && myStr[i] <= 57)
            Push(&top, (int)myStr[i] - '0');
        else
        {
            int a = Pop(&top);
            int b = Pop(&top);
            switch (myStr[i])
            {
            case '+':
                resultTemp = (a + b);
                break;
            case '-':
                resultTemp = (b - a);
                break;
            case '*':
                resultTemp = (a * b);
                break;
            case '/':
                resultTemp = (b / a);
                break;
            default:
                printf("BAD Expression\n");
                return -9999;
                break;
            }
            Push(&top, resultTemp);
        }
        i++;
    }
    return Pop(&top);
}

int main()
{
    char myStr[50];
    printf("Enter Your PostFix Expression\n");
    scanf("%s", myStr);

    printf("Evaluation of %s is %d\n", myStr, Evaluate(myStr));

    return 0;
}