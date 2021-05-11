#include <iostream>

#define MAXSIZE 10

template <typename T>

class QueueArray
{
public:
    T QueueMEM[MAXSIZE];
    int front;
    int rear;
    int QueueSize;

    QueueArray()
    {
        this->front = this->rear = -1;
        this->QueueSize = 0;
    }

    int isEmpty()
    {
        return (this->front == -1) && (this->rear == -1);
    }
    int isFull()
    {
        return (this->rear == MAXSIZE - 1);
    }

    void EnQueue(T el)
    {
        if (this->isFull())
        {
            std::cout << "QUEUE is FULL -- can't add " << el << '\n';
            return;
        }
        else if (this->isEmpty())
        {
            this->front = 0;
            this->rear = 0;
        }
        else
        {
            this->rear = this->rear + 1;
        }

        this->QueueMEM[this->rear] = el;
        this->QueueSize = this->QueueSize + 1;
    }

    T DeQueue()
    {
        T retEl;
        if (this->isEmpty())
        {
            std::cout << "QUEUE is EMPTY\n";
            return NULL;
        }
        else if (this->front == this->rear) // just one element, make front and rear -1 for empty
        {

            retEl = this->QueueMEM[this->front];
            this->front = -1;
            this->rear = -1;
            this->QueueSize = 0;
            return retEl;
        }
        else
        {
            retEl = this->QueueMEM[this->front];
            this->front = this->front + 1;
            this->QueueSize = this->QueueSize - 1;
            return retEl;
        }
    }
    void DisplayQueue()
    {
        std::cout << *this << std::endl;
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, QueueArray<T> &queue)
{
    int i;
    for (i = queue.front; i < queue.rear + 1; i++)
    {
        stream << queue.QueueMEM[i] << '\t';
    }
    return stream;
}

int main()
{
    QueueArray<int> myQueue = QueueArray<int>();
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

    for (int i = 0; i < MAXSIZE + 3; i++)
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