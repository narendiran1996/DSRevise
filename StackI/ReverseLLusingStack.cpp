// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>
#include "../LinkedListImp.h"
#include "../StackLLImp.h"

int main()
{
    // creation of LL
    SingleLinkedList<int> myLL = SingleLinkedList<int>();
    NodeLL<int> *ptr;

    myLL.insertNodeBegin(48);
    myLL.insertNodeBegin(32);
    myLL.insertNodeBegin(64);
    myLL.insertNodeBegin(15);
    myLL.insertNodeBegin(7);
    printf("Linked List Content before Reversing\n");
    std::cout << myLL << '\n';

    // creation of Stack
    StackLL<NodeLL<int> *> myStack = StackLL<NodeLL<int> *>();

    ptr = myLL.head;
    while (ptr != NULL)
    {
        myStack.Push(ptr);
        ptr = ptr->next;
    }

    printf("Stack Content\n");
    std::cout << myStack << '\n';

    SingleLinkedList<int> myLL2 = SingleLinkedList<int>();

    while (!myStack.isEmpty())
    {
        NodeLL<int> *temp;
        temp = myStack.Pop();
        myLL2.insertNodeEnd(temp->data);
    }

    std::cout << "Linked List Content afer Reversing\n";
    std::cout << myLL2 << '\n';

    return 0;
}