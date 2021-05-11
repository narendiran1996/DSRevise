#include <iostream>

template <typename T>
struct NodeQueue
{
    T data;
    NodeQueue *next;
};

template <typename T>
class QueueLL
{
public:
    NodeQueue<T> *front;
    NodeQueue<T> *rear;
    int QueueSize;

    QueueLL()
    {
        this->front = NULL;
        this->rear = NULL;
        this->QueueSize = 0;
    }

    int isEmpty()
    {
        return (this->front == NULL) && (this->rear == NULL);
    }
    void EnQueue(T el)
    {
        NodeQueue<T> *temp = new NodeQueue<T>();
        temp->data = el;
        temp->next = NULL;

        if (this->isEmpty())
        {
            this->front = temp;
            this->rear = temp;
        }
        else
        {
            (this->rear)->next = temp;
            this->rear = temp;
        }
        this->QueueSize = this->QueueSize + 1;
    }

    T DeQueue()
    {
        NodeQueue<T> *ptr = this->front;
        T retEl;
        if (this->isEmpty())
        {
            std::cout << "QUEUE is EMPTY\n";
            return NULL;
        }
        else if (this->front == this->rear) // just one element, make front and rear -1 for empty
        {
            retEl = (this->front)->data;
            this->rear = NULL;
            this->front = NULL;
            delete ptr;
            this->QueueSize = 0;
            return retEl;
        }
        else
        {
            retEl = (this->front)->data;
            this->front = (this->front)->next;
            delete ptr;
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
std::ostream &operator<<(std::ostream &stream, QueueLL<T> &queue)
{
    NodeQueue<T> *i = NULL;
    for (i = queue.front; i != NULL; i = i->next)
    {
        stream << i->data << '\t';
    }
    return stream;
}

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