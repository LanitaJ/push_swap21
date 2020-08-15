/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:21:57 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/15 15:37:08 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_error(stacks_t *stacks)
{
	if (stacks->flag_c)
		ft_printf(RED"Error"RESET);
	else
		ft_printf("Error");
	exit(1);
}

void	print_stack(stacks_t *stacks)
{
	int	i;

	i = 0;
	stacks->flag_c ? ft_printf(CYN"Stack A: "RESET) : ft_printf("Stack A: ");
	while (i < stacks->count_a)
		stacks->flag_c ? ft_printf(CYN"%d "RESET, stacks->a[i++]) : ft_printf("%d ", stacks->a[i++]);
	ft_printf("\n");
	i = 0;
	stacks->flag_c ? ft_printf(MAG"Stack B: "RESET) : ft_printf("Stack B: ");
	while (i < stacks->count_b)
		stacks->flag_c ? ft_printf(MAG"%d "RESET, stacks->b[i++]) : ft_printf("%d ", stacks->b[i++]);
	ft_printf("\n");
}