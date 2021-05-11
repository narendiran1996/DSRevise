#include <iostream>

template <typename T>
struct NodeLL
{
    T data;
    NodeLL *next, *prev;
};

template <typename T>
class DoubleLinkedList
{
private:
    NodeLL<T> *head;
    int LLsize;

public:
    DoubleLinkedList()
    {
        this->head = NULL;
        this->LLsize = 0;
    }
    NodeLL<T> *getHead()
    {
        return this->head;
    }
    int getSize()
    {
        return this->LLsize;
    }
    void insertNodeEnd(T nodeData)
    {
        NodeLL<T> *temp = new NodeLL<T>;
        temp->data = nodeData;
        temp->next = NULL;
        temp->prev = NULL;

        if (this->head == NULL)
            this->head = temp;
        else
        {
            // insertion at end
            NodeLL<T> *ptr1, *ptr2;
            ptr1 = this->head;
            ptr2 = this->head;
            while (ptr1 != NULL)
            {
                ptr2 = ptr1; // pointer to store the current node
                ptr1 = ptr1->next;
            }
            temp->prev = ptr2;
            ptr2->next = temp;
        }
        this->LLsize = this->LLsize + 1;
    }
    void insertNodeBegin(T nodeData)
    {
        NodeLL<T> *temp = new NodeLL<T>;
        temp->data = nodeData;
        temp->next = NULL;
        temp->prev = NULL;

        // head Node insertion
        if (this->head == NULL)
            this->head = temp;
        else
        {
            (this->head)->prev = temp;
            temp->next = this->head;
            this->head = temp;
        }
        this->LLsize = this->LLsize + 1;
    }
    void insertNodeN(T nodeData, int LLposition)
    {
        NodeLL<T> *temp = new NodeLL<T>;
        temp->data = nodeData;
        temp->next = NULL;
        temp->prev = NULL;

        if (LLposition == 1)
        {
            // headNode Insertion
            (this->head)->prev = temp;
            temp->next = this->head;
            this->head = temp;
            this->LLsize = this->LLsize + 1;
        }
        else
        {
            int cPos = 1;
            NodeLL<T> *ptr1, *ptr2;
            ptr1 = this->head;
            ptr2 = this->head;

            while (ptr1 != NULL && cPos < LLposition)
            {
                ptr2 = ptr1;
                ptr1 = ptr1->next;
                cPos++;
            }
            // printf("%d cosp", cPos);
            if (cPos == LLposition)
            {
                // Valid Insertion
                temp->next = ptr2->next;
                temp->prev = ptr2;

                if (ptr2->next != NULL)
                    (ptr2->next)->prev = temp;
                ptr2->next = temp;
                this->LLsize = this->LLsize + 1;
            }
            else
            {
                printf("\nINVALID INSERTION LOCATION of %d\n", LLposition);
            }
        }
    }
    void deleteNode(T LLposition)
    {
        if (this->LLsize == 0)
        {
            std::cout << "Empty List can't delete" << std::endl;
            return;
        }

        if (LLposition == 1)
        {
            // headNode Deletion
            NodeLL<T> *ptr;
            ptr = this->head;
            if (ptr->next == NULL) // JUst one Node
            {
                this->head = NULL;
            }
            else
            {
                this->head = ptr->next;
                (this->head)->prev = NULL;
            }
            delete ptr;
            this->LLsize = this->LLsize - 1;
        }
        else if (LLposition >= this->LLsize + 1)
        {
            printf("\nINVALID DELETION LOCATION of %d\n", LLposition);
        }
        else
        {
            int cPos = 1;
            NodeLL<T> *ptr1, *ptr2;
            ptr1 = this->head;
            ptr2 = this->head;

            while (ptr1 != NULL && cPos < LLposition)
            {
                ptr2 = ptr1;
                ptr1 = ptr1->next;
                cPos++;
            }
            // printf("%d cosp", cPos);
            if (cPos == LLposition)
            {
                // Valid Deletion
                if (ptr1->next != NULL)
                    (ptr1->next)->prev = ptr2;
                ptr2->next = (ptr2->next)->next;
                this->LLsize = this->LLsize - 1;
                delete ptr1;
            }
            else
            {
                printf("\nINVALID DELETION LOCATION of %d\n", LLposition);
            }
        }
    }
    void reverseLL()
    {

        NodeLL<T> *currentNode, *nextNode, *prevNode;
        currentNode = this->head;
        prevNode = NULL;

        while (currentNode != NULL)
        {
            // storing the nextNode to traverrse
            nextNode = currentNode->next;
            // chaning the link of current node to point to previous Node
            currentNode->next = prevNode;
            currentNode->prev = nextNode;
            // assing previous Node
            prevNode = currentNode;
            // updataing currentNode for traversion
            currentNode = nextNode;
        }

        this->head = prevNode;
    }

    void displayLL()
    {
        std::cout << *this << std::endl;
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, DoubleLinkedList<T> &sll)
{
    NodeLL<T> *ptr, *lastPtr;
    ptr = sll.getHead();
    stream << "Forward Print \n";
    while (ptr != NULL)
    {
        stream << ptr->data << '\t';
        lastPtr = ptr;
        ptr = ptr->next;
    }

    stream << "Reverse Print \n";
    ptr = lastPtr;
    while (ptr != NULL)
    {
        stream << ptr->data << '\t';
        ptr = ptr->prev;
    }
    return stream;
}

int main()
{
    std::cout << "Insertion Node END" << std::endl;
    DoubleLinkedList<int> myList;
    myList.insertNodeEnd(6);
    myList.insertNodeEnd(11);
    myList.insertNodeEnd(2);
    myList.insertNodeEnd(5);
    myList.insertNodeEnd(13);
    std::cout << myList << std::endl;

    std::cout << "Insertion Node Begin" << std::endl;
    myList.insertNodeBegin(6);
    myList.insertNodeBegin(11);
    myList.insertNodeBegin(2);
    myList.insertNodeBegin(5);
    myList.insertNodeBegin(13);
    myList.displayLL();

    std::cout << "Insertion Node N" << std::endl;
    myList.insertNodeN(33, 1);
    myList.insertNodeN(44, 1);
    myList.insertNodeN(55, 7);
    myList.insertNodeN(88, 9);
    myList.insertNodeN(99, myList.getSize() + 1);
    std::cout << myList << std::endl;

    std::cout << "Deletion Node" << std::endl;
    std::cout << myList << std::endl;
    myList.deleteNode(1);
    std::cout << myList << std::endl;
    myList.deleteNode(2);
    std::cout << myList << std::endl;
    myList.deleteNode(1);
    std::cout << myList << std::endl;
    myList.deleteNode(5);
    std::cout << myList << std::endl;
    myList.deleteNode(myList.getSize());
    std::cout << myList << std::endl;
    myList.deleteNode(myList.getSize() + 1);
    std::cout << myList << std::endl;

    std::cout << "Reversing" << std::endl;
    myList.reverseLL();
    std::cout << myList << std::endl;

    return 0;
}