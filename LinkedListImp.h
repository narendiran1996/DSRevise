#pragma once

#include <iostream>

template <typename T>
struct NodeLL
{
    T data;
    NodeLL *next;
};

template <typename T>
class SingleLinkedList
{
public:
    NodeLL<T> *head;
    int LLsize;
    SingleLinkedList()
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
            ptr2->next = temp;
        }
        this->LLsize = this->LLsize + 1;
    }
    void insertNodeBegin(T nodeData)
    {
        NodeLL<T> *temp = new NodeLL<T>;
        temp->data = nodeData;
        temp->next = NULL;

        // head Node insertion
        if (this->head == NULL)
            this->head = temp;
        else
        {
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

        if (LLposition == 1)
        {
            // headNode Insertion
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
std::ostream &operator<<(std::ostream &stream, SingleLinkedList<T> &sll)
{
    NodeLL<T> *ptr;
    ptr = sll.getHead();
    while (ptr != NULL)
    {
        stream << ptr->data << '\t';
        ptr = ptr->next;
    }
    return stream;
}