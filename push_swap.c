/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:51:51 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/17 14:23:54 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int     main(int ac, char **av)
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
	if (stacks.flag_v)
		print_stack(&stacks);
	push_swap(stacks);
	free(stacks.a);
	free(stacks.b);
}

/*
p_s:
создание 2 стеков
	выделение памяти
	вычленение из av чисел
	запись в структуру
	проверка на дубликаты
	проверка что это числа инта
проверка отсортирован ли массив, пустой ли стек В
если нет, то алгоритм сортировки
	находим мин и макс
	
	
парсинг файла с командами
	в цикле:
		гнл считывает строку
		валидирование команды
		выполнение команды
		очистка памяти гнл
проверка выполнения алгоритма (отсортирован ли массив, пустой ли стек В)
очистка массивов

*/