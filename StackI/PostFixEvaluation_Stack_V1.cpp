// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>
#include "../StackLLImp.h"

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
    std::cout << "Enter Your PostFix Expression\n";
    std::cin >> myStr;

    std::cout<< "Evaluation of " << myStr << " is " << EvaluatePostFix(myStr) << '\n';

    return 0;
}