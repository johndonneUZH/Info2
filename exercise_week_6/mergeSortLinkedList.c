#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int val;
    struct node *next;
    struct node *prev;
};

struct node *getMidNode(struct node *head) 
{
    struct node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct node *mergeAct(struct node *list1, struct node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }

    if (list2 == NULL)
    {
        return list1;
    }

    if (list1->val < list2->val)
    {
        list1->next = mergeAct(list1->next, list2);
        list1->next->prev = list1;
        list1->prev = NULL;
        return list1;
    }
    else
    {
        list2->next = mergeAct(list1, list2->next);
        list2->next->prev = list2;
        list2->prev = NULL;
        return list2;
    }
}

struct node *mergeSort(struct node *head) 
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct node *mid = getMidNode(head);
    struct node *next = mid->next;
    mid->next = NULL;

    struct node *list1 = mergeSort(head);
    struct node *list2 = mergeSort(next);

    return mergeAct(list1, list2);
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

    // Create second linked list
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    head2->val = 2;
    head2->next = (struct node *)malloc(sizeof(struct node));
    head2->next->val = 4;
    head2->next->next = (struct node *)malloc(sizeof(struct node));
    head2->next->next->val = 6;
    head2->next->next->next = NULL;

    // Sort the individual linked lists
    struct node *sorted1 = mergeSort(head1);
    struct node *sorted2 = mergeSort(head2);

    // Merge the sorted linked lists
    struct node *merged = mergeAct(sorted1, sorted2);

    // Print the merged list
    struct node *current = merged;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    return 0;
}