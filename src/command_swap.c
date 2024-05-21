/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:22:53 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 14:10:54 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *a)
{
	t_node	*temp;

	if (!a || !a->top)
		return ;
	temp = a->top;
	a->top = a->top->next;
	temp->prev = a->top;
	temp->next = a->top->next;
	a->top->next = temp;
	a->top->prev = NULL;
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	t_node	*temp;

	if (!b || !b->top)
		return ;
	temp = b->top;
	b->top = b->top->next;
	temp->prev = b->top;
	temp->next = b->top->next;
	b->top->next = temp;
	b->top->prev = NULL;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	t_node	*temp_a;
	t_node	*temp_b;

	if (!a || !a->top || !b || !b->top)
		return ;
	temp_a = a->top;
	a->top = a->top->next;
	temp_a->prev = a->top;
	temp_a->next = a->top->next;
	a->top->next = temp_a;
	a->top->prev = NULL;
	temp_b = b->top;
	b->top = b->top->next;
	temp_b->prev = b->top;
	temp_b->next = b->top->next;
	b->top->next = temp_b;
	b->top->prev = NULL;
	ft_printf("ss\n");
}
