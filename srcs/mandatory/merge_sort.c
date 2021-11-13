/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:47:25 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/13 18:36:21 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	merge(int *arr, int *right, int *left, t_merge merge_len)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < merge_len.len_l && j < merge_len.len_r)
	{	
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while (i < merge_len.len_l)
		arr[k++] = left[i++];
	while (j < merge_len.len_r)
		arr[k++] = right[j++];
}

void	merge_sort(int **arr, int len, int mid_len)
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
	i = -1;
	while (++i < mid_len)
		left[i] = (*arr)[i];
	i = mid_len - 1;
	while (++i < len)
		right[i - mid_len] = (*arr)[i];
	merge_sort(&left, mid_len, mid_len);
	merge_sort(&right, len - mid_len, mid_len);
	merge(*arr, right, left, (t_merge){mid_len, len - mid_len});
	free(right);
	free(left);
}
