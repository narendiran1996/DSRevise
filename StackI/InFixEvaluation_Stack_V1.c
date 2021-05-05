// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
};
struct NodeI
{
    int data;
    struct NodeI *next;
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

void PushI(struct NodeI **topPtr, int el)
{
    struct NodeI *temp = (struct NodeI *)malloc(sizeof(struct NodeI));

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
    char retVal = ptr->data;

    *topPtr = ptr->next;
    free(ptr);

    return retVal;
}
int PopI(struct NodeI **topPtr)
{
    if (*topPtr == NULL)
    {
        printf("\n****ERROR****\n-----------UNDERFLOW-----------\n");
        return '\0';
    }
    struct NodeI *ptr = *topPtr;
    int retVal = ptr->data;

    *topPtr = ptr->next;
    free(ptr);

    return retVal;
}
char Top(struct Node **topPtr)
{
    return (*topPtr)->data;
}
int TopI(struct NodeI **topPtr)
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
int isEmptyI(struct NodeI **topPtr)
{
    if (*topPtr == NULL)
        return 1;
    else
        return 0;
}

int isOperator(int s)
{
    switch (s)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 1;
    case '/':
        return 1;
    default:
        return 0;
    }
}

int getOperatorPrecedence(char s)
{
    switch (s)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '(':
        return 3;
    default:
        return 0;
    }
}

int isHigherPrecedence(char s1, char s2)
{
    return getOperatorPrecedence(s1) > getOperatorPrecedence(s2);
}

void InfixToPostfix(char *myStr, char *resultExp)
{
    int i = 0;
    int j = 0;

    struct Node *top;
    top = NULL;

    while (myStr[i] != '\0')
    {
        // printf("cur val is %c\n", myStr[i]);
        if (myStr[i] >= 48 && myStr[i] <= 57)
        {
            resultExp[j] = myStr[i];
            j++;
        }
        else if (isOperator(myStr[i]))
        {
            // printf("Operator is %c\n", myStr[i]);
            while (!isEmpty(&top) && isHigherPrecedence(Top(&top), myStr[i]) && Top(&top) != '(')
            {
                // printf("Top is %c\n", Top(&top));
                resultExp[j] = Top(&top);
                Pop(&top);
                j++;
            }
            Push(&top, myStr[i]);
        }
        else if (myStr[i] == '(')
        {
            Push(&top, myStr[i]);
        }
        else if (myStr[i] == ')')
        {
            while (!isEmpty(&top) && Top(&top) != '(')
            {
                // printf("Top is %c\n", Top(&top));
                resultExp[j] = Top(&top);
                Pop(&top);
                j++;
            }
            // extra pop for (
            Pop(&top);
        }

        i++;
    }
    while (!isEmpty(&top))
    {
        resultExp[j] = Top(&top);
        Pop(&top);
        j++;
    }

    resultExp[j] = '\0';
}

int EvaluatePostFix(char *myStr)
{
    int resultTemp = 0;
    struct NodeI *top;
    top = NULL;
    int i = 0;
    while (myStr[i] != '\0')
    {
        if (myStr[i] >= 48 && myStr[i] <= 57)
            PushI(&top, (int)myStr[i] - '0');
        else
        {
            int a = PopI(&top);
            int b = PopI(&top);
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
            PushI(&top, resultTemp);
        }
        i++;
    }
    return PopI(&top);
}

int main()
{
    char myStr[50];
    char PostFixExp[50];
    printf("Enter Your Infix Expression\n");
    scanf("%s", myStr);
    InfixToPostfix(myStr, PostFixExp);
    printf("The PostFix Evaluation is %s\n", PostFixExp);

    printf("Evaluation of %s is %d\n", myStr, EvaluatePostFix(PostFixExp));

    return 0;
}