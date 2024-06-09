typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} LinkedListQueue;

LinkedListQueue* initLinkedListQueue() {
    LinkedListQueue* queue = (LinkedListQueue*)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

bool isEmptyLinkedListQueue(LinkedListQueue* queue) {
    return queue->front == NULL;
}

bool enqueueLinkedList(LinkedListQueue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return false; // checking if malloc worked
    newNode->value = value;
    newNode->next = NULL;
    if (isEmptyLinkedListQueue(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    return true;
}

int dequeueLinkedList(LinkedListQueue* queue) {
    if (isEmptyLinkedListQueue(queue)) return -1;
    Node* temp = queue->front;
    int value = temp->value;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return value;
}
