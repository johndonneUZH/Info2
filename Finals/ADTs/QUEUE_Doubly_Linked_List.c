typedef struct DNode {
    int value;
    struct DNode* next;
    struct DNode* prev;
} DNode;

typedef struct {
    DNode* front;
    DNode* rear;
} DoublyLinkedListQueue;

DoublyLinkedListQueue* initDoublyLinkedListQueue() {
    DoublyLinkedListQueue* queue = (DoublyLinkedListQueue*)malloc(sizeof(DoublyLinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

bool isEmptyDoublyLinkedListQueue(DoublyLinkedListQueue* queue) {
    return queue->front == NULL;
}

bool enqueueDoublyLinkedList(DoublyLinkedListQueue* queue, int value) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) return false;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = queue->rear;
    if (isEmptyDoublyLinkedListQueue(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    return true;
}

int dequeueDoublyLinkedList(DoublyLinkedListQueue* queue) {
    if (isEmptyDoublyLinkedListQueue(queue)) return -1;
    DNode* temp = queue->front;
    int value = temp->value;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    } else {
        queue->front->prev = NULL;
    }
    free(temp);
    return value;
}
