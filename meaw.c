/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meaw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:51 by pboonpro          #+#    #+#             */
/*   Updated: 2023/11/14 22:26:51 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	free_stack(t_arr *a)
{
	if (a != NULL)
	{
		free(a->stack);
		free(a);
		a = NULL;
	}
}

void	push(t_arr *arr, int num)
{
	if (arr->top >= arr->size - 1 || !arr)
		return ;
	arr->top++;
	arr->stack[arr->top] = num;
}

int	pop(t_arr *arr)
{
	int	num;

	if (arr->top <= -1 || !arr)
		return (0);
	num = arr->stack[arr->top];
	arr->top--;
	return (num);
}

t_arr	*stack_create(unsigned int n)
{
	t_arr	*arr;

	arr = malloc(sizeof(t_arr) * 1);
	if (!arr)
		return (NULL);
	arr->stack = malloc(sizeof(int) * n);
	if (!arr->stack)
	{
		free(arr);
		return (NULL);
	}
	arr->size = n;
	arr->top = -1;
	return (arr);
}

int	open_file(char **av, int *len)
{
	int		fd;
	char	*buff;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Can't open file ;-;\n");
		return (-1);
	}
	buff = get_next_line(fd);
	*len = ft_atoi(buff);
	return (fd);
}

void	read_and_put(t_arr *a, int fd)
{
	char	*buff;

	buff = get_next_line(fd);
	while (buff)
	{
		push(a, ft_atoi(buff));
		free(buff);
		buff = get_next_line(fd);
	}
}

long	do_sort(t_arr *a, int mode)
{
	long	start;

	start = get_time();
	if (mode == 1)
		bubble(a->stack, a->size);
	else if (mode == 2)
		insertion(a->stack, a->size);
	else if (mode == 3)
		selection(a->stack, a->size);
	else if (mode == 4)
		mergeSort(a->stack, 0, a->size - 1);
	else if (mode == 5)
		quick(a->stack, 0, a->size - 1);
	return (now(start));
}

int	main(int ac, char **av)
{
	int		fd;
	int		len;
	t_arr	*stack;

	fd = 0;
	len = 0;
	if (ac == 3)
	{
		if (ft_atoi(av[2]) < 1 || ft_atoi(av[2]) > 5)
			return (0);
		fd = open_file(av, &len);
		stack = stack_create(len);
		read_and_put(stack , fd);
		close(fd);
		printf("sort time : %lu microsecond\n", do_sort(stack, ft_atoi(av[2])));
		free_stack(stack);
	}
	else
		printf("Invalid paramiter\n");
	return (0);
}
