/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:44:40 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/15 16:24:13 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void			ft_do_sa(stacks_t *stacks)
{
	ft_swap(&stacks->a[0], &stacks->a[1]);
}
void			ft_do_sb(stacks_t *stacks)
{
	ft_swap(&stacks->b[0], &stacks->b[1]);
}


void			ft_do_ra(stacks_t *stacks)
{
	int		tmp;
	int		i;

	tmp = stacks->a[0];
	i = 0;
	while (++i <= stacks->count_a)
		stacks->a[i - 1] = stacks->a[i];
	stacks->a[stacks->count_a - 1] = tmp;
}

void			ft_do_rb(stacks_t *stacks)
{
	int		tmp;
	int		i;

	tmp = stacks->b[0];
	i = 0;
	while (++i <= stacks->count_b)
		stacks->b[i - 1] = stacks->b[i];
	stacks->b[stacks->count_b - 1] = tmp;
}

void			ft_do_rra(stacks_t *stacks)
{
	int	tmp;
	int	i;
	
	tmp = stacks->a[stacks->count_a - 1];
	i = stacks->count_a - 1;
	while (i > 0)
		ft_swap(&stacks->a[i - 1], &stacks->a[i--]);
	stacks->a[0] = tmp;
}

void			ft_do_rrb(stacks_t *stacks)
{
	int	tmp;
	int	i;
	
	tmp = stacks->b[stacks->count_b - 1];
	i = stacks->count_b - 1;
	while (i > 0)
		ft_swap(&stacks->b[i - 1], &stacks->b[i--]);
	stacks->b[0] = tmp;
}


void			ft_do_pb(stacks_t *stacks)
{
	int	i;

	if (!stacks->count_b)
		return ;
	i = stacks->count_b;
	while (i > 0)
		ft_swap(&stacks->b[i - 1], &stacks->b[i--]);
	ft_swap(&stacks->a[0], &stacks->b[0]);
	stacks->count_b++;
	i = 0;
	while (i > 0)
		ft_swap(&stacks->a[i - 1], &stacks->a[i--]);
	stacks->count_a--;
}

void			ft_do_pa(stacks_t *stacks)
{
	int	i;

	if (!stacks->count_a)
		return ;
	i = stacks->count_a;
	while (i > 0)
		ft_swap(&stacks->a[i - 1], &stacks->a[i--]);
	ft_swap(&stacks->b[0], &stacks->a[0]);
	stacks->count_a++;
	i = 0;
	while (i > 0)
		ft_swap(&stacks->b[i - 1], &stacks->b[i--]);
	stacks->count_b--;
}