/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:44:32 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/19 12:39:28 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	solver_for_three2(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a > c && b > c)//231
	{
		stacks->flag_c ? ft_printf(CYN"rra\n"RESET) : ft_printf("rra\n");
		ft_do_rra(stacks);
	}
	if (a > b && a < c && b < c)//213
	{
		stacks->flag_c ? ft_printf(CYN"sa\n"RESET) : ft_printf("sa\n");
		ft_do_sa(stacks);
	}
	if (b > a && b > c && c > a)//132
	{
		stacks->flag_c ? ft_printf(CYN"sa\nra\n"RESET)
			: ft_printf("sa\nra\n");
		ft_do_sa(stacks);
		ft_do_ra(stacks);
	}
}

void	solver_for_three1(t_stacks *stacks)
{
	int a;
	int b;
	int c;

	a = stacks->a[0];
	b = stacks->a[1];
	c = stacks->a[2];
	if (a > b && a > c && b > c)//321
	{
		stacks->flag_c ? ft_printf(CYN"sa\nrra\n"RESET) 
						: ft_printf("sa\nrra\n");
		ft_do_sa(stacks);
		ft_do_rra(stacks);
	}
	if (a > b && a > c && b < c)//312
	{
		stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
		ft_do_ra(stacks);
	}
	solver_for_three2(stacks, a, b, c);
}

static void	split_two(t_stacks *stacks)
{
	long	m;
	int		lim;
	int		i;

	m = (stacks->max + stacks->min) / 2;
	lim = stacks->count_a;
	i = 0;
	while (lim > 50 && i++ < lim)
	{
		if (stacks->a[0] == stacks->max || stacks->a[0] == stacks->max ||
			 stacks->a[0] < m)
		{
			stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
			ft_do_ra(stacks);
		}
		else
		{
			stacks->flag_c ? ft_printf(CYN"pb\n"RESET) : ft_printf("pb\n");
			ft_do_pb(stacks);
		}
	}
}

void	push_to_b(t_stacks *stacks)
{
	int	i;

	i = -1;
	stacks->min = stacks->a[0];
	stacks->max = stacks->a[0];
	while (++i < stacks->count_a)
	{
		if (stacks->a[i] > stacks->max)
			stacks->max = stacks->a[i];
		if (stacks->a[i] < stacks->min)
			stacks->min = stacks->a[i];
	}
	split_two(stacks);
	while (stacks->count_a > 3)
	{
		if (stacks->a[0] == stacks->max || stacks->a[0] == stacks->min)
		{
			stacks->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
			ft_do_ra(stacks);
		}
		else
		{
			stacks->flag_c ? ft_printf(CYN"pb\n"RESET) : ft_printf("pb\n");
			ft_do_pb(stacks);
		}
	}
}


