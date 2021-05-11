// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>
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

int main()
{
    char myStr[50];
    char resultExp[50];
    std::cout << "Enter Your Infix Expression\n";
    std::cin >> myStr;
    InfixToPostfix(myStr, resultExp);
    std::cout << "The PostFix Evaluation is " << resultExp << '\n';
    return 0;
}