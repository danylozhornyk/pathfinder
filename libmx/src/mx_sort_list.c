#include "libmx.h"

static void swap(void **s1, void **s2) 
{
    void *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    if (list)
    {
        for (t_list *i = list; i; i = i->next)
        {
            for (t_list *j = list; j->next; j = j->next)
            {
                if (cmp(j->data, j->next->data))
                {
                    swap(&j->data, &j->next->data);  
                }
            }
        }
    }
    return list;
}
