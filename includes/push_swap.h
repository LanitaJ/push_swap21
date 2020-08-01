/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 14:04:27 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/01 19:21:27 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"

/* # define CYN	"\x1B[36m"
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m" */

# define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

typedef struct	s_stacks
{
	int			*a;
	int			*b;
	int			count_a;
	int			count_b;
	int			min;
	int			max;
	int			flag_v;
	int			flag_c;
}				t_stacks;

typedef struct	s_commands
{
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	int			rr;
	int			rrr;
	int			count;
}				t_commands;

#endif
