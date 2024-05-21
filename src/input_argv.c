/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:20:19 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 15:29:52 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	temp = stack->top;
	while (temp)
	{
		next = temp->next;
		ft_printf("%d\n", temp->num);
		temp = next;
	}
}

void	ft_print_stack_rnk(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	temp = stack->top;
	ft_printf("----- rnk is -----\n");
	while (temp)
	{
		next = temp->next;
		ft_printf("%d\n", temp->rnk);
		temp = next;
	}
}

void	ft_check_dup(t_stack *a, t_stack *b)
{
	t_node	*temp;
	t_node	*temp2;
	int		idx;
	int		idx2;

	temp = a->top;
	idx = -1;
	idx2 = 0;
	while (++idx < a->size)
	{
		idx2 = idx - 1;
		temp2 = temp;
		while (++idx2 < ((a->size) - 1) && temp2)
		{
			if (temp->num == temp2->next->num)
			{
				ft_putendl_fd("Error", 2);
				ft_free_stack(a);
				ft_free_stack(b);
				exit(1);
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void	ft_passing(t_stack *a)
{
	t_node	*temp;
	t_node	*cur;
	int		rnk;

	rnk = 0;
	cur = a->top;
	while (cur)
	{
		rnk = 1;
		temp = a->top;
		while (temp)
		{
			if (cur->num > temp->num)
				rnk += 1;
			temp = temp->next;
		}
		cur->rnk = rnk;
		cur = cur->next;
	}
}
