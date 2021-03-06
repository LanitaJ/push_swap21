/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:51:51 by ljerk             #+#    #+#             */
/*   Updated: 2020/09/07 12:22:31 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_solver(t_stacks stacks)
{
	push_to_b(&stacks);
	if (stacks.flag_v)
		print_stack(&stacks);
	solver_for_three1(&stacks);
	if (stacks.flag_v)
		print_stack(&stacks);
	while (stacks.count_b)
	{
		sort(&stacks);
		if (stacks.flag_v)
			print_stack(&stacks);
	}
	if (!check_sorted(stacks))
		move(&stacks);
	if (stacks.flag_v)
		print_stack(&stacks);
}

void	push_swap(t_stacks stacks)
{
	if (check_sorted(stacks))
		return ;
	if (stacks.count_a == 3 || stacks.count_a == 1)
		solver_for_three1(&stacks);
	else if (stacks.count_a == 2 && stacks.a[0] > stacks.a[1])
		stacks.flag_c ? ft_printf(CYN"sa\n"RESET) : ft_printf("sa\n");
	else if (stacks.count_a > 3)
		ft_solver(stacks);
}

int		main(int ac, char **av)
{
	int			fd;
	t_stacks	stacks;

	av++;
	ft_bzero(&stacks, sizeof(t_stacks));
	find_flags(&av, &stacks);
	if (ac == 1)
		return (0);
	fd = open(av[0], O_RDONLY);
	if (fd == -1)
		fd = 0;
	else
		av++;
	create_stacks(&stacks, ac - 1, av);
	if (stacks.flag_v)
		print_stack(&stacks);
	push_swap(stacks);
	free(stacks.a);
	free(stacks.b);
}
