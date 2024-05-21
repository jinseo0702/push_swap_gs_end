/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_re.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <jinseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:42 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 15:29:25 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi_re(t_stack *b, t_stack *a, char **split_argv, int idx_sp)
{
	long long	nb;
	const char	*nptr;

	nb = 0;
	nptr = split_argv[idx_sp];
	if ((*nptr == '+' || *nptr == '-') && *(nptr + 1) == '\0')
		ft_free_stack_split(a, b, split_argv, idx_sp);
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
	{
		nb = (*nptr - 48) + (nb * 10);
		nptr++;
	}
	if (*nptr != '\0' && !(*nptr >= '0' && *nptr <= '9'))
		ft_free_stack_split(a, b, split_argv, idx_sp);
	if (split_argv[idx_sp][0] == '-')
		nb *= -1;
	if (nb < -2147483648 || nb > 2147483647)
		ft_free_stack_split(a, b, split_argv, idx_sp);
	return ((int)nb);
}

void	ft_free_stack_split(t_stack *a, t_stack *b, char **split_argv, int idx)
{
	ft_free_stack(a);
	ft_free_stack(b);
	ft_strfree(split_argv, idx);
	ft_putendl_fd("Error", 2);
	exit(1);
}
