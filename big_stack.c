/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:51:17 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/11 20:15:59 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_node **top_a, int len)
{
    int     *arr;
	int		i;
    t_node  *current;

    arr = malloc((len) * sizeof(int));
    if (arr == NULL)
        exit(EXIT_FAILURE);
    current = *top_a;
    i = -1;
    while (current != NULL)
    {
        arr[++i] = current->data;
        current = current->next;
    }
    merge_sort(&arr, len, 0);
    i = -1;
    while (++i < len)
    {
        current = *top_a;
        while (current != NULL)
        {
            if (arr[i] == current->data)
                current->index = i;
            current = current->next;
        }
    }
	// current = *top_a;
	// while (current != NULL)
	// {
	// 	printf("%d\n", current->data);
	// 	current = current->next;
	// }
	// printf("--------------------------\n");
	// current = *top_a;
	// while (current != NULL)
	// {
	// 	printf("%d\n", current->index);
	// 	current = current->next;
	// }
	// exit (0);
	free(arr);
}

void    sort_big_stack(t_node **top_a, t_node **top_b, int len)
{
	int		max_num;
	int		num_bits;
	int		i;
	int		j;
	
	get_index(top_a, len);
	max_num = len - 1;
	num_bits = 0;
	while ((max_num >> num_bits) != 0)
		num_bits++;
	i = -1;
	while (++i < num_bits)
	{
		j = -1;
		while (++j < len)
		{
			if ((((*top_a)->index >> i) & 1) == 0)
				push_to_stack(top_b, top_a, "pb\n");
			else
				rotate(top_a, "ra\n");
		}
		while (*top_b != NULL)
			push_to_stack(top_a, top_b, "pa\n");		
	}
	// while (*top_a != NULL)
	// {
	// 	printf("%d\n", (*top_a)->index);
	// 	*top_a = (*top_a)->next;
	// }
}