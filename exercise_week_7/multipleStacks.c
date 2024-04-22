#include "stdio.h"
#include "stdbool.h"
#include <stdlib.h>

typedef struct node
{
   int val;
   struct node* next;
} node;

node* new()
{
    node* stack = malloc(sizeof(node));
    stack->next = NULL;
    stack->val = -1;  // Initialize with sentinel value
    return stack;
}

bool is_empty(node* stack)
{
    return stack->next == NULL;
}

int pop(node* stack)
{
   if (stack->next == NULL)
   {
      return -1;
   }

   node* p = stack;
   while (p->next != NULL && p->next->next != NULL)
    {
        p = p->next;
    }

    int popped_value;

    if (p->next == NULL)
    {
        node* temp = p;
        popped_value = temp->val;
        stack = NULL;
        free(temp);
    }
    else
    {
        node* temp = p->next;
        popped_value = temp->val;
        p->next = NULL;
        free(temp);
    }

    return popped_value;
}

void push(node* stack, int value)
{
    node* p = stack;
    while(p->next != NULL) {p = p-> next;}
    node* q = malloc(sizeof(node));
    q->val = value;
    q->next = NULL;
    p->next = q;
}

void print_stack_helper(node* p) 
{
   while (p != NULL) 
   {
     printf("%d ", p->val);
     p = p->next;
   }
}

void print_stack(node* stack, char *name) {
    if (is_empty(stack)) {
        printf("The stack %s is empty.\n", name);
    }
    else {
        printf("Stack %s is (from bottom to top): ", name);
        print_stack_helper(stack->next);
        printf("\n");
    }
}

int main() {
    node* S1 = new();
    printf("The initial stack S1 is empty: %d\n", is_empty(S1));
    push(S1, 3);
    push(S1, 2);
    push(S1, 1);
    print_stack(S1, "S1");
    printf("Popped item: %d\n", pop(S1));
    print_stack(S1, "S1");
    push(S1, 4);
    print_stack(S1, "S1");
    printf("Popped item: %d\n", pop(S1));
    printf("Popped item: %d\n", pop(S1));
    printf("Popped item: %d\n", pop(S1));
    print_stack(S1, "S1");
    printf("Now I tried popping an empty stack: %d\n", pop(S1));

    node* S2 = new();
    push(S2, 2);
    push(S2, 3);
    push(S2, 4);
    print_stack(S2, "S2");
    printf("Now I can pop an element from S2 and push that element in S1.\n");
    push(S1, pop(S2));
    print_stack(S2, "S2");
    print_stack(S1, "S1");
    return 0;
}