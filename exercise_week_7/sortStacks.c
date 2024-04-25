#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"


//-----------------------------------------------------------------------------

typedef struct Node {
    int key;
    struct Node *next;
} Node;

// Convention: new_stack points to NULL when the stack is empty.
Node** new() {
    Node **new_stack = malloc(sizeof(Node*));
    *new_stack = NULL;
    return new_stack;
}

bool is_empty(Node** S) {
    return (*S == NULL);
}

int pop(Node** S) {
    if (is_empty(S)) {
        return -1;
    }

    int top_value;
    top_value = (*S)->key;

    Node* temp = *S;
    *S = temp->next;

    //free(temp);

    return top_value;
}

void push(Node** S, int x) {
    Node* new_node = malloc(sizeof(Node*));

    new_node->key = x;
    new_node->next = *S;
    *S = new_node;
}
//-----------------------------------------------------------

Node** sort_stack(Node** S)
{
    Node **S_new = new();
    Node **temp = new();
    int x, y;

    while (is_empty(S) == 0)
    {
        push(S_new, pop(S));
    }

    push(S, pop(S_new));

    while (!is_empty(S_new))
    {
        x = pop(S_new);
        while(!is_empty(S))
        {
            y = pop(S);
            if (x < y)
            {
                push(temp, y);

            }
            else
            {
                push(S, y);
                break;
            }
        }

        push(S, x);
        while(!is_empty(temp))
        {
            push(S, pop(temp));
        }
    }
    return S;
}


void print_stack_helper(Node *node) {
    if (node != NULL) {
        print_stack_helper(node->next);
        printf("%d ", node->key);
    }
}

void print_stack(Node **S, char *name) {
    if (is_empty(S) == 0) {
        printf("Stack %s is (from bottom to top): ", name);
        print_stack_helper(*S);
        printf("\n");
    }
    else {
        printf("The stack %s is empty.\n", name);
    }
}

int main() {
    Node **S = new();
    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 4);
    print_stack(S, "S");
    S = sort_stack(S);
    print_stack(S, "S");
    return 0;
}