/*The LIFO behaviour of a stack shall be simulated with FIFO
queues. Assume a FIFO queue data structure with the following operations
enQueue(queue q, int val), int deQueue(queue q), and int size(queue
q). Use one or more FIFO queues to implement the pop() and push() functions of a LIFO stack.*/

push(queue* q, int val)
{
    enQueue(q, val);
}

pop(queue* q1)
{
    queue* q2 = initQueue();

    while(size(q1) != 1)
    {
        enQueue(q1, deQueue(q2))
    }

    int x = deQueue(q1);

    while(size(q2) != 0)
    {
        enQueue(q1, deQueue(q1))
    }
    
    return x;
}
