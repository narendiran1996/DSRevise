#include <iostream>
#include "../StackLLImp.h"
#define MAXSIZE 5

int main()
{
    StackLL<int> myStack = StackLL<int>();
    myStack.Push(2);
    std::cout << myStack << std::endl;
    myStack.Push(5);
    std::cout << myStack << std::endl;
    myStack.Push(10);
    std::cout << myStack << std::endl;
    myStack.Pop();
    std::cout << myStack << std::endl;
    myStack.Push(12);
    std::cout << myStack << std::endl;
    myStack.Push(41);
    myStack.Push(57);
    myStack.Push(62);
    std::cout << myStack << std::endl;

    StackLL<char> myStack2 = StackLL<char>();
    myStack2.Push('N');
    myStack2.Push('a');
    myStack2.Push('r');
    myStack2.Push('e');
    myStack2.Push('n');
    std::cout << myStack2 << std::endl;
    myStack2.Pop();
    myStack2.Pop();
    std::cout << myStack2 << std::endl;
    return 0;
}