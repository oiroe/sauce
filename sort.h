/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:27:17 by pboonpro          #+#    #+#             */
/*   Updated: 2023/11/14 22:27:17 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include "libft/libft.h"
# include "color.h"

typedef struct s_arr
{
	int	*stack;
	int	size;
	int	top;
}			t_arr;

/*time.c*/
long		get_time(void);
long		now(long past);

/*simple_sort.c*/
void	bubble(int *arr, int size);
void	selection(int *arr, int size);
void	insertion(int *arr, int size);
void	quick(int *arr, int start, int end);
void	mergeSort(int arr[], int l, int r);


#endif
