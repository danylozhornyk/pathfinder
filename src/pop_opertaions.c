#include "../inc/pathfinder.h"

void mx_pop_front_node(t_node **head) {
    if (head && *head) {
        if ((*head)->next == NULL) {
            mx_free_node(head); 
            return;
        }

        t_node *tmp = *head; 
        *head = (*head)->next; 

        mx_free_node(&tmp); 
    }
}

void mx_pop_back_parent(t_parent **head)
{
    if (head == NULL || *head == NULL)
    {
        return; 
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    t_parent *tmp = *head;
    while (tmp && tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    free(tmp->next);
    tmp->next = NULL;
}
