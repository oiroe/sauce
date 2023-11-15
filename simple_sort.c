/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:39 by pboonpro          #+#    #+#             */
/*   Updated: 2023/11/14 22:26:39 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	bubble(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

void	selection(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] < arr[j])
				swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

void	insertion(int *arr, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	partion(int *arr, int start, int end)
{
	int	i;
	int	j;
	int	p;

	i = start - 1;
	p = arr[end];
	j = start;
	while (j <= end - 1)
	{
		if (arr[j] < p)
		{
			i++;
			swap(&arr[j], &arr[i]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

void	quick(int *arr, int start, int end)
{
	int	i;

	i = 0;
	if (start < end)
	{
		i = partion(arr, start, end);
		quick(arr, start, i - 1);
		quick(arr, i + 1, end);
	}
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1, n2;

	n1 = m - l + 1;
	n2 = r - m;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void	mergeSort(int arr[], int l, int r)
{
	int	m;

	m = 0;
	if (l < r)
	{
		m = (r + l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void	printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/*int	main(void)
{
	int	a[] = {5, 4, 3, 2, 1};

	//bubble(a, 5);
	//selection(a, 5);
	//insertion(a, 5);
	//quick(a, 0, 4);
	mergeSort(a, 0, 4);
	printArray(a, 5);
	return (0);
}*/
