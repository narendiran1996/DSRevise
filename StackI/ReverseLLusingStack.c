// Linked List Implementation in C
#include <stdio.h>
#include <malloc.h>

struct LLNode
{
    int data;
    struct LLNode *next;
};

void displayLL(struct LLNode **headPtr)
{
    struct LLNode *ptr;
    // we deference headPtr to get the head
    ptr = *headPtr;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertNodeBegin(struct LLNode **headPtr, int nodeData)
{
    struct LLNode *temp = (struct LLNode *)malloc(sizeof(struct LLNode));

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

struct StackNode
{
    struct LLNode *data;
    struct StackNode *next;
};

void Push(struct StackNode **topPtr, struct LLNode **elementPtr)
{
    struct StackNode *temp = (struct StackNode *)malloc(sizeof(struct StackNode));
    temp->data = *elementPtr;
    temp->next = NULL;

    if (*topPtr == NULL)
    {
        *topPtr = temp;
    }
    else
    {
        temp->next = *topPtr;
        *topPtr = temp;
    }
}

void Pop(struct StackNode **topPtr, struct LLNode **retLLElement)
{
    if (*topPtr == NULL)
    {
        printf("\n****ERROR****\n-----------UNDERFLOW-----------\n");
        return;
    }
    struct StackNode *ptr = *topPtr;

    *retLLElement = ptr->data;

    *topPtr = ptr->next;
    free(ptr);
}

void PrintStack(struct StackNode **topPtr)
{
    struct StackNode *ptr;
    // we deference headPtr to get the head
    ptr = *topPtr;
    while (ptr != NULL)
    {
        printf("%d\t", (ptr->data)->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isEmpty(struct StackNode **topPtr)
{
    if (*topPtr == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    // creation of LL
    struct LLNode *head, *ptr;
    head = NULL;
    insertNodeBegin(&head, 48);
    insertNodeBegin(&head, 32);
    insertNodeBegin(&head, 64);
    insertNodeBegin(&head, 15);
    insertNodeBegin(&head, 7);
    printf("Linked List Content before Reversing\n");
    displayLL(&head);

    // creation of Stack

    struct StackNode *top;
    top = NULL;

    ptr = head;
    while (ptr != NULL)
    {
        Push(&top, &ptr);
        ptr = ptr->next;
    }

    printf("Stack Content\n");
    PrintStack(&top);

    struct LLNode *newHead;
    newHead = NULL;
    while (!isEmpty(&top))
    {
        struct LLNode *temp;
        Pop(&top, &temp);

        if (newHead == NULL)
        {
            newHead = temp;
        }
        else
        {
            temp->next = newHead;
            newHead = temp;
        }
    }

    printf("Linked List Content afer Reversing\n");
    displayLL(&newHead);

    return 0;
}