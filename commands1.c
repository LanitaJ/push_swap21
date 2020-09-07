/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:44:40 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/19 16:13:37 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void			ft_do_sa(t_stacks *stacks)
{
	ft_swap(&stacks->a[0], &stacks->a[1]);
}

void			ft_do_sb(t_stacks *stacks)
{
	ft_swap(&stacks->b[0], &stacks->b[1]);
}

void			ft_do_ra(t_stacks *stacks)
{
	int		tmp;
	int		i;

	tmp = stacks->a[0];
	i = 0;
	while (++i <= stacks->count_a)
		stacks->a[i - 1] = stacks->a[i];
	stacks->a[stacks->count_a - 1] = tmp;
}

void			ft_do_rb(t_stacks *stacks)
{
	int		tmp;
	int		i;

	tmp = stacks->b[0];
	i = 0;
	while (++i <= stacks->count_b)
		stacks->b[i - 1] = stacks->b[i];
	stacks->b[stacks->count_b - 1] = tmp;
}
