/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:09:58 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 15:39:28 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "../libft/libft.h"
#include "../ft_printf/libftprintf.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
    int num;
    int rnk;
    struct s_node   *prev;
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    struct s_node *top;
    struct s_node *bottom;
    int size;
} t_stack;

// add + pcmver.double linked list
void    ft_init_list(t_node *new);
t_stack *ft_creat_stack(void);
void ft_insert_node(t_stack *stack, t_node *node);
t_node *ft_new_node(int num, t_stack *stack);
void    ft_free_stack(t_stack *stack);
//in input_argv
void ft_print_stack(t_stack *stack);
void ft_print_stack_rnk(t_stack *stack);
void ft_check_dup(t_stack *a, t_stack *b);
void ft_passing(t_stack *a);
//ver.2 judgment
void ft_judge(t_stack *stacka, t_stack *stackb, char **argv, int argc);
void ft_strfree(char **split_argv, int idx);
void ft_argc_input(t_stack *a, t_stack *b, char **argv);
void ft_free_all(t_stack *a, t_stack *b);
//command_push.c
void pb(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
//command_swap.c
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
//command_reverse.c
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
//command_double_reverse.c
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
//ft_atoi_re.c
int	ft_atoi_re(t_stack *b, t_stack *a, char **split_argv, int idx_sp);
void ft_free_stack_split(t_stack *a, t_stack *b, char **split_argv, int idx);
//quick_sort.c
void quick_swap_first(t_stack *a, t_stack *b, int min, int max);
void quick_swap_no(t_stack *a, t_stack *b, int min, int max);
int quick_cnt(t_stack *stack, int num);
//sand.c
void	ft_sand_onestep(t_stack *a, t_stack *b, int cnt, int chunk);
void	ft_sand_twostep(t_stack *a, t_stack *b);
int	ft_chunk(int size);
//check.c
void ft_is_sort(t_stack *a, t_stack *b);
#endif
