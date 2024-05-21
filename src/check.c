#include "../include/push_swap.h"

void ft_is_sort(t_stack *a, t_stack *b)
{
    t_node *temp;
    t_node *next;

    temp = a->top;
    while (temp->next)
    {
        next = temp->next;
        if (temp->rnk > next->rnk)
            return ;
        temp = next;
    }
    ft_free_stack(a);
    ft_free_stack(b);
    exit(1);
}