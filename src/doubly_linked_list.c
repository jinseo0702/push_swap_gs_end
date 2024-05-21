/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:13:45 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 15:29:01 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_init_list(t_node *new)
{
	new->prev = NULL;
	new->next = NULL;
	new->num = 0;
	new->rnk = 0;
}

t_stack	*ft_creat_stack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	new->top = NULL;
	new->bottom = NULL;
	new->size = 0;
	return (new);
}

void	ft_insert_node(t_stack *stack, t_node *node)
{
	if (!stack->top)
	{
		stack->top = node;
		stack->bottom = node;
		stack->size++;
	}
	else
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->bottom = node;
		stack->size++;
	}
}

t_node	*ft_new_node(int num, t_stack *stack)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_stack(stack);
		exit(1);
	}
	ft_init_list(new);
	new->num = num;
	return (new);
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	temp = stack->top;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	temp = NULL;
	next = NULL;
	stack->top = NULL;
	stack->bottom = NULL;
	free(stack);
	stack = NULL;
}
