/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:47:25 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/12 20:47:57 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	merge(int *arr, int *right, int *left, int lenR, int lenL)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < lenL && j < lenR)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i = i + 1;
		}
		else
		{
			arr[k] = right[j];
			j = j + 1;
		}
		k = k + 1;
	}
	while (i < lenL)
	{
		arr[k] = left[i];
		i = i + 1;
		k = k + 1;
	}
	while (j < lenR)
	{
		arr[k] = right[j];
		j = j + 1;
		k = k + 1;
	}
}

void	merge_sort(int **arr, int len , int mid_len)
{
	int		*right;
	int		*left;
	int		i;

	if (len < 2)
		return ;
	mid_len = len / 2;
	left = malloc(mid_len * sizeof(int));
	right = malloc((len - mid_len) * sizeof(int));
	if (right == NULL || left == NULL)
		exit (EXIT_FAILURE);
	i  = -1;
	while (++i < mid_len)
		left[i] = (*arr)[i];
	i = mid_len - 1;
	while (++i < len)
		right[i - mid_len] = (*arr)[i];
	merge_sort(&left, mid_len, mid_len);
	merge_sort(&right, len - mid_len, mid_len);
	merge(*arr, right, left, len - mid_len, mid_len);
	free(right);
	free(left);
}