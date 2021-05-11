#pragma once

#include <iostream>

template <typename T>
struct NodeStack
{
    T data;
    NodeStack *next;
};

template <typename T>
class StackLL
{
public:
    NodeStack<T> *top;
    int StackSize;
    StackLL()
    {
        this->top = NULL;
        this->StackSize = 0;
    }

    void Push(T el)
    {
        NodeStack<T> *temp = new NodeStack<T>();
        temp->data = el;
        temp->next = NULL;

        if (this->top == NULL)
        {
            this->top = temp;
        }
        else
        {
            temp->next = this->top;
            this->top = temp;
        }
        this->StackSize = this->StackSize + 1;
    }

    T Pop()
    {
        if (this->top == NULL)
        {
            std::cout << "\n****ERROR****\n-----------UNDERFLOW-----------\n";
            this->StackSize = 0;
            return NULL;
        }
        NodeStack<T> *ptr = this->top;

        T retVal = ptr->data;
        this->top = (this->top)->next;
        this->StackSize = this->StackSize - 1;
        delete ptr;

        return retVal;
    }

    T getTop()
    {
        return (this->top)->data;
    }
    int isEmpty()
    {
        if (this->top == NULL)
            return 1;
        else
            return 0;
    }

    void DisplayStack()
    {
        std::cout << *this << std::endl;
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, StackLL<T> &stack)
{
    NodeStack<T> *ptr = stack.top;
    while (ptr != NULL)
    {
        std::cout << ptr->data << '\t';
        ptr = ptr->next;
    }

    return stream;
}
