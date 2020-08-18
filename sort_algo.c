/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:39:48 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/18 13:45:32 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		min_com(int *arr, int count)
{
	int	min;
	int	i;
	int	index;
	
	i = 0;
	index = 0;
	min = arr[0];
	while (i < count)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	sort(t_stacks *stacks)
{
	t_commands	com;
	int			arr[stacks->count_b];
	int			i;
	int			min_i;

	i = 0;
	while (i < stacks->count_b)
	{
		ft_bzero(&com, sizeof(t_commands));
		count_com(*stacks, &com, i);
		arr[i] = com.count;
		i++;
	}
	min_i = min_com(arr, stacks->count_b);
	count_com(*stacks, &com, min_i);
	do_com1(com, stacks);
}
