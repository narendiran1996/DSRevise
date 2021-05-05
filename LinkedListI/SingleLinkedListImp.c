// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>
#define DEBUG 0

// Node Defintion
struct Node
{
    /* data */
    int data;
    struct Node *next;
};

// using **headPtr becuase we are using pointer to head and not the head
// this is because modification to the LL to take place
void displayLL(struct Node **headPtr)
{
    struct Node *ptr;
    // we deference headPtr to get the head
    ptr = *headPtr;
    if (DEBUG)
        printf("Node's Address - Data - Node's Next Address\n");
    while (ptr != NULL)
    {
        if (DEBUG)
            printf("0x%x\t%d\t0x%x\n", ptr, ptr->data, ptr->next);
        else
            printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertNodeEnd(struct Node **headPtr, int nodeData)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = nodeData;
    temp->next = NULL;

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
        ptr2->next = temp;
    }
}

void insertNodeBegin(struct Node **headPtr, int nodeData)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = nodeData;
    temp->next = NULL;

    // head Node insertion
    if (*headPtr == NULL)
    {
        *headPtr = temp;
    }
    else
    {
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
            ptr2->next = (ptr2->next)->next;

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
        // assing previous Node
        prevNode = currentNode;
        // updataing currentNode for traversion
        currentNode = nextNode;
    }

    *headPtr = prevNode;
}

void printReverseRecursive(struct Node **headPtr)
{
    struct Node *ptr;
    ptr = *headPtr;
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        printReverseRecursive(&(ptr->next));
        printf("%d\t", ptr->data);
    }
}

void reverseLLRecursive(struct Node **headPtr, struct Node **nodeInRecursion)
{
    struct Node *currentNode, *ptr;
    currentNode = *nodeInRecursion;

    if (currentNode->next == NULL) // till head Node
    {
        *headPtr = *nodeInRecursion;
        return;
    }
    else
    {
        reverseLLRecursive(headPtr, &(currentNode->next));
        // storing nextNode for chaning
        ptr = currentNode->next;
        // actual changing
        ptr->next = currentNode;
        // NULl because we will change recursive, so this will getupdated
        currentNode->next = NULL;
    }
}



int main()
{
    // Head Node;
    struct Node *head;
    head = NULL;

    insertNodeEnd(&head, 48);
    insertNodeEnd(&head, 32);
    insertNodeEnd(&head, 64);
    insertNodeEnd(&head, 15);
    insertNodeEnd(&head, 7);
    displayLL(&head);
    insertNodeBegin(&head, 1);
    insertNodeBegin(&head, 2);
    insertNodeBegin(&head, 3);
    insertNodeBegin(&head, 4);
    displayLL(&head);

    insertNode(&head, 11, 1);
    insertNode(&head, 22, 1);
    insertNode(&head, 33, 3);
    insertNode(&head, 44, 4);
    insertNode(&head, 55, 3);
    insertNode(&head, 66, 6);
    insertNode(&head, 77, 2);
    insertNode(&head, 2020, 20);
    displayLL(&head);

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

    reverseLL(&head);
    displayLL(&head);
    printReverseRecursive(&head);
    printf("\n");
    reverseLLRecursive(&head, &head);
    displayLL(&head);

    return 0;
}