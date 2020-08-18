/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 14:04:27 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/18 13:48:12 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"
# include <fcntl.h>

# define CYN	"\x1B[36m"
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"

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


void			ft_do_sa(t_stacks *stacks);
void			ft_do_sb(t_stacks *stacks);
void			ft_do_rra(t_stacks *stacks);
void			ft_do_ra(t_stacks *stacks);
void			ft_do_rrb(t_stacks *stacks);
void			ft_do_rb(t_stacks *stacks);
void			ft_do_pb(t_stacks *stacks);
void			ft_do_pa(t_stacks *stacks);

void			print_error(t_stacks *stacks);
void			create_stacks(t_stacks *stacks, int ac, char **av);
void			print_stack(t_stacks *stacks);
void			find_flags(char ***av, t_stacks *stacks);
int				check(int fd, t_stacks *stacks);
void			push_swap(t_stacks stacks);
int				atoi_ps(const char *str, t_stacks *stacks);
int				check_sorted(t_stacks stacks);
void			ft_solver(t_stacks stacks);
void			solver_for_three1(t_stacks *stacks);
void			sort(t_stacks *stacks);
void			count_com(t_stacks stacks, t_commands *com, int i);
void			do_com1(t_commands com, t_stacks *stacks);
#endif
