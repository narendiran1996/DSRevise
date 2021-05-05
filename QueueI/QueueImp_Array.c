#include <stdio.h>

#define MAXSIZE 10

// Global Variables
int QueueMEM[MAXSIZE];
int front = -1;
int rear = -1;

int isEmpty()
{
    return (front == -1) && (rear == -1);
}
int isFull()
{
    return (rear == MAXSIZE - 1);
}

void EnQueue(int el)
{
    if (isFull())
    {
        printf("QUEUE is FULL -- can't add %d\n", el);
        return;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        ++rear;
    }
    QueueMEM[rear] = el;
}

int DeQueue()
{
    int retEl = -999;
    if (isEmpty())
    {
        printf("QUEUE is EMPTY\n");
        return retEl;
    }
    else if (front == rear) // just one element, make front and rear -1 for empty
    {
        retEl = QueueMEM[front];
        front = -1;
        rear = -1;
        return retEl;
    }
    else
    {
        retEl = QueueMEM[front];
        ++front;
        return retEl;
    }
}
int main()
{
    EnQueue(2);
    EnQueue(5);
    EnQueue(7);
    EnQueue(3);
    EnQueue(1);
    EnQueue(9);
    EnQueue(10);
    EnQueue(4);
    EnQueue(6);
    EnQueue(21);
    EnQueue(37);
    int i;
    for (i = 0; i < MAXSIZE + 3; i++)
    {
        printf("%d\t", DeQueue());
    }
    printf("\n");
    
    EnQueue(2);
    EnQueue(5);
    EnQueue(7);
    EnQueue(3);
    EnQueue(1);
    EnQueue(9);
    EnQueue(10);
    return 0;
}