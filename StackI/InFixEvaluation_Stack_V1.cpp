// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "../StackLLImp.h"

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

    StackLL<char> myStack = StackLL<char>();

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
            while (!myStack.isEmpty() && isHigherPrecedence(myStack.getTop(), myStr[i]) && myStack.getTop() != '(')
            {
                // printf("Top is %c\n", Top(&top));
                resultExp[j] = myStack.getTop();
                myStack.Pop();
                j++;
            }
            myStack.Push(myStr[i]);
        }
        else if (myStr[i] == '(')
        {
            myStack.Push(myStr[i]);
        }
        else if (myStr[i] == ')')
        {
            while (!myStack.isEmpty() && myStack.getTop() != '(')
            {
                // printf("Top is %c\n", Top(&top));
                resultExp[j] = myStack.getTop();
                myStack.Pop();
                j++;
            }
            // extra pop for (
            myStack.Pop();
        }

        i++;
    }
    while (!myStack.isEmpty())
    {
        resultExp[j] = myStack.getTop();
        myStack.Pop();
        j++;
    }

    resultExp[j] = '\0';
}

int EvaluatePostFix(char *myStr)
{
    int resultTemp = 0;
    StackLL<int> myStack = StackLL<int>();
    int i = 0;
    while (myStr[i] != '\0')
    {
        if (myStr[i] >= 48 && myStr[i] <= 57)
            myStack.Push((int)myStr[i] - '0');
        else
        {
            int a = myStack.Pop();
            int b = myStack.Pop();
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
            myStack.Push(resultTemp);
        }
        i++;
    }
    return myStack.Pop();
}

int main()
{
    char myStr[50];
    char PostFixExp[50];
    std::cout << "Enter Your Infix Expression\n";
    std::cin >> myStr;
    InfixToPostfix(myStr, PostFixExp);
    std::cout << "The PostFix Evaluation is " << PostFixExp << '\n';

    std::cout << "Evaluation of " << myStr << " is " << EvaluatePostFix(PostFixExp) << '\n';

    return 0;
}