/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:08 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 15:46:47 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a->top || !stack_a)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	if (!stack_b->top)
	{
		stack_b->top = temp;
		stack_b->bottom = temp;
		temp->next = NULL;
		if (stack_a->top)
			stack_a->top->prev = NULL;
		stack_b->size++;
		stack_a->size--;
	}
	else
	{
		stack_b->top->prev = temp;
		temp->next = stack_b->top;
		stack_b->top = temp;
		if (stack_a->top)
			stack_a->top->prev = NULL;
		stack_b->size++;
		stack_a->size--;
	}
	ft_printf("pb\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b->top || !stack_b)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	if (!stack_a->top)
	{
		stack_a->top = temp;
		stack_a->bottom = temp;
		temp->next = NULL;
		if (stack_b->top)
			stack_b->top->prev = NULL;
		stack_a->size++;
		stack_b->size--;
	}
	else
	{
		stack_a->top->prev = temp;
		temp->next = stack_a->top;
		stack_a->top = temp;
		if (stack_b->top)
			stack_b->top->prev = NULL;
		stack_a->size++;
		stack_b->size--;
	}
	ft_printf("pa\n");
}
