/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:29:02 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/17 12:54:58 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int				check_sorted(t_stacks stacks)
{
	int	i;

	i = 1;
	if (stacks.count_b)
		return (0);
	while (i < stacks.count_a)
	{
		if (stacks.a[i] < stacks.a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

static void		next_commands(t_stacks *stacks, char *line)
{
	if (ft_strequ(line, "ss"))
	{
		ft_do_sa(stacks);
		ft_do_sb(stacks);
	}
	else if (ft_strequ(line, "rr"))
	{
		ft_do_ra(stacks);
		ft_do_rb(stacks);
	}
	else if (ft_strequ(line, "rrr"))
	{
		ft_do_rra(stacks);
		ft_do_rrb(stacks);
	}
	else
		print_error(stacks);
}

static void    make_commands(t_stacks *stacks, char *line)
{
	if (ft_strequ(line, "sa"))
		ft_do_sa(stacks);
	else if (ft_strequ(line, "sb"))
		ft_do_sb(stacks);
	else if (ft_strequ(line, "ra"))
		ft_do_ra(stacks);
	else if (ft_strequ(line, "rb"))
		ft_do_rb(stacks);
	else if (ft_strequ(line, "rra"))
		ft_do_rra(stacks);
	else if (ft_strequ(line, "rrb"))
		ft_do_rrb(stacks);	
	else if (ft_strequ(line, "pb"))
		ft_do_pb(stacks);
	else if (ft_strequ(line, "pa"))
		ft_do_pa(stacks);
	else
		next_commands(stacks, line);
}

int		check(int fd, t_stacks *stacks)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (stacks->flag_v)
			stacks->flag_c ? ft_printf(YEL"Operation %s\n"RESET, line)
			: ft_printf("Operation %s\n", line);
		make_commands(stacks, line);
		if (stacks->flag_v)
			print_stack(stacks);
		free(line);
	}
	if (check_sorted(*stacks))
		return (1);
	return (0);
}