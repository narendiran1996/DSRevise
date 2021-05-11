#include <iostream>
#define MAXSIZE 5

template <typename T>
class StackArray
{
public:
    T StackMem[MAXSIZE];
    int top;
    int size;

    StackArray()
    {
        this->top = -1;
        this->size = 0;
    }

    void Push(T el)
    {
        if (this->top == (MAXSIZE - 1))
        {
            std::cout << "\n****ERROR****\n-----------OVERFLOW-----------\n";
            return;
        }
        this->size = this->size + 1;
        this->top = this->top + 1;
        this->StackMem[this->top] = el;
    }

    T Pop()
    {
        if (this->top == -1)
        {
            std::cout << "\n****ERROR****\n-----------UNDERFLOW-----------\n";
            this->size = 0;
            return -9999;
        }
        this->size = this->size - 1;
        this->top = this->top - 1;
        return this->StackMem[this->top];
    }

    T getTop()
    {
        return this->StackMem[this->top];
    }

    void DisplayStack()
    {
        std::cout << *this << std::endl;
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, StackArray<T> &stack)
{
    int i;
    for (i = stack.size - 1; i >= 0; i--)
    {
        std::cout << stack.StackMem[i] << '\t';
    }
    return stream;
}

int main()
{
    StackArray<int> myStack = StackArray<int>();
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
    std::cout << myStack << std::endl;
    myStack.Push(62);

    StackArray<char> myStack2 = StackArray<char>();
    myStack2.Push('N');
    myStack2.Push('a');
    myStack2.Push('r');
    myStack2.Push('e');
    myStack2.Push('n');
    std::cout << myStack2 << std::endl;
    return 0;
}