// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100

// Global Variables
int StackMem[MAXSIZE];
int top = -1;

void Push(int el)
{
    if (top == (MAXSIZE - 1))
    {
        printf("\n****ERROR****\n-----------OVERFLOW-----------\n");
        return;
    }

    top++;
    StackMem[top] = el;
}

int Pop()
{
    if (top == -1)
    {
        printf("\n****ERROR****\n-----------UNDERFLOW-----------\n");
        return -9999;
    }

    top--;
    return StackMem[top];
}
int Top()
{
    return StackMem[top];
}

void PrintStack()
{
    int i;
    for (i = 0; i <= top; i++)
    {
        printf("%d\t", StackMem[i]);
    }
    printf("\n");
}

int main()
{
    Push(2);
    PrintStack();
    Push(5);
    PrintStack();
    Push(10);
    PrintStack();
    Pop();
    PrintStack();
    Push(12);
    PrintStack();

    return 0;
}