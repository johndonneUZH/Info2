#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Functions already implemented */
struct month *init_months(struct month *head);
void free_months(struct month *head);

/* given month struct */
struct month {
    int month_number;
    char *month_name;
    struct month *next;
};

void print_months(struct month *head) {
    while (head != NULL)
    {
        printf("%s (%i)\n", head -> month_name, head -> month_number );
        head = head -> next;
    }
    printf("\n");
}

struct month *get_previous_month(struct month *head, struct month *given_month) {
    if (head == NULL || given_month == NULL) 
    {
        return NULL;
    }
    else if (head->next == given_month)
    {   
        return head;
    }

    struct month *current = head;
    while (current->next != NULL && current->next != given_month) 
    {
        current = current->next;
    }
    return current;
}

struct month *swap_month(struct month *head, struct month *a, struct month *b) {
    /* TODO: Implement task 2.(c) */
    struct month *prev_a = NULL, *prev_b = NULL;
    struct month *curr = head;

    // Find a and b in the linked list and keep track of their previous nodes
    while (curr != NULL)
    {
        if (curr->next == a)
        {
            prev_a = curr;
        }
        else if (curr->next == b)
        {
            prev_b = curr;
        }
        curr = curr->next;
    }

    if (prev_a != NULL && prev_b != NULL)
    {
        // Swap a and b
        struct month *temp = prev_a->next;
        prev_a->next = prev_b->next;
        prev_b->next = temp;

        temp = prev_a->next->next;
        prev_a->next->next = prev_b->next->next;
        prev_b->next->next = temp;
    }

    return head;
}

struct month *selection_sort(struct month *head) {
    /* TODO: Implement task 2.(d) */
    struct month *i;
    struct month *j;
    struct month *k;

    i = head;
    while (i != NULL) //from 1 to n
    {
        print_months(head);
        k = i;
        j = i->next; //j = i+1
        while (j != NULL)
        {
            if (j->month_number < k->month_number)
            {
                k = j;
            }
            j = j->next;
        }
        head = swap_month(head, i, k);
        i = k->next;
    }
    return head;
}

int main(int argc, char *argv[]) {
    /* Init month linked list */
    struct month *head;
    head = init_months(head);

    /* Print the linked list as it is after initialization */
    print_months(head);

    struct month *current = head;
    while (current->month_number != 8)
    {
        current = current->next;
    }
    struct month *p = get_previous_month(head, current);
    printf("%s (%i)", p->month_name, p->month_number);

    selection_sort(head);

    /* Cleanup */
    free_months(head);
    return 0;
}

struct month *init_months(struct month *head) {
    int n = 12;
    int init_order[n];
    char *month_strings[] = {"January",   "February", "March",    "April",
                             "May",       "June",     "July",     "August",
                             "September", "Oktober",  "November", "Dezember"};
    struct month *h;
    struct month *p; /* trailing pointer */

    /* create random order with fisher-yates shuffle */
    for (int i = 0; i < n; ++i) {
        init_order[i] = i + 1;
    }
    srand(time(0));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1); /* generate random index below i */
        /* swap a[i] with a[j] */
        int tmp = init_order[i];
        init_order[i] = init_order[j];
        init_order[j] = tmp;
    }

    /* create month linked list */
    h = malloc(sizeof(struct month)); /* first node, gets returned */
    h->month_number = init_order[0];  /*  */
    h->month_name = month_strings[h->month_number - 1];
    p = h; /* pointer that goes through list */
    for (int i = 1; i < n; ++i) {
        struct month *m = malloc(sizeof(struct month));
        /* printf("create month %d\n", i); */
        m->month_number = init_order[i];
        m->month_name = month_strings[m->month_number - 1];
        p->next = m; /* previous node points now to this */

        p = m; /* increment trailing pointer */
    }
    p->next = NULL;
    return h;
}

void free_months(struct month *head) {
    /* free month linked list */
    struct month *p = head;
    struct month *q = head->next;
    while (q) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}
