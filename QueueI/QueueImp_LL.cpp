#include <iostream>
#include "../QueueImp.h"

int main()
{
    QueueLL<int> myQueue = QueueLL<int>();
    myQueue.EnQueue(2);
    myQueue.EnQueue(5);
    myQueue.EnQueue(7);
    myQueue.EnQueue(3);
    myQueue.EnQueue(1);
    myQueue.EnQueue(9);
    myQueue.EnQueue(10);
    myQueue.EnQueue(4);
    myQueue.EnQueue(6);
    myQueue.EnQueue(21);
    myQueue.EnQueue(37);
    std::cout << myQueue << std::endl;

    for (int i = 0; i < 10 + 3; i++)
        std::cout << myQueue.DeQueue() << '\t';
    std::cout << '\n';
    std::cout << myQueue << std::endl;
    myQueue.EnQueue(2);
    myQueue.EnQueue(5);
    myQueue.EnQueue(7);
    myQueue.EnQueue(3);
    myQueue.EnQueue(1);
    myQueue.EnQueue(9);
    myQueue.EnQueue(10);
    std::cout << myQueue << std::endl;
    return 0;
}