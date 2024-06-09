#define MAX_SIZE 20

typedef struct Queue {
    int head, tail;
    int array[MAX_SIZE];
} Queue;

Queue* initQueue()
{
    Queue* Q = malloc(sizeof(Queue));
    Q->head = -1;
    Q->tail = -1;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        Q->array[i] = 0;
    }
    return Q;
}

bool isFull(Queue* q)
{
    return ((q->tail + 1) % MAX_SIZE == q->head);
}

bool isEmpty(Queue* q)
{
    return q->head == -1;
}

bool enQueue(Queue* q, int x)
{
    if (isFull(q)) return false; // queue is full
    q->tail = (q->tail + 1) % MAX_SIZE;
    if (q->head == -1) // queue is empty
    {
        q->head++;
        q->array[q->tail] = x;
        return true;
    }
    q->array[q->tail] = x;
    return true;
}

int deQueue(Queue* q)
{
    if (isEmpty(q)) return -1;

    int pop = q->array[q->head];
    // we're the dequeueing the last value in the queue
    if (q->head == q->tail)
    {
        q->head = q->tail = -1;
        return pop;
    }
    q->head = (q->head + 1) % MAX_SIZE;
    return pop;
}

void printQueue(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!");
        return;
    }
    printf("Current Queue:\n");
    int i = q->head;
    while (true) {
        printf("(%d)\t%d\n", i, q->array[i]);
        if (i == q->tail) break;
        i = (i + 1) % MAX_SIZE;
    }
}
