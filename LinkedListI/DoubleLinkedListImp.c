// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>
#define DEBUG 0

// Node Defintion
struct Node
{
    /* data */
    int data;
    struct Node *next, *prev;
};

// using **headPtr becuase we are using pointer to head and not the head
// this is because modification to the LL to take place
void displayLL(struct Node **headPtr)
{
    struct Node *ptr, *p;
    // we deference headPtr to get the head
    ptr = *headPtr;
    printf("FOrward Print\n");
    if (DEBUG)
        printf("Node's Address - Data - Node's Next Address\n");
    while (ptr != NULL)
    {
        if (DEBUG)
            printf("0x%x\t%d\t0x%x\n", ptr, ptr->data, ptr->next);
        else
            printf("%d\t", ptr->data);
        p = ptr;
        ptr = ptr->next;
    }
    printf("\n");

    printf("Reverse Print\n");

    ptr = p;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

void insertNodeEnd(struct Node **headPtr, int nodeData)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = nodeData;
    temp->next = NULL;
    temp->prev = NULL;

    // head Node insertion
    if (*headPtr == NULL)
    {
        *headPtr = temp;
    }
    else
    {
        // insertion at end
        struct Node *ptr1, *ptr2;
        ptr1 = *headPtr;
        ptr2 = *headPtr;
        while (ptr1 != NULL)
        {
            ptr2 = ptr1; // pointer to store the current node
            ptr1 = ptr1->next;
        }
        temp->prev = ptr2;
        ptr2->next = temp;
    }
}

void insertNodeBegin(struct Node **headPtr, int nodeData)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = nodeData;
    temp->next = NULL;
    temp->prev = NULL;

    // head Node insertion
    if (*headPtr == NULL)
    {
        *headPtr = temp;
    }
    else
    {
        (*headPtr)->prev = temp;
        temp->next = *headPtr;
        *headPtr = temp;
    }
}

void insertNode(struct Node **headPtr, int nodeData, int LLposition)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = nodeData;
    temp->next = NULL;

    if (LLposition == 1)
    {
        // headNode Insertion
        (*headPtr)->prev = temp;
        temp->next = *headPtr;
        *headPtr = temp;
    }
    else
    {
        int cPos = 1;
        struct Node *ptr1, *ptr2;
        ptr1 = *headPtr;
        ptr2 = *headPtr;

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
            if (DEBUG)
                printf("\nVALID INSERTION LOCATION\n");
            temp->next = ptr2->next;
            temp->prev = ptr2;

            (ptr2->next)->prev = temp;
            ptr2->next = temp;
        }
        else
        {
            printf("\nINVALID INSERTION LOCATION of %d\n", LLposition);
        }
    }
}

void deleteNode(struct Node **headPtr, int LLposition)
{
    if (LLposition == 1)
    {
        // headNode Deletion
        struct Node *ptr;
        ptr = *headPtr;
        if (ptr->next == NULL) // JUst one Node
        {
            *headPtr = NULL;
        }
        else
        {
            *headPtr = ptr->next;
            (*headPtr)->prev = NULL;
        }
        free(ptr);
    }
    else
    {
        int cPos = 1;
        struct Node *ptr1, *ptr2;
        ptr1 = *headPtr;
        ptr2 = *headPtr;

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
            if (DEBUG)
            {
                printf("\nVALID DELETION LOCATION\n");
                printf("%d currentNode\n", ptr2->data);
            }

            (ptr1->next)->prev = ptr2;
            ptr2->next = ptr1->next;

            free(ptr1);
        }
        else
        {
            printf("\nINVALID DELETION LOCATION of %d\n", LLposition);
        }
    }
}

void reverseLL(struct Node **headPtr)
{

    struct Node *currentNode, *nextNode, *prevNode;
    currentNode = *headPtr;
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

    *headPtr = prevNode;
}


int main()
{
    // Head Node;
    struct Node *head;
    head = NULL;

    printf("****\tINSERT NODE END\t****\n");
    insertNodeEnd(&head, 48);
    insertNodeEnd(&head, 32);
    insertNodeEnd(&head, 64);
    insertNodeEnd(&head, 15);
    insertNodeEnd(&head, 7);
    displayLL(&head);
    printf("****\tINSERT NODE BEGIN\t****\n");
    insertNodeBegin(&head, 1);
    insertNodeBegin(&head, 2);
    insertNodeBegin(&head, 3);
    insertNodeBegin(&head, 4);
    displayLL(&head);

    printf("****\tINSERT NODE\t****\n");
    insertNode(&head, 11, 1);
    insertNode(&head, 22, 1);
    insertNode(&head, 33, 3);
    insertNode(&head, 44, 4);
    insertNode(&head, 55, 3);
    insertNode(&head, 66, 6);
    insertNode(&head, 77, 2);
    insertNode(&head, 2020, 20);
    displayLL(&head);

    printf("****\tDELETE NODE\t****\n");
    deleteNode(&head, 1);
    displayLL(&head);
    deleteNode(&head, 1);
    displayLL(&head);
    deleteNode(&head, 1);
    displayLL(&head);
    deleteNode(&head, 3);
    displayLL(&head);
    deleteNode(&head, 4);
    displayLL(&head);
    deleteNode(&head, 6);
    displayLL(&head);
    deleteNode(&head, 2);
    displayLL(&head);

    printf("****\tREVERSE LL\t****\n");
    reverseLL(&head);
    displayLL(&head);


    return 0;
}