/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:24:16 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 15:47:06 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*temp;

	if (a->size <= 1)
		return ;
	temp = a->top;
	a->top = a->top->next;
	a->top->prev = NULL;
	a->bottom->next = temp;
	temp->prev = a->bottom;
	a->bottom = temp;
	temp->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	t_node	*temp;

	if (b->size <= 1)
		return ;
	temp = b->top;
	b->top = b->top->next;
	b->top->prev = NULL;
	b->bottom->next = temp;
	temp->prev = b->bottom;
	b->bottom = temp;
	temp->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*temp_a;
	t_node	*temp_b;

	if (a->size <= 1 || b->size <= 1)
		return ;
	temp_a = a->top;
	a->top = a->top->next;
	a->top->prev = NULL;
	a->bottom->next = temp_a;
	temp_a->prev = a->bottom;
	a->bottom = temp_a;
	temp_a->next = NULL;
	temp_b = b->top;
	b->top = b->top->next;
	b->top->prev = NULL;
	b->bottom->next = temp_b;
	temp_b->prev = b->bottom;
	b->bottom = temp_b;
	temp_b->next = NULL;
	ft_printf("rr\n");
}
