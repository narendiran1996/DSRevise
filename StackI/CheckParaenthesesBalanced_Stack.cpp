// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>
#include "../StackLLImp.h"

int isBalanced(char *myStr)
{
    StackLL<char> myStack = StackLL<char>();
    int i = 0;
    while (myStr[i] != '\0')
    {
        if (myStr[i] == '(' || myStr[i] == '[' || myStr[i] == '{')
            myStack.Push(myStr[i]);
        else if (!myStack.isEmpty() && !(myStack.getTop() == '(' && myStr[i] == ')') && !(myStack.getTop() == '{' && myStr[i] == '}') && !(myStack.getTop() == '[' && myStr[i] == ']'))
        {
            return 0;
        }
        else if (!myStack.isEmpty())
        {
            myStack.Pop();
        }
        i++;
    }
    if (myStack.isEmpty())
        return 1;
    else
        return 0;
}

int main()
{

    char myStr[50];
    std::cout << "Enter a String \n";
    std::cin >> myStr;

    if (isBalanced(myStr))
        std::cout << myStr << " is Balanced\n";
    else
        std::cout << myStr << " is NOT Balanced\n";

    return 0;
}