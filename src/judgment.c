/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judgment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:47:30 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 15:30:16 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_judge(t_stack *stacka, t_stack *stackb, char **argv, int argc)
{
	if (argc >= 2)
		ft_argc_input(stacka, stackb, argv);
	else
	{
		ft_putendl_fd("Error", 2);
		ft_free_stack(stacka);
		ft_free_stack(stackb);
		exit(1);
	}
}

void	ft_argc_input(t_stack *a, t_stack *b, char **argv)
{
	int			idx;
	int			spi;
	static char	**sp_av;

	idx = 1;
	spi = 0;
	while (argv[idx] != NULL)
	{
		if (ft_strncmp(argv[idx], "", 1) == 0)
			ft_free_all(a, b);
		sp_av = ft_split(argv[idx], ' ');
		spi = -1;
		while (sp_av[++spi])
			ft_insert_node(a, ft_new_node(ft_atoi_re(b, a, sp_av, spi), a));
		ft_strfree(sp_av, spi);
		idx++;
	}
	ft_check_dup(a, b);
	ft_passing(a);
}

void	ft_strfree(char **split_argv, int idx)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (size <= idx)
	{
		free(split_argv[i]);
		i++;
		size++;
	}
	free(split_argv);
	split_argv = NULL;
}

void	ft_free_all(t_stack *a, t_stack *b)
{
	ft_free_stack(a);
	ft_free_stack(b);
	ft_putendl_fd("Error", 2);
	exit(1);
}
