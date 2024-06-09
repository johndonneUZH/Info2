#define MAX_SIZE 20

typedef struct stack {
    int val;
    struct stack* next;
} stack;

stack* initStack()
{
    stack* S = NULL;
    return S;
}

bool push(stack** S, int x)
{
    stack* p = malloc(sizeof(stack));
    if (p == NULL) return false;

    p->val = x;
    p->next = *S;
    *S = p;
    return true;
}

int pop(stack** S)
{
    if (*S == NULL) return -1;

    int pop = (*S)->val;
    stack* temp = (*S);
    *S = (*S)->next;
    free(temp);
    return pop;
}

void printStack(stack** S)
{
    if (*S == NULL)
    {
        printf("Stack is empty!");
        return;
    }
    stack* p = *S;
    int counter = 0;
    printf("Current Stack:\n");
    while (p != NULL)
    {
        printf("(%d)\t%d\n", counter, p->val);
        counter++;
        p = p->next;
    }
}
