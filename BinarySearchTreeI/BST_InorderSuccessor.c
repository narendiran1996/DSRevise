#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct NodeBST
{
    int data;
    struct NodeBST *leftC, *rightC;
};

void InsertBST(struct NodeBST **node, int el)
{
    if (*node == NULL) // root insertion
    {
        struct NodeBST *temp = (struct NodeBST *)malloc(sizeof(struct NodeBST *));
        temp->data = el;
        temp->leftC = NULL;
        temp->rightC = NULL;
        *node = temp;
    }
    else if (el <= (*node)->data)
    {
        InsertBST(&((*node)->leftC), el);
    }
    else if (el >= (*node)->data)
    {
        InsertBST(&((*node)->rightC), el);
    }
}

struct NodeBST *FindMin(struct NodeBST **node)
{
    if (*node == NULL) // no root
        return NULL;
    else if ((*node)->leftC == NULL)
        return *node;
    else
        return FindMin(&((*node)->leftC));
}
struct NodeBST *FindMax(struct NodeBST **node)
{
    if (*node == NULL) // no root
        return NULL;
    else if ((*node)->rightC == NULL)
        return *node;
    else
        return FindMax(&((*node)->rightC));
}

struct NodeBST *SearchBST(struct NodeBST **node, int dataToSearch)
{
    // printf("SBST %d\n", (*node)->data);
    if (*node == NULL) // not found or root is empty
        return NULL;
    else if (((*node)->data) == dataToSearch) // found the element
        return *node;
    else if (dataToSearch < ((*node)->data))
        return SearchBST(&((*node)->leftC), dataToSearch);
    else if (dataToSearch > ((*node)->data))
        return SearchBST(&((*node)->rightC), dataToSearch);
}

int getSuccessor(struct NodeBST **rootPtr, int data)
{
    struct NodeBST *current = SearchBST(rootPtr, data);
    if (current == NULL)
        return -999;

    if (current->rightC != NULL) // has right subtree, so the min of right subtree
        return FindMin(&(current->rightC))->data;
    else // has no right subtree, so the deepest node for which current node is in left
    {
        struct NodeBST *successor, *ancestor;
        successor = NULL;
        ancestor = *rootPtr;

        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->leftC;
            }
            else
            {
                ancestor = ancestor->rightC;
            }
        }
        if(successor == NULL) // last element of the tree so no succesor
            return -333;
        else
            return successor->data;
    }
}

void inOrderTraversal(struct NodeBST **node)
{
    if (*node != NULL)
    {
        inOrderTraversal(&((*node)->leftC));
        printf("%d \t", (*node)->data);
        inOrderTraversal(&((*node)->rightC));
    }
}

int main()
{
    struct NodeBST *root = NULL;

    InsertBST(&root, 12);
    InsertBST(&root, 5);
    InsertBST(&root, 15);
    InsertBST(&root, 3);
    InsertBST(&root, 7);
    InsertBST(&root, 13);
    InsertBST(&root, 17);
    InsertBST(&root, 1);
    InsertBST(&root, 9);
    InsertBST(&root, 19);

    int no = 19;
    printf("Sucessor of %d is %d \n", no, getSuccessor(&root, no));

    return 0;
}
