/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:44:32 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/17 14:27:57 by ljerk            ###   ########.fr       */
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

static void	solver_for_three1(t_stacks *stacks)
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

void	push_swap(t_stacks stacks)
{
	if (check_sorted(stacks))
		return ;
	if (stacks.count_a == 3 || stacks.count_a == 1)
		solver_for_three1(&stacks);
	else if (stacks.count_a == 2 && stacks.a[0] > stacks.a[1])
		stacks.flag_c ? ft_printf(CYN"sa\n"RESET) : ft_printf("sa\n");
	/* else if (stacks.count_a > 3)
		ft_solver(stacks); */
}