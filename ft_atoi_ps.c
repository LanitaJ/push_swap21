/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 07:09:41 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/16 07:40:58 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/push_swap.h"

int		atoi_ps(const char *str, t_stacks *stacks)
{
	size_t	i;
	int		sing;
	long	res;

	i = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sing = (str[i] == '-' ? -1 : 1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i++] - '0';
		if (res > (res * 10) || (res > 2147483647 && sing == 1)
				|| (res > 2147483648 && sing == -1))
			print_error(stacks);
	}
	if (str[i] || (i && (str[i - 1] == '-' || str[i - 1] == '+')))
		print_error(stacks);
	return (res * sing);
}
