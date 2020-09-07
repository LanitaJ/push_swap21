/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_com.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:09:57 by ljerk             #+#    #+#             */
/*   Updated: 2020/09/07 12:11:43 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	get_ra_rra(t_stacks stacks, t_commands *com, int i)
{
	int	num;
	int	b;

	b = stacks.b[i];
	num = 0;
	while (1)
	{
		if (!num && stacks.a[num] != stacks.min
			&& stacks.a[0] > b && stacks.a[stacks.count_a - 1] < b)
			break ;
		else if (num && stacks.a[num] != stacks.min
			&& stacks.a[num] > b && stacks.a[num - 1] < b)
			break ;
		num++;
	}
	com->ra = num;
	com->rra = stacks.count_a - num;
}

static void	get_rb_rrb(t_stacks stacks, t_commands *com, int i)
{
	com->rb = i;
	com->rrb = stacks.count_b - i;
}

static void	get_rr_rrr(t_commands *com)
{
	com->rr = com->ra > com->rb ? com->rb : com->ra;
	com->ra -= com->rr;
	com->rb -= com->rr;
	com->rrr = com->rra > com->rrb ? com->rrb : com->rra;
	com->rra -= com->rrr;
	com->rrb -= com->rrr;
}

static void	optimum_com(t_commands *com)
{
	if (com->ra + com->rb + com->rr < com->rra + com->rrb + com->rrr)
	{
		com->count = com->ra + com->rb + com->rr;
		com->rrr = 0;
		com->rrb = 0;
		com->rra = 0;
	}
	else
	{
		com->count = com->rra + com->rrb + com->rrr;
		com->rr = 0;
		com->rb = 0;
		com->ra = 0;
	}
}

void		count_com(t_stacks stacks, t_commands *com, int i)
{
	get_ra_rra(stacks, com, i);
	get_rb_rrb(stacks, com, i);
	get_rr_rrr(com);
	optimum_com(com);
}
