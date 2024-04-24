#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct Node
{
    int val;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node **head, **tail;
} Queue;

Queue* new();
bool is_empty(Queue* Q);
int dequeue(Queue* Q) ;
void enqueue(Queue* Q, int x)


Queue* new()
{
    struct Queue Q;
    Q.head = malloc(sizeof(Node*));
    Q.tail = malloc(sizeof(Node*));

    *(Q.head) = *(Q.tail) = NULL;
    return Q;
}

bool is_empty(Queue* Q)
{
    return (*(Q.head) == NULL && *(Q.tail) == NULL);
}

int dequeue(Queue* Q)
{
    if (is_empty(Q)) {return -1;} //Queue is empty

    if (Q.head == Q.tail) //dequeing last element, resetting queue to empty
    {
        int value = *(Q.head)->val;
        free(*(Q.head));
        *(Q.head) = *(Q.tail) = NULL;
        return value;
    }
    else //changing pointer of the root to the node after
    {
        int value = (*(Q.head))->val;
        Node* temp = *(Q.head);
        *(Q.head) = (*(Q.head))->next;
        free(*(Q.head))
        return value;
    }
}

void enqueue(Queue* Q, int x)
{
    if (is_empty(Q)) //queue is empty create a node and make head and tail point to it
    {
        Node* q = malloc(sizeof(Node));
        q->val = x;
        q->next = NULL;
        *(Q.head) = *(Q.tail) = q;  
    }

    else
    {
        Node* q = malloc(sizeof(Node));
        q->val = x;
        q->next = NULL;
        (*(Q.tail))->next = q;
        (*(Q.tail)) = q;
    }
}


