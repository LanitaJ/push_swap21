/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:19:51 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/15 16:21:24 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	find_flags(char ***av, stacks_t *stacks)
{
	if (ft_strequ(**av, "-v"))
	{
		stacks->flag_v = 1;
		(*av)++;
		find_flags(av, stacks);
	}
	if (ft_strequ(**av, "-c"))
	{
		stacks->flag_c = 1;
		(*av)++;
		find_flags(av, stacks);
	}
}



int main(int ac, char **av)
{
	int	fd;
	stacks_t stacks;

	av++;
	ft_bzero(&stacks, sizeof(stacks_t));
	find_flags(&av, &stacks);
	if (ac == 1)
		return (0);
	fd = open(av[0], O_RDONLY);
	//ft_printf("%d", fd);
	if (fd == -1)
		fd = 0;
	else
		av++;
	create_stacks(&stacks, ac - 1, av);
	print_stack(&stacks);
	
	/* if (check(fd, &stacks))
		stacks.flag_c ? ft_printf(GRN"OK\n"RESET) : ft_printf("OK\n");
	else
		stacks.flag_c ? ft_printf(RED"KO\n"RESET) : ft_printf("KO\n"); */
	free(stacks.a);
	free(stacks.b);
}

/*
чекер:
создание 2 стеков
	выделение памяти
	вычленение из av чисел
	запись в структуру
	проверка на дубликаты
	проверка что это числа инта
парсинг файла с командами
	в цикле:
		гнл считывает строку
		валидирование команды
		выполнение команды
		очистка памяти гнл
проверка выполнения алгоритма (отсортирован ли массив, пустой ли стек В)
очистка массивов




вывод стеков на экран(флаг -v)
	вывод длины стека, содержимое

создание обработчика ошибок (флаг - e)
	ошибка ввода
	ошибка файла
	ошибка выделения памяти

	

*/