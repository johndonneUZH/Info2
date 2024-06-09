#define MAX_SIZE 20

typedef struct stack {
    int top;
    int array[MAX_SIZE];
} stack;

stack* initStack()
{
    stack* S = malloc(sizeof(stack));
    S->top = -1;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        S->array[i] = 0;
    }
    return S;
}

bool push(stack* S, int x)
{
    // check if stack is full
    if (S->top == MAX_SIZE - 1) return false;

    // push
    S->top++;
    S->array[S->top] = x;
    return true;
}

int pop(stack* S)
{
    // check if stack is empty
    if (S->top == -1) return -1;

    // pop;
    int pop = S->array[S->top];
    S->top--;
    return pop;
}

bool isEmptyStack(stack* S)
{
    return S->top == -1;
}

void printStack(stack* S)
{
    if (isEmptyStack(S))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Current Stack:\n");
    for (int i = S->top; i >= 0; i--)
    {
        printf("(%d)\t%d\n", i, S->array[i]);
    }
}
