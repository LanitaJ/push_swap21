/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:54:47 by ljerk             #+#    #+#             */
/*   Updated: 2020/09/07 12:53:13 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int		check_double(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->count_a)
	{
		j = i + 1;
		while (j < stacks->count_a)
		{
			if (stacks->a[i] == stacks->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int		count_nums(char **av)
{
	int		i;
	int		j;
	int		n;
	char	**arr;

	n = 0;
	i = 0;
	while (av[i])
	{
		arr = ft_strsplit(av[i], ' ');
		j = 0;
		while (arr[j++])
			n++;
		i++;
		ft_freestrarr(arr);
	}
	return (n);
}

static int		*create_stack_a(int *ac, char **av, t_stacks *stacks)
{
	int		*stack_a;
	int		n;
	int		i;
	int		j;
	char	**arr;

	n = count_nums(av);
	if (!n)
		exit(1);
	*ac = n;
	stack_a = (int*)ft_memalloc(sizeof(int*) * n);
	if (stack_a == NULL)
		exit(1);
	n = 0;
	i = 0;
	while (av[i])
	{
		arr = ft_strsplit(av[i], ' ');
		j = 0;
		while (arr[j])
			stack_a[n++] = atoi_ps(arr[j++], stacks);
		i++;
		ft_freestrarr(arr);
	}
	return (stack_a);
}

void			create_stacks(t_stacks *stacks, int ac, char **av)
{
	stacks->a = create_stack_a(&ac, av, stacks);
	stacks->b = (int*)ft_memalloc(sizeof(int*) * ac);
	if (stacks->b == NULL)
		exit(1);
	stacks->count_a = ac;
	if (check_double(stacks))
		print_error(stacks);
}
