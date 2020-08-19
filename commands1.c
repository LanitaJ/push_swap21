/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:44:40 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/19 12:25:59 by ljerk            ###   ########.fr       */
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

void			ft_do_rra(t_stacks *stacks)
{
	int	tmp;
	int	i;
	
	tmp = stacks->a[stacks->count_a - 1];
	i = stacks->count_a + 1;
	while (--i > 0)
		stacks->a[i] = stacks->a[i - 1];
	stacks->a[0] = tmp;
}

void			ft_do_rrb(t_stacks *stacks)
{
	int	tmp;
	int	i;
	
	tmp = stacks->b[stacks->count_b - 1];
	i = stacks->count_b + 1;
	while (--i > 0)
		stacks->b[i] = stacks->b[i - 1];
	stacks->b[0] = tmp;
}


void			ft_do_pb(t_stacks *stacks)
{
	int	i;

	if (!stacks->count_a)
		return ;
	i = stacks->count_b + 1;
	while (--i > 0)
		stacks->b[i] = stacks->b[i - 1];
	ft_swap(&stacks->a[0], &stacks->b[0]);
	stacks->count_b++;
	i = 0;
	while (++i <= stacks->count_a)
		stacks->a[i - 1] = stacks->a[i];
	stacks->count_a--;
}

void			ft_do_pa(t_stacks *stacks)
{
	int	i;

	if (!stacks->count_b)
		return ;
	i = stacks->count_a + 1;
	while (--i > 0)
		stacks->a[i] = stacks->a[i - 1];
	ft_swap(&stacks->b[0], &stacks->a[0]);
	stacks->count_a++;
	i = 0;
	while (++i <= stacks->count_b)
		stacks->b[i - 1] = stacks->b[i];
	stacks->count_b--;
}