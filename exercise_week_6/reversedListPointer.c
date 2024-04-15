#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int val;
    struct node *next;
    struct node *prev;
};

struct node *reverse(struct node *head)
{
    if (head->next != NULL)
    {
        struct node *temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        return reverse(temp); 
    }

    struct node *temp = head->prev;
    head->prev = NULL;
    head->next = temp;

    return head;

}

int main(void)
{
    // Create first linked list
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    head1->val = 1;
    head1->next = (struct node *)malloc(sizeof(struct node));
    head1->next->val = 3;
    head1->next->next = (struct node *)malloc(sizeof(struct node));
    head1->next->next->val = 5;
    head1->next->next->next = NULL;
    
    struct node *current = reverse(head1);
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    return 0;
}