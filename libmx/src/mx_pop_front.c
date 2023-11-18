#include "libmx.h"

void mx_pop_front(t_list **head)
{
    if (*head == NULL) 
    {
        return;
    }
    t_list *front_node = *head;
    *head = front_node->next;
    free(front_node);
}
