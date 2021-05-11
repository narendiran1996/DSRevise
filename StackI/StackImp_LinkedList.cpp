#include <iostream>
#define MAXSIZE 5

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
            return -9999;
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