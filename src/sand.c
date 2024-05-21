/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:30:46 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 15:43:38 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sand_onestep(t_stack *a, t_stack *b, int cnt, int chunk)
{
	int	num;

	while (a->top != NULL)
	{
		num = a->top->rnk;
		if (num <= cnt)
		{
			pb(a, b);
			cnt++;
		}
		else if ((num > cnt) && (num <= chunk + cnt))
		{
			pb(a, b);
			rb(b);
			cnt++;
		}
		else if (num > cnt + chunk)
		{
			if (a->size / 2 >= cnt)
				rra(a);
			else
				ra(a);
		}
	}
}

void	ft_sand_twostep(t_stack *a, t_stack *b)
{
	t_node	*temp;
	t_node	*next;

	while (b->top != NULL)
	{
		temp = b->top;
		while (b->top->rnk != b->size && temp)
		{
			next = temp->next;
			if (quick_cnt(b, b->size))
				rrb(b);
			else
				rb(b);
			temp = next;
		}
		pa(a, b);
	}
}

int	ft_chunk(int size)
{
	return ((0.000000053 * (size * size)) + (0.03 * (size)) + 14.5);
}

int	quick_cnt(t_stack *stack, int num)
{
	t_node	*temp;
	t_node	*next;
	int		num2;

	if (!stack->top)
		return (-2);
	temp = stack->top;
	num2 = -1;
	while (temp->rnk != num && temp)
	{
		next = temp->next;
		temp = next;
		++num2;
	}
	if ((num2 + stack->size) % stack->size > \
			((stack->size - num2) % stack->size))
		return (1);
	return (0);
}
