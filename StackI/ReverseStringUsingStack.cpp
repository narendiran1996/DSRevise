// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>
#include "../StackLLImp.h"

void ReverseString(char *myStr)
{
    StackLL<char> myStack = StackLL<char>();
    int i = 0;
    while (myStr[i] != '\0')
    {
        myStack.Push(myStr[i++]);
    }

    i = 0;
    while (!myStack.isEmpty())
    {
        myStr[i++] = myStack.Pop();
    }
}

int main()
{
    char myStr[50];
    std::cout << "Enter a String \n";
    std::cin >> myStr;

    ReverseString(myStr);

    std::cout << "Reversed String is " << myStr << '\n';

    return 0;
}