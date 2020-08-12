/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:54:47 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/12 20:50:01 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int		check_double(stacks_t *stacks)
{
	int	i;
	int j;

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
		//ft_printf("%s\n", av[i]);
		arr = ft_strsplit(av[i], ' ');
		//ft_printf("***%s\n%s\n", arr[0], arr[1]);
		j = 0;
		while (arr[j++])
			n++;
		i++;
		ft_freestrarr(arr);
	}
	return (n);
}

static int		*create_stack_a(int *ac, char **av)
{
	int		*stack_a;
	int		n;
	int		i;
	int		j;
	char	**arr;
		
	n = count_nums(av);
	//ft_printf("n = %d\n", n);
	*ac = n;
	stack_a = (int*)ft_memalloc(sizeof(int*) * n);
	i = 0;
	n = 0;
	while (av[i])
	{
		arr = ft_strsplit(av[i], ' ');
		j = 0;
		while (arr[j])
			stack_a[n++] = ft_atoi(arr[j++]);
		i++;
		ft_freestrarr(arr);
	}
	return (stack_a);
}

void	print_error(stacks_t *stacks)
{
	if (stacks->flag_c)
		ft_printf(RED"Error"RESET);
	else
		ft_printf("Error");
	exit(1);
}

void	create_stacks(stacks_t *stacks, int ac, char **av)
{
	stacks->a = create_stack_a(&ac, av);
	stacks->b = (int*)ft_memalloc(sizeof(int*) * ac);
	stacks->count_a = ac;
	if (check_double(stacks))
		print_error(stacks);
}
