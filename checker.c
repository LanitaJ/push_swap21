/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:19:51 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/19 14:06:01 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int main(int ac, char **av)
{
	int	fd;
	t_stacks stacks;

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
	if (check(fd, &stacks))
		stacks.flag_c ? ft_printf(GRN"OK\n"RESET) : ft_printf("OK\n");
	else
		stacks.flag_c ? ft_printf(RED"KO\n"RESET) : ft_printf("KO\n");
	free(stacks.a);
	free(stacks.b);
}
