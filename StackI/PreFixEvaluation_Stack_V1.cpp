// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>
#include "../StackLLImp.h"
#include <string.h>
int EvaluatePostFix(char *myStr)
{
    int resultTemp = 0;
    StackLL<int> myStack = StackLL<int>();
    int i = strlen(myStr) - 1;
    while (i != -1)
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
                resultTemp = (a - b);
                break;
            case '*':
                resultTemp = (a * b);
                break;
            case '/':
                resultTemp = (a / b);
                break;
            default:
                std::cout << "BAD Expression\n";
                return -9999;
                break;
            }
            myStack.Push(resultTemp);
        }
        i--;
    }
    return myStack.Pop();
}

int main()
{
    char myStr[50];
    std::cout << "Enter Your Prefix Expression\n";
    std::cin >> myStr;

    std::cout << "Evaluation of " << myStr << " is " << EvaluatePostFix(myStr) << '\n';

    return 0;
}