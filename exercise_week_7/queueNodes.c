#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct node
{
    int val;
    struct node* next;
} node;

void new();
bool is_empty();
int dequeue();
void enqueue(int x);

node* head,* tail;

void new()
{
    head = tail = NULL;
}

bool is_empty()
{
    if (head == NULL && tail == NULL) {return true;}
    return false;
}

int dequeue()
{
    if (is_empty()) {return -1;}

    if (head == tail) 
    {
        int value = head->val;
        free(head);
        head = tail = NULL;
        return value;    
    }
    else 
    {
        node* i = head;
        int value = i->val;

        head = head->next;
        free(i);

        return value;
    }

}

void enqueue(int x) 
{
    if (is_empty())
    {
        node* q = malloc(sizeof(node));
        q->val = x;
        q->next = NULL;
        head = tail = q;
    }
    else
    {
        node* q = malloc(sizeof(node));
        q->val = x;
        q->next = NULL;
        tail->next = q;
        tail = q;
    }
}

void print_queue() {
    if (is_empty()) {
        printf("The queue is empty.\n");
        return;
    }

    printf("The queue is (from head to tail): ");
    for (node* node = head; node != NULL; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");
}

int main() {
    new();
    printf("The initial queue is empty: %d\n", is_empty());
    printf("I now enqueue the values 3, 4 and 2\n");
    enqueue(3);
    enqueue(4);
    enqueue(2);
    print_queue();
    printf("I now dequeue (remove from the head)\n");
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Enqueued value: 10\n");
    enqueue(10);
    print_queue();
    printf("Enqueued value: 20\n");
    enqueue(20);
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    return 0;
}