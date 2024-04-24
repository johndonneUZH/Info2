#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define MAX_QUEUE_SIZE 1000

int Q[MAX_QUEUE_SIZE];
int head, tail;

void new();
bool is_empty();
int dequeue();
void enqueue(int x);

void new()
{
    head = tail = 0;
}

bool is_empty()
{
    return (head == tail);
}

int dequeue()
{
    if (is_empty())
    {
        return -1;
    }
    int i = head;
    head = (head + 1) % MAX_QUEUE_SIZE;
    return Q[i];
}

void enqueue(int x)
{
    int next_tail = (tail + 1) % MAX_QUEUE_SIZE;
    if (next_tail == head)
    {
        return 0;
    }
    Q[tail] = x;
    tail = next_tail;
}

void print_queue() {
    if (is_empty()) {
        printf("The queue is empty.\n");
        return;
    }

    printf("The queue is (from head to tail): ");
    int i;
    for (i = head; i != tail; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", Q[i]);
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
